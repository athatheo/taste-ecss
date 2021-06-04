#include <msp430.h>

#include <stdint.h>
#include <string.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "transport.h"

#include "drivers_config.h"

#include "msp430_eusci_a_serial_minimal.h"

#define RING_BUFFER_SIZE ((MSP430_BUFFER_SIZE + sizeof(uint32_t) + sizeof(uint32_t)) * 2)

typedef struct
{
    volatile int m_head;
    volatile int m_tail;
    volatile uint8_t m_data[RING_BUFFER_SIZE];
} ring_buffer;

static void ring_buffer_init(ring_buffer* buf)
{
    buf->m_head = 0;
    buf->m_tail = 0;
}

static int ring_buffer_empty(ring_buffer* buf)
{
    return buf->m_head == buf->m_tail;
}

static void ring_buffer_push(ring_buffer* buf, uint8_t data)
{
    buf->m_data[buf->m_head] = data;
    ++buf->m_head;
    if(buf->m_head == RING_BUFFER_SIZE)
    {
        buf->m_head = 0;
    }
}

static uint8_t ring_buffer_get(ring_buffer* buf)
{
    if(ring_buffer_empty(buf))
    {
        return '\0';
    }
    else
    {
        uint8_t result = buf->m_data[buf->m_tail];
        ++buf->m_tail;
        if(buf->m_tail == RING_BUFFER_SIZE)
        {
            buf->m_tail = 0;
        }
        return result;
    }
}

enum UART_PARITY
{
    PARITY_ENABLED,
    PARITY_DISABLED
};

enum UART_PARITY_MODE
{
    PARITY_ODD,
    PARITY_EVEN
};

static void uart_setup_parity(enum UART_PARITY parity, enum UART_PARITY_MODE mode)
{
    // parity
    if(parity == PARITY_ENABLED)
    {
        UCA0CTLW0 |= UCPEN;
        if(mode == PARITY_EVEN)
        {
            UCA0CTLW0 |= UCPAR;
        }
        else
        {
            UCA0CTLW0 &= ~UCPAR;
        }
    }
    else
    {
        UCA0CTLW0 &= ~UCPEN;
    }
}

enum UART_BYTE_ORDER
{
    LSB,
    MSB
};

static void uart_setup_byte_order(enum UART_BYTE_ORDER byte_order)
{
    if(byte_order == MSB)
    {
        UCA0CTLW0 |= UCMSB;
    }
    else
    {
        UCA0CTLW0 &= ~UCMSB;
    }
}

enum UART_CHAR_BITS
{
    CHAR_8BIT,
    CHAR_7BIT
};

static void uart_setup_character_bits(enum UART_CHAR_BITS char_bits)
{
    if(char_bits == CHAR_7BIT)
    {
        UCA0CTLW0 |= UC7BIT;
    }
    else
    {
        UCA0CTLW0 &= ~UC7BIT;
    }
}

enum UART_STOP_BITS
{
    ONE,
    TWO
};

static void uart_setup_stop_bits(enum UART_STOP_BITS stop_bits)
{
    if(stop_bits == ONE)
    {
        UCA0CTLW0 &= ~UCSPB;
    }
    else
    {
        UCA0CTLW0 |= UCSPB;
    }
}

enum UART_BAUDRATE
{
    BAUDRATE_9600,
    BAUDRATE_19200,
    BAUDRATE_38400,
    BAUDRATE_57600,
    BAUDRATE_115200
};

static void uart_setup_baudrate(enum UART_BAUDRATE baudrate)
{
    // use SMCLK as BRCLK
    UCA0CTLW0 = UCSSEL0 | UCSSEL1;

    switch(baudrate)
    {
    case BAUDRATE_9600:
        UCA0BRW = 52;
        UCA0MCTLW_L |= UCOS16 | UCBRF_1;
        UCA0MCTLW_H = 0x49;
        break;

    case BAUDRATE_19200:
        UCA0BRW = 26;
        UCA0MCTLW_L |= UCOS16 | UCBRF_0;
        UCA0MCTLW_H = 0xB6;
        break;

    case BAUDRATE_38400:
        UCA0BRW = 13;
        UCA0MCTLW_L |= UCOS16 | UCBRF_0;
        UCA0MCTLW_H = 0x84;
        break;

    case BAUDRATE_57600:
        UCA0BRW = 8;
        UCA0MCTLW = UCOS16 | UCBRF_10 | 0xF700;
        break;

    case BAUDRATE_115200:
        UCA0BRW = 4;
        UCA0MCTLW = UCOS16 | UCBRF_5 | 0x5500;
        break;

    }
}

static ring_buffer stdin_buffer;
static ring_buffer stdout_buffer;
static SemaphoreHandle_t semaphore;
static StaticSemaphore_t semaphore_buffer;

