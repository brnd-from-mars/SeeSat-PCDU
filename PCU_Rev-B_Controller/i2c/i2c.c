/*
 * project: PCU_Rev-B_Controller
 * author: Brendan Berg
 * date: 2023-05-28
 *
 * Copyright: (c) SeeSat e.V. 2023
 */

#include "i2c.h"


uint8_t i2c_get_status(void)
{
    return (TWSR & ((1u<<TWS7) | (1u<<TWS6) | (1u<<TWS5) | (1u<<TWS4) | (1u<<TWS3)));
}


void i2c_start_xfer(void)
{
    // set I2C frequency to 400.000kHz
    TWBR = 12u;
    TWSR = (0u<<TWPS0) | (0u<<TWPS1);

    // send start signal
    TWCR = (1u << TWINT) | (1u << TWSTA) | (1u << TWEN);

    // wait until ready
    for (uint16_t i = 0; (i < 0xffff) && ((TWCR & (1u<<TWINT)) == 0); ++i);
}


void i2c_send_byte(uint8_t d)
{
    // send byte
    TWDR = d;

    // reset interrupt flag, keep TWI activated
    TWCR = (1u<<TWINT) | (1u<<TWEN);

    // wait until transmission finished
    for (uint16_t i = 0; (i < 0xffff) && ((TWCR & (1u<<TWINT)) == 0); ++i);
}


void i2c_send_sla_w(uint8_t sla)
{
    i2c_send_byte((sla<<1) | 0u);
}


void i2c_send_sla_r(uint8_t sla)
{
    i2c_send_byte((sla<<1) | 1u);
}


uint8_t i2c_recv_byte(uint8_t ack_requested)
{
    // reset interrupt flag, keep TWI activated, prepare ACK
    TWCR = (1u<<TWINT) | (1u<<TWEN) | ((ack_requested ? 1u : 0u)<<TWEA);

    // wait until receive finished
    for (uint16_t i = 0; (i < 0xffff) && ((TWCR & (1u<<TWINT)) == 0); ++i);

    return TWDR;
}

void i2c_stop_xfer(void)
{
    // send stop signal
    TWCR = (1u<<TWINT) | (1u<<TWSTO) | (1u<<TWEN);
}


void i2c_reg_burst_read(uint8_t* buffer, uint8_t device_addr, uint8_t start_addr, uint8_t end_addr)
{
    i2c_start_xfer();
    i2c_send_sla_w(device_addr);
    i2c_send_byte(start_addr);
    i2c_start_xfer();
    i2c_send_sla_r(device_addr);

    for (uint8_t i = 0; (i + start_addr) <= end_addr; ++i)
    {
        buffer[i] = i2c_recv_byte((i + start_addr == end_addr) ? 0u : 1u);
    }

    i2c_stop_xfer();
}
