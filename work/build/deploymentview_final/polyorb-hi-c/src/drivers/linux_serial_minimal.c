#include <drivers/linux_serial_minimal.h>
#include <drivers/configuration/serial.h>

#if defined __PO_HI_NEED_DRIVER_LINUX_SERIAL_MINIMAL

#include <po_hi_debug.h>
#include <po_hi_returns.h>
#include <po_hi_utils.h>
#include <po_hi_messages.h>
#include <po_hi_transport.h>
#include <po_hi_gqueue.h>
#include <po_hi_protected.h>

#include <drivers/po_hi_driver_serial_common.h>

#include <activity.h>
#include <marshallers.h>
#include <deployment.h>
#include <linux/ioctl.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Set parity bits in struct termios according to configuration.
 * If the configuration does not exist, then parity is disabled.
 */
static void setup_parity_bits(struct termios* tty, __po_hi_c_serial_conf_t* serialconf)
{
   if(serialconf->exist.parity && serialconf->exist.use_paritybit)
   {
       if(serialconf->use_paritybit)
       {
           if(serialconf->parity == __po_hi_c_odd)
           {
               __PO_HI_DEBUG_DEBUG("Setting parity odd\n");
               tty->c_cflag |= PARODD;
           }
           else
           {
               __PO_HI_DEBUG_DEBUG("Setting parity even\n");
               tty->c_cflag &= ~PARODD;
           }
           tty->c_cflag |= PARENB;
       }
       else
       {
           __PO_HI_DEBUG_DEBUG("Setting parity disabled\n");
           tty->c_cflag &= ~PARENB; // shut off parity
       }
   }
   else
   {
       __PO_HI_DEBUG_DEBUG("Setting parity disabled\n");
       tty->c_cflag &= ~PARENB;
   }
}

/* Set character size in struct termios according to configuration.
 * If the configuration does not exist, then character with is 8 bits.
 */

static void setup_bit_size(struct termios* tty, __po_hi_c_serial_conf_t* serialconf)
{
   if(serialconf->exist.bits)
   {
       switch(serialconf->bits)
       {
       case 5:
           __PO_HI_DEBUG_DEBUG("Setting bit 5\n");
           tty->c_cflag |= CS5;
           break;

       case 6:
           __PO_HI_DEBUG_DEBUG("Setting bit 6\n");
           tty->c_cflag |= CS6;
           break;

       case 7:
           __PO_HI_DEBUG_DEBUG("Setting bit 7\n");
           tty->c_cflag |= CS7;
           break;

       case 8:
           __PO_HI_DEBUG_DEBUG("Setting bit 8\n");
           tty->c_cflag |= CS8;
           break;

       default:
           __PO_HI_DEBUG_DEBUG("Setting bit 8\n");
           tty->c_cflag |= CS8;
           break;

       }
   }
   else
   {
       __PO_HI_DEBUG_DEBUG("Setting bit 8\n");
       tty->c_cflag |= CS8;
   }
}

/* Setup UART configuration.
 */
