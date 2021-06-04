#ifndef MSP430_EUSCI_A_SERIAL_DRIVER_HPP__
#define MSP430_EUSCI_A_SERIAL_DRIVER_HPP__

#include <stdint.h>

void msp430_eusci_a_serial_minimal_init(void);
void msp430_eusci_a_serial_minimal_poller(void* param);
void msp430_eusci_a_serial_minimal_sender(uint8_t* data, uint32_t length, uint32_t port);

#endif