static void uart_putc(uint8_t c)
{
    ring_buffer_push(&stdout_buffer, c);
    /* enable interrupt to transmit */
    UCA0IE |= UCTXIE;

    __asm__ volatile("nop");
    __asm__ volatile("nop");
}

static uint8_t uart_getc(void)
{
    uint8_t result;
    int run = 1;
    while(run)
    {
        if(ring_buffer_empty(&stdin_buffer))
        {
            xSemaphoreTake(semaphore, portMAX_DELAY);
        }
        else
        {
            result = ring_buffer_get(&stdin_buffer);
            run = 0;
        }
    }
    return result;
}

static void uart_transmit_character()
{
    portENTER_CRITICAL();
    if(ring_buffer_empty(&stdout_buffer))
    {
        /* disable interrupts */
        UCA0IE &= ~UCTXIE;
    }
    else
    {
        uint8_t c = ring_buffer_get(&stdout_buffer);
        UCA0TXBUF = c;
    }
    portEXIT_CRITICAL();
}

static void uart_receive_character(BaseType_t* parameter)
{
    portENTER_CRITICAL();
    uint8_t result = UCA0RXBUF;

    ring_buffer_push(&stdin_buffer, result);
    if(*parameter == pdFALSE)
    {
        xSemaphoreGiveFromISR(semaphore, parameter);
    }
    portEXIT_CRITICAL();
}

/*
 * interupt handler for receiving/transmiting
 */
__attribute__((interrupt(USCI_A0_VECTOR)))
void uart_a0_interrupt_handler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    /* receive characters */
    while((UCA0IFG & UCRXIFG) != 0)
    {
        uart_receive_character(&xHigherPriorityTaskWoken);
    }

    if((UCA0IFG & UCTXIFG) != 0)
    {
        uart_transmit_character();
    }

    __bic_SR_register_on_exit(SCG1 + SCG0 + OSCOFF + CPUOFF);

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

#define PACKET_START_BYTE ((uint8_t)'\x02')
#define PACKET_STOP_BYTE ((uint8_t)'\x03')
#define PACKET_ESCAPE_BYTE ((uint8_t)'\x1B')

enum PACKET_STATE
{
    WAITING_FOR_START_BYTE,
    RECEIVING_MESSAGE,
    ESCAPE_STARTED
};

void process_packet(uint8_t* data, int length)
{
    if(length > 4)
    {
        struct Message msg;

        memcpy(&msg.m_port, data, sizeof(uint32_t));
        memcpy(msg.m_data, data + sizeof(uint32_t), length - sizeof(uint32_t));
        msg.m_length = length - sizeof(uint32_t);

        process_incomming_message(&msg);
    }
    else
    {
        // the packet does not contain valid Message
    }
}

void msp430_eusci_a_serial_minimal_poller(void* param)
{
    uint8_t buffer[MSP430_BUFFER_SIZE + sizeof(uint32_t) + sizeof(uint32_t)];
    int counter = 0;
    enum PACKET_STATE state = WAITING_FOR_START_BYTE;

    while(1)
    {
        uint8_t c = uart_getc();

        switch(state)
        {
        case WAITING_FOR_START_BYTE:
            if(c == PACKET_START_BYTE)
            {
                counter = 0;
                state = RECEIVING_MESSAGE;
            }
            break;

        case RECEIVING_MESSAGE:
            if(c == PACKET_START_BYTE)
            {
                counter = 0;
                state = RECEIVING_MESSAGE;
            }
            else if(c == PACKET_STOP_BYTE)
            {
                process_packet(buffer, counter);
                state = WAITING_FOR_START_BYTE;
            }
            else if(c == PACKET_ESCAPE_BYTE)
            {
                state = ESCAPE_STARTED;
            }
            else
            {
                buffer[counter] = c;
                ++counter;
            }
            break;

        case ESCAPE_STARTED:
            buffer[counter] = c;
            ++counter;
            state = RECEIVING_MESSAGE;
            break;

        };
    }
}

static SemaphoreHandle_t sender_semaphore = {0};
static StaticSemaphore_t sender_semaphore_buffer = {0};