static void setup_termios(struct termios* tty, __po_hi_device_id id)
{
    __po_hi_c_serial_conf_t* serialconf = (__po_hi_c_serial_conf_t*)__po_hi_get_device_configuration(id);

    tty->c_cflag |= CREAD ;
    tty->c_iflag = IGNPAR | IGNBRK;
    tty->c_cc[VMIN]=1;
    tty->c_cc[VTIME]=0;

    setup_parity_bits(tty, serialconf);
    setup_bit_size(tty, serialconf);

    tty->c_cflag &= ~CSTOPB;
    tty->c_cflag &= ~CRTSCTS;
    tty->c_lflag &= ~ICANON;
    tty->c_lflag &= ~ECHOE;
    tty->c_lflag &= ~ECHO;
    tty->c_lflag &= ~ECHONL;
    tty->c_lflag &= ~ISIG;
    tty->c_iflag &= ~(IXON | IXOFF | IXANY);
    tty->c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);
    tty->c_oflag &= ~OPOST;
    tty->c_oflag &= ~ONLCR;
    tty->c_cflag &= ~OFILL;

    if(serialconf->exist.speed)
    {
        switch (serialconf->speed)
        {
        case __po_hi_c_b9600:
            cfsetospeed(tty, B9600);
            cfsetispeed(tty, B9600);
            __PO_HI_DEBUG_DEBUG ("[LINUX SERIAL] Set speed to 19200\n");
            break;

        case __po_hi_c_b19200:
            cfsetospeed(tty, B19200);
            cfsetispeed(tty, B19200);
            __PO_HI_DEBUG_DEBUG ("[LINUX SERIAL] Set speed to 19200\n");
            break;

        case __po_hi_c_b38400:
            cfsetospeed(tty, B38400);
            cfsetispeed(tty, B38400);
            __PO_HI_DEBUG_DEBUG ("[LINUX SERIAL] Set speed to 38400\n");
            break;

        case __po_hi_c_b57600:
            cfsetospeed(tty, B57600);
            cfsetispeed(tty, B57600);
            __PO_HI_DEBUG_DEBUG ("[LINUX SERIAL] Set speed to 57600\n");
            break;

        case __po_hi_c_b115200:
            cfsetospeed(tty, B115200);
            cfsetispeed(tty, B115200);
            __PO_HI_DEBUG_DEBUG ("[LINUX SERIAL] Set speed to 115200\n");
            break;

        case __po_hi_c_b230400:
            cfsetospeed(tty, B230400);
            cfsetispeed(tty, B230400);
            __PO_HI_DEBUG_DEBUG ("[LINUX SERIAL] Set speed to 115200\n");
            break;

        }
    }
    else
    {
        cfsetospeed(tty, B9600);
        cfsetispeed(tty, B9600);
        __PO_HI_DEBUG_DEBUG ("[LINUX SERIAL] Set speed to 9600\n");
    }
}

#define PACKET_START_BYTE '\x02'
#define PACKET_STOP_BYTE '\x03'
#define PACKET_ESCAPE_BYTE '\x1B'

// process packet data generated by PolyORB to send it using UART
static uint32_t encode_packet(uint8_t* data, const uint32_t data_length, const uint8_t* msg_content, const uint32_t msg_length)
{
    if(msg_length <= 8)
    {
        __PO_HI_DEBUG_DEBUG ("Encoding packet - not enough msg_length, at least 9 bytes is required, got %d\n", msg_length);
        // the message is empty
        return 0;
    }

    // structure of the msg_content:
    // - first four bytes of msg_content - port number
    // - next - actual data
    // - double word before dummy bytes  - length of data
    // - last double word - dummy bytes

    uint32_t* length_ptr = (uint32_t*)(msg_content + (msg_length - 4));

    uint32_t bytes_to_copy = (*length_ptr) + sizeof(uint32_t);

    if(data_length < (*length_ptr + sizeof(uint32_t)) * 2 + 2)
    {
        __PO_HI_DEBUG_CRITICAL ("Encoding packet - not enough data_length, at least %d bytes is required, got %d\n", *length_ptr, data_length);
        return 0;
    }

    uint32_t length = 0;

    data[length++] = PACKET_START_BYTE;

    uint32_t iter;
    for(iter = 0; iter < bytes_to_copy; ++iter)
    {
        uint8_t msg_byte = msg_content[iter];

        if(msg_byte == PACKET_START_BYTE || msg_byte == PACKET_STOP_BYTE || msg_byte == PACKET_ESCAPE_BYTE)
        {
            data[length++] = PACKET_ESCAPE_BYTE;
        }

        data[length++]= msg_byte;
    }

    data[length++] = PACKET_STOP_BYTE;

    return length;
}

int      po_hi_c_driver_serial_fd_read;
int      po_hi_c_driver_serial_fd_write;
uint32_t po_hi_c_driver_serial_sending_wait;

__po_hi_request_t __po_hi_c_driver_linux_serial_minimal_request;
__po_hi_mutex_t   __po_hi_c_driver_linux_serial_minimal_send_mutex;

