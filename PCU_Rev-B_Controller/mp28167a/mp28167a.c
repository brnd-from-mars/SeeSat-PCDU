/*
 * project: PCU_Rev-B_Controller
 * author: Brendan Berg
 * date: 2023-05-28
 *
 * Copyright: (c) SeeSat e.V. 2023
 */

#include "../i2c/i2c.h"

#include "mp28167a.h"
#include "mp28167a_register.h"


void mp28167a_init(struct MP28167A* device)
{
    device->valid = true;

    uint8_t data[4];
    i2c_reg_burst_read(&data[0], DEVICE_ADDR, REG_ID1, REG_ID1);
    i2c_reg_burst_read(&data[1], DEVICE_ADDR, REG_MFR_ID, REG_IC_REV);

    if ((data[0] != 0x00) ||
        (data[1] != 0x09) ||
        (data[2] != 0x58) ||
        (data[3] != 0x01))
    {
        device->valid = false;
    }
}


void mp28167a_set_vref(struct MP28167A* device, uint16_t vref)
{
    if (!device->valid) return;

    i2c_start_xfer();
    i2c_send_sla_w(DEVICE_ADDR);
    i2c_send_byte(REG_VREF_L);
    i2c_send_byte(vref & 0x07);
    i2c_send_byte(vref>>3);
    i2c_stop_xfer();
}

void mp28167a_set_go_bit(struct MP28167A* device)
{
    if (!device->valid) return;

    i2c_start_xfer();
    i2c_send_sla_w(DEVICE_ADDR);
    i2c_send_byte(REG_VREF_GO);
    i2c_send_byte(0x01 | (device->pg_delay_en ? 0x02 : 0x00));
    i2c_stop_xfer();
}


void mp28167a_set_pg_delay_en(struct MP28167A* device, bool pg_delay_en)
{
    if (!device->valid) return;

    device->pg_delay_en = pg_delay_en;

    i2c_start_xfer();
    i2c_send_sla_w(DEVICE_ADDR);
    i2c_send_byte(REG_VREF_GO);
    i2c_send_byte(device->pg_delay_en ? 0x02 : 0x00);

    i2c_stop_xfer();
}
