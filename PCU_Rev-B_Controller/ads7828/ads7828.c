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


void ads7828_init(struct ADS72828 *device)
{
    device->valid = true;
}


uint16_t ads7828_read_channel(struct ADS72828 *device, uint8_t channel)
{
    // if (!device->valid) return 0xFFFF;

    uint8_t device_addr = DEVICE_ADDR | device->a1a0;
    uint8_t command = (1u<<7) | (channel_to_c2c1c0[channel]<<4) | (3u<<2);
    uint16_t data = 0;

    i2c_start_xfer();
    i2c_send_sla_w(device_addr);
    i2c_send_byte(command);

    i2c_start_xfer();
    i2c_send_sla_r(device_addr);
    data |= i2c_recv_byte(1) << 8;
    data |= i2c_recv_byte(0);

    return data;
}
