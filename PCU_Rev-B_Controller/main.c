/*
 * project: PCU_Rev-B_Controller
 * author: Brendan Berg
 * date: 2023-04-05
 *
 * Copyright: (c) SeeSat e.V. 2023
 */

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB |= (1 << PORTB0);

    while(1)
    {
        PORTB |= (1 << PORTB0);
        _delay_ms(200);
        PORTB &= ~(1 << PORTB0);
        _delay_ms(800);
    }

    return 0;
}
