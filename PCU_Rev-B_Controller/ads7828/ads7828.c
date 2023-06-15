/*
 * project: PCU_Rev-B_Controller
 * author: Brendan Berg
 * date: 2023-06-14
 *
 * Copyright: (c) SeeSat e.V. 2023
 */

#include "../i2c/i2c.h"

#include "ads7828.h"
#include "ads7828_register.h"


int ads7828_init(struct ADS72828 *device)
{
    device->valid = true;

    uint8_t device_addr = DEVICE_ADDR | device->a1a0;

    i2c_start_xfer();
    i2c_send_sla_w(device_addr);
    i2c_send_byte(0x8C);

    i2c_start_xfer();
    i2c_send_sla_r(device_addr);
    int MSB = i2c_recv_byte(1);
    int LSB = i2c_recv_byte(0);

    return (MSB<<8) | LSB;
}