void msp430_eusci_a_serial_minimal_sender(uint8_t* data, uint32_t length, uint32_t port)
{
    xSemaphoreTake(sender_semaphore, portMAX_DELAY);

    uart_putc(PACKET_START_BYTE);

    uint32_t iter;

    for(iter = 0; iter < 4; ++iter)
    {
        uint8_t packet_byte = ((uint8_t*)(&port))[iter];

        if(packet_byte == PACKET_START_BYTE || packet_byte == PACKET_STOP_BYTE || packet_byte == PACKET_ESCAPE_BYTE)
        {
            uart_putc(PACKET_ESCAPE_BYTE);
        }

        uart_putc(packet_byte);
    }

    for(iter = 0; iter < length; ++iter)
    {
        uint8_t packet_byte = data[iter];

        if(packet_byte == PACKET_START_BYTE || packet_byte == PACKET_STOP_BYTE || packet_byte == PACKET_ESCAPE_BYTE)
        {
            uart_putc(PACKET_ESCAPE_BYTE);
        }

        uart_putc(packet_byte);
    }

    uart_putc(PACKET_STOP_BYTE);

    xSemaphoreGive(sender_semaphore);
}

__attribute__ ((persistent)) StackType_t prv_msp430_eusci_a_serial_minimal_poller_stack[configMINIMAL_STACK_SIZE] = {0};
__attribute__ ((persistent)) StaticTask_t prv_msp430_eusci_a_serial_minimal_poller_tcb = {0};

/*
 * initialization function
 */
void msp430_eusci_a_serial_minimal_init(void)
{
    ring_buffer_init(&stdin_buffer);
    ring_buffer_init(&stdout_buffer);

    P4DIR |= 0x40;   // configure P4.6 as output :: LED B

    semaphore = xSemaphoreCreateBinaryStatic(&semaphore_buffer);
    sender_semaphore = xSemaphoreCreateMutexStatic(&sender_semaphore_buffer);

    P2SEL1 |= BIT0 | BIT1;                    // USCI_A0 UART operation
    P2SEL0 &= ~(BIT0 | BIT1);

    // clear register
    UCA0CTLW0 = 0;

    // reset
    UCA0CTLW0 |= UCSWRST;

    // enable async mode (UART)
    UCA0CTLW0 &= ~UCSYNC;

    //pohidrv_msp430_node_msp430_eusci_a_serial_minimal

    if(pohidrv_node1_msp430_eusci_a_serial_minimal.exist.use_paritybit)
    {
        if(pohidrv_node1_msp430_eusci_a_serial_minimal.exist.parity && pohidrv_node1_msp430_eusci_a_serial_minimal.use_paritybit)
        {
            if(pohidrv_node1_msp430_eusci_a_serial_minimal.parity == Parity_T_even)
            {
                uart_setup_parity(PARITY_ENABLED, PARITY_EVEN);
            }
            else
            {
                uart_setup_parity(PARITY_ENABLED, PARITY_ODD);
            }
        }
        else
        {
            // disable parity
            uart_setup_parity(PARITY_DISABLED, PARITY_EVEN);
        }
    }
    else
    {
        // disable parity
        uart_setup_parity(PARITY_DISABLED, PARITY_EVEN);
    }

    uart_setup_byte_order(LSB);

    if(pohidrv_node1_msp430_eusci_a_serial_minimal.exist.bits)
    {
        switch(pohidrv_node1_msp430_eusci_a_serial_minimal.bits)
        {
        case 7:
            uart_setup_character_bits(CHAR_7BIT);
            break;
        case 8:
            uart_setup_character_bits(CHAR_8BIT);
            break;
        default:
            uart_setup_character_bits(CHAR_8BIT);
        }
    }
    else
    {
        uart_setup_character_bits(CHAR_8BIT);
    }

    if(pohidrv_node1_msp430_eusci_a_serial_minimal.exist.speed)
    {
        switch(pohidrv_node1_msp430_eusci_a_serial_minimal.speed)
        {
        case Baudrate_T_b9600:
            uart_setup_baudrate(BAUDRATE_9600);
            break;
        case Baudrate_T_b19200:
            uart_setup_baudrate(BAUDRATE_19200);
            break;
        case Baudrate_T_b38400:
            uart_setup_baudrate(BAUDRATE_38400);
            break;
        case Baudrate_T_b57600:
            uart_setup_baudrate(BAUDRATE_57600);
            break;
        case Baudrate_T_b115200:
            uart_setup_baudrate(BAUDRATE_115200);
            break;
        default:
            uart_setup_baudrate(BAUDRATE_9600);
        }
    }
    else
    {
        uart_setup_baudrate(BAUDRATE_9600);
    }

    uart_setup_stop_bits(ONE);

    // enable receive interrupts
    UCA0IE |= UCRXIE;

    // start uart
    UCA0CTLW0 &= ~UCSWRST;

    register_remote_transport_func(&msp430_eusci_a_serial_minimal_sender);

    xTaskCreateStatic(&msp430_eusci_a_serial_minimal_poller,
                "serial_poller",
                configMINIMAL_STACK_SIZE,
                NULL,
                1,
                prv_msp430_eusci_a_serial_minimal_poller_stack,
                &prv_msp430_eusci_a_serial_minimal_poller_tcb);
}
