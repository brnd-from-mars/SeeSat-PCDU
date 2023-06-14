/*
 * project: PCU_Rev-B_Controller
 * author: Brendan Berg
 * date: 2023-05-28
 *
 * Copyright: (c) SeeSat e.V. 2023
 */

#ifndef PCU_REV_B_CONTROLLER_I2C_H
#define PCU_REV_B_CONTROLLER_I2C_H

#include <avr/io.h>


uint8_t i2c_get_status(void);

void i2c_start_xfer(void);

void i2c_send_byte(uint8_t d);

void i2c_send_sla_w(uint8_t sla);

void i2c_send_sla_r(uint8_t sla);

uint8_t i2c_recv_byte(uint8_t ack_requested);

void i2c_stop_xfer(void);

void i2c_reg_burst_read(uint8_t* buffer, uint8_t device_addr, uint8_t start_addr, uint8_t end_addr);


#endif //PCU_REV_B_CONTROLLER_I2C_H
