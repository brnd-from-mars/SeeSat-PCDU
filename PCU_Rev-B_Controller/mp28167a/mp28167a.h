/*
 * project: PCU_Rev-B_Controller
 * author: Brendan Berg
 * date: 2023-05-28
 *
 * Copyright: (c) SeeSat e.V. 2023
 */

#ifndef PCU_REV_B_CONTROLLER_MP28167A_H
#define PCU_REV_B_CONTROLLER_MP28167A_H

#include <avr/io.h>
#include <stdbool.h>


struct MP28167A
{
    bool valid;

    uint16_t v_ref;

    bool pg_delay_en;

};

void mp28167a_init(struct MP28167A* device);

void mp28167a_set_vref(struct MP28167A* device, uint16_t vref);

void mp28167a_set_go_bit(struct MP28167A* device);

void mp28167a_wait_go_bit_release(struct MP28167A* device);

void mp28167a_set_pg_delay_en(struct MP28167A* device, bool pg_delay_en);


#endif //PCU_REV_B_CONTROLLER_MP28167A_H
