/*
 * project: PCU_Rev-B_Controller
 * author: Brendan Berg
 * date: 2023-06-14
 *
 * Copyright: (c) SeeSat e.V. 2023
 */

#ifndef PCU_REV_B_CONTROLLER_ADS7828_H
#define PCU_REV_B_CONTROLLER_ADS7828_H

#include <avr/io.h>
#include <stdbool.h>


struct ADS72828
{
    bool valid;

    uint8_t a1a0;

};

void ads7828_init(struct ADS72828 *device);

uint16_t ads7828_read_channel(struct ADS72828 *device, uint8_t channel);


#endif //PCU_REV_B_CONTROLLER_ADS7828_H
