/*
 * project: PCU_Rev-B_Controller
 * author: Brendan Berg
 * date: 2023-04-05
 *
 * Copyright: (c) SeeSat e.V. 2023
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#include "mp28167a/mp28167a.h"
#include "uart/uart.h"


int main(void)
{
    DDRB |= (1<<PORTB0);

    struct MP28167A mp28167a;

    uint16_t vref = 1244;

    uart_init();

    while (true)
    {
        mp28167a_init(&mp28167a);
        if(mp28167a.valid)
        {
            PORTB |= (1<<PORTB0);

            mp28167a_set_vref(&mp28167a, vref);
            mp28167a_set_go_bit(&mp28167a);
        }
        else
        {
            PORTB &= ~(1<<PORTB0);
        }
        _delay_ms(10);
    }

    return 0;
}
