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

#include "ads7828/ads7828.h"
#include "mp28167a/mp28167a.h"
#include "uart/uart.h"


int main(void)
{
    DDRB |= (1<<PORTB0);

    struct MP28167A mp28167a;
    uint16_t vref = 1244;

    struct ADS72828 ads72828;
    ads72828.a1a0 = 0x00;

    uart_init();

    while (true)
    {
        mp28167a_init(&mp28167a);
        ads7828_init(&ads72828);

        if(mp28167a.valid && ads72828.valid)
        {
            // turn status LED on
            PORTB |= (1<<PORTB0);

            // cycle MPPT output voltage
            //++vref;
            //if (vref == 2047) vref = 400;

            // set new MPPT output voltage
            mp28167a_set_vref(&mp28167a, vref);
            mp28167a_set_go_bit(&mp28167a);

            printf("%d,", vref);
            for (uint8_t i = 0; i < 8; ++i)
            {
                printf("%d,", ads7828_read_channel(&ads72828, i));
            }
            printf("\n");
        }
        else
        {
            // turn status LED off
            PORTB &= ~(1<<PORTB0);
        }
    }

    return 0;
}
