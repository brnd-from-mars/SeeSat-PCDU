/*
 * project: PCU_Rev-B_Controller
 * author: Brendan Berg
 * date: 2023-06-14
 *
 * Copyright: (c) SeeSat e.V. 2023
 */

#include "uart.h"


FILE uart_stdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
FILE uart_stdin = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);

int uart_putchar(char c, FILE *stream)
{
    // wait until transmit register empty
    while ((UCSR0A & (1u<<UDRE0)) == 0);

    // send byte
    UDR0 = c;

    return 0;
}


int uart_getchar(FILE *stream)
{
    // wait until byte received
    while ((UCSR0A & (1u<<RXC0)) == 0);

    // TODO: catch exceptions

    // get byte
    uint8_t c = UDR0;

    uart_putchar(c, NULL);

    return c;
}


void uart_init(void)
{
    // High-Speed-Mode, 57.600 Baud: UBRR0 = 34, U2X0 = 1
    UBRR0 = 34u;
    UCSR0A = (1u << U2X0);

    // Frame-Format: 8N1
    UCSR0B = (1u << RXEN0) | (1u << TXEN0) | (0u << UCSZ02);
    UCSR0C = (0u << USBS0) | (1u << UCSZ01) | (1u << UCSZ00);

    // setup stdout and stdin
    stdout = &uart_stdout;
    stdin = &uart_stdin;
}
