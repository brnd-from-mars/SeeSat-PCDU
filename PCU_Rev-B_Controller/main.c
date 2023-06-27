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


int main(void)
{
    DDRB |= (1<<PORTB0);

    struct MP28167A mp28167a;
    uint16_t vref = 1244;

    while (true)
    {
        mp28167a_init(&mp28167a);

        if(mp28167a.valid)
        {
            // turn status LED on
            PORTB |= (1<<PORTB0);

            // set new MPPT output voltage
            mp28167a_set_vref(&mp28167a, vref);
            mp28167a_set_go_bit(&mp28167a);
            mp28167a_wait_go_bit_release(&mp28167a);
        }
        else
        {
            // turn status LED off
            PORTB &= ~(1<<PORTB0);
        }

        _delay_ms(100);
    }

    return 0;
}