void __po_hi_c_driver_linux_serial_minimal_init_receiver (__po_hi_device_id id)
{
   struct termios             oldtio,newtio;
   __po_hi_c_serial_conf_t*   serialconf;

   __PO_HI_DEBUG_INFO ("[LINUX SERIAL] Init receiver\n");

   serialconf = (__po_hi_c_serial_conf_t*)__po_hi_get_device_configuration (id);

   if (serialconf == NULL)
   {
      __PO_HI_DEBUG_INFO ("[LINUX SERIAL] Cannot get the name of the device !\n");
      return;
   }

   po_hi_c_driver_serial_fd_read = open (serialconf->devname, O_RDONLY | O_NOCTTY);

   if (po_hi_c_driver_serial_fd_read < 0)
   {
      __PO_HI_DEBUG_DEBUG ("[LINUX SERIAL] Error while opening device %s\n", serialconf->devname);
   }
   else
   {
      __PO_HI_DEBUG_DEBUG ("[LINUX SERIAL] Device %s successfully opened for reading, fd=%d\n", serialconf->devname , po_hi_c_driver_serial_fd_read);
   }


   tcgetattr (po_hi_c_driver_serial_fd_read, &oldtio);  /* save current serial port settings */
   tcgetattr (po_hi_c_driver_serial_fd_read, &newtio);  /* save current serial port settings */

   setup_termios(&newtio, id);

   if (tcflush (po_hi_c_driver_serial_fd_read, TCIOFLUSH) < 0)
   {
      __PO_HI_DEBUG_CRITICAL ("[LINUX SERIAL] Error in tcflush()\n");
   }

   if (tcsetattr (po_hi_c_driver_serial_fd_read, TCSANOW, &newtio) < 0)
   {
      __PO_HI_DEBUG_CRITICAL ("[LINUX SERIAL] Error in tcsetattr()\n");
   }

    __PO_HI_DEBUG_INFO ("[LINUX SERIAL] End of receiver init\n");
}

void __po_hi_c_driver_linux_serial_minimal_init_sender (__po_hi_device_id id)
{
   struct termios             oldtio,newtio;
   __po_hi_c_serial_conf_t*   serialconf;

   po_hi_c_driver_serial_sending_wait = 0;

   __PO_HI_DEBUG_INFO ("[LINUX SERIAL] Init sender\n");

   __po_hi_mutex_init (&__po_hi_c_driver_linux_serial_minimal_send_mutex,__PO_HI_MUTEX_REGULAR, 0);
   __po_hi_transport_set_sending_func (id, __po_hi_c_driver_linux_serial_minimal_sender);

   serialconf = (__po_hi_c_serial_conf_t*)__po_hi_get_device_configuration (id);

   if (serialconf == NULL)
   {
      __PO_HI_DEBUG_INFO ("[LINUX SERIAL] Cannot get the configuration of the device !\n");
      return;
   }

   if (serialconf->exist.sending_wait == 1)
   {
      po_hi_c_driver_serial_sending_wait = (uint32_t) serialconf->sending_wait;
      __PO_HI_DEBUG_INFO ("[LINUX SERIAL] Set sending delay to %u!\n",po_hi_c_driver_serial_sending_wait);
   }

   po_hi_c_driver_serial_fd_write = open (serialconf->devname, O_WRONLY | O_NOCTTY | O_NDELAY);

   if (po_hi_c_driver_serial_fd_write < 0)
   {
      __PO_HI_DEBUG_CRITICAL ("[LINUX SERIAL] Error while opening device %s\n", serialconf->devname);
   }
   else
   {
      __PO_HI_DEBUG_DEBUG ("[LINUX SERIAL] Device %s successfully opened for sending, fd=%d\n", serialconf->devname, po_hi_c_driver_serial_fd_write);
   }

   tcgetattr (po_hi_c_driver_serial_fd_write, &oldtio);  /* save current serial port settings */
   tcgetattr (po_hi_c_driver_serial_fd_write, &newtio);  /* save current serial port settings */

   setup_termios(&newtio, id);

   /*
    * clean the serial line and activate the settings for the port
    */
   if (tcflush (po_hi_c_driver_serial_fd_write, TCIOFLUSH) == -1)
   {
      __PO_HI_DEBUG_CRITICAL ("[LINUX SERIAL] Error in tcflush()\n");
   }

   if (tcsetattr (po_hi_c_driver_serial_fd_write, TCSANOW, &newtio) == -1)
   {
      __PO_HI_DEBUG_CRITICAL ("[LINUX SERIAL] Error in tcsetattr()\n");
   }

    __PO_HI_DEBUG_INFO ("[LINUX SERIAL] End of sender init\n");
}

