/*
 * project: PCU_Rev-B_Controller
 * author: Brendan Berg
 * date: 2023-06-14
 *
 * Copyright: (c) SeeSat e.V. 2023
 */

#ifndef PCU_REV_B_CONTROLLER_UART_H
#define PCU_REV_B_CONTROLLER_UART_H

#include <avr/io.h>
#include <stdio.h>


int uart_putchar(char c, FILE* stream);

int uart_getchar(FILE* stream);



void uart_init(void);


#endif //PCU_REV_B_CONTROLLER_UART_H
