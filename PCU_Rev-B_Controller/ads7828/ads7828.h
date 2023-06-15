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

int ads7828_init(struct ADS72828* device);


#endif //PCU_REV_B_CONTROLLER_ADS7828_H