void __po_hi_c_driver_linux_serial_minimal_init (__po_hi_device_id id)
{
   __po_hi_c_driver_linux_serial_minimal_init_receiver (id);
   __po_hi_c_driver_linux_serial_minimal_init_sender (id);
   return;
}

#define PACKET_DECODER_BUFFER_SIZE 100

enum PACKET_DECODER_STATE
{
    WAITING_FOR_START_BYTE,
    RECEIVING_MESSAGE,
    ESCAPE_STARTED
};

__po_hi_msg_t     __po_hi_c_driver_serial_linux_poller_msg;

static uint8_t packet_decoder_buffer[PACKET_DECODER_BUFFER_SIZE];
static int packet_decoder_index = 0;
static enum PACKET_DECODER_STATE packet_decoder_state;

static void process_packet(uint8_t* data, int size)
{
    uint32_t length = size;

    __PO_HI_DEBUG_DEBUG ("[LINUX SERIAL] Processing packet\n");
    __po_hi_msg_reallocate(&__po_hi_c_driver_serial_linux_poller_msg);
    memcpy(__po_hi_c_driver_serial_linux_poller_msg.content, data, size);
    memcpy(__po_hi_c_driver_serial_linux_poller_msg.content + (__PO_HI_MESSAGES_MAX_SIZE - 8), &length, 4);
    __po_hi_c_driver_serial_linux_poller_msg.length = __PO_HI_MESSAGES_MAX_SIZE;

    __po_hi_unmarshall_request(&__po_hi_c_driver_linux_serial_minimal_request,
                               &__po_hi_c_driver_serial_linux_poller_msg);

    __PO_HI_DEBUG_DEBUG ("[LINUX SERIAL] Deliver to port %u\n", __po_hi_c_driver_linux_serial_minimal_request.port);
    __po_hi_main_deliver(&__po_hi_c_driver_linux_serial_minimal_request);
}

static int process_character(uint8_t c)
{
    __PO_HI_DEBUG_DEBUG ("[LINUX SERIAL] Processing character\n");
    int result = 0;
    switch(packet_decoder_state)
    {
    case WAITING_FOR_START_BYTE:
        if(c == PACKET_START_BYTE)
        {
            packet_decoder_index = 0;
            packet_decoder_state = RECEIVING_MESSAGE;
        }
        break;

    case RECEIVING_MESSAGE:
        if(c == PACKET_START_BYTE)
        {
            packet_decoder_index = 0;
            packet_decoder_state = RECEIVING_MESSAGE;
        }
        else if(c == PACKET_STOP_BYTE)
        {
            process_packet(packet_decoder_buffer, packet_decoder_index);
            result = 1;
            packet_decoder_state = WAITING_FOR_START_BYTE;
        }
        else if(c == PACKET_ESCAPE_BYTE)
        {
            packet_decoder_state = ESCAPE_STARTED;
        }
        else
        {
            packet_decoder_buffer[packet_decoder_index] = c;
            ++packet_decoder_index;
        }
        break;

    case ESCAPE_STARTED:
        packet_decoder_buffer[packet_decoder_index] = c;
        ++packet_decoder_index;
        packet_decoder_state = RECEIVING_MESSAGE;
        break;

    };

    return result;
}

void __po_hi_c_driver_linux_serial_minimal_poller (const __po_hi_device_id dev_id)
{
    (void) dev_id;

    uint8_t local_buffer[1];

    while(1)
    {
        if (read (po_hi_c_driver_serial_fd_read, local_buffer, 1) == 1)
        {
            __PO_HI_DEBUG_DEBUG ("[LINUX SERIAL] Received one character %02x !\n", (unsigned int) local_buffer[0] );
            if(process_character(local_buffer[0]))
            {
                break;
            }
        }
        else
        {
            __PO_HI_DEBUG_CRITICAL ("[LINUX SERIAL] Cannot read !\n");
            return;
        }
    }
}

__po_hi_msg_t __po_hi_c_driver_linux_serial_minimal_sender_msg;

int  __po_hi_c_driver_linux_serial_minimal_sender (__po_hi_task_id task_id, __po_hi_port_t port)
{
   int                     n;
   __po_hi_local_port_t    local_port;
   __po_hi_request_t*      request;
   __po_hi_port_t          destination_port;

   local_port = __po_hi_get_local_port_from_global_port (port);

   request = __po_hi_gqueue_get_most_recent_value (task_id, local_port);

   if (request->port == -1)
   {
      __PO_HI_DEBUG_DEBUG("[LINUX SERIAL] Send output task %d, port %d (local_port=%d): no value to send\n", task_id, port, local_port);
      return __PO_HI_SUCCESS;
   }

   destination_port     = __po_hi_gqueue_get_destination (task_id, local_port, 0);
   __po_hi_mutex_lock (&__po_hi_c_driver_linux_serial_minimal_send_mutex);

   __po_hi_msg_reallocate (&__po_hi_c_driver_linux_serial_minimal_sender_msg);

   request->port = destination_port;

   __po_hi_marshall_request (request, &__po_hi_c_driver_linux_serial_minimal_sender_msg);

   uint32_t msg_length = (uint32_t) __po_hi_msg_length(&__po_hi_c_driver_linux_serial_minimal_sender_msg);
   uint8_t* msg_content = (uint8_t*) malloc(msg_length);
   __po_hi_msg_get_data(msg_content,
                        &__po_hi_c_driver_linux_serial_minimal_sender_msg,
                        0,
                        msg_length);

   uint32_t data_length = msg_length * 2 + 2;
   uint8_t* data = (uint8_t*)malloc(data_length);
   uint32_t length = encode_packet(data, data_length, msg_content, msg_length);

   if(length > 0)
   {

       if (po_hi_c_driver_serial_sending_wait != 0)
       {
           __PO_HI_DEBUG_DEBUG (" [LINUX SERIAL] write %d bytes in loop to device\n", length);

           for (n = 0 ; n < (int)length ; n++)
           {
               write (po_hi_c_driver_serial_fd_write, &(data[n]), 1);
               usleep (po_hi_c_driver_serial_sending_wait);

               fsync(po_hi_c_driver_serial_fd_write);

               if (n <= 0)
               {
                   __PO_HI_DEBUG_CRITICAL (" [LINUX SERIAL] failed to write !\n");
               }
           }

       }
       else
       {
           __PO_HI_DEBUG_DEBUG (" [LINUX SERIAL] write %d bytes to device\n", length);

           n = write (po_hi_c_driver_serial_fd_write, data, length);

           fsync(po_hi_c_driver_serial_fd_write);

           if (n < 0)
           {
               __PO_HI_DEBUG_CRITICAL (" [LINUX SERIAL] failed !\n");
           }
           else if((0 <= n)&(n < (int)length))
           {
               __PO_HI_DEBUG_CRITICAL (" [LINUX SERIAL] Unable write - write returned %d !\n", n);
           }
           else
           {
               __PO_HI_DEBUG_CRITICAL (" [LINUX SERIAL] OK !\n");
           }

       }

       __PO_HI_DEBUG_DEBUG  ("[LINUX SERIAL] write() returns %d, message sent: 0x\n", n);
   }

   __po_hi_mutex_unlock (&__po_hi_c_driver_linux_serial_minimal_send_mutex);
   request->port = __PO_HI_GQUEUE_INVALID_PORT;

   free(msg_content);

   return 1;
}

#endif
