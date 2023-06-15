/*
 * project: PCU_Rev-B_Controller
 * author: Brendan Berg
 * date: 2023-05-28
 *
 * Copyright: (c) SeeSat e.V. 2023
 */

#ifndef PCU_REV_B_CONTROLLER_MP28167A_REGISTER_H
#define PCU_REV_B_CONTROLLER_MP28167A_REGISTER_H


#define DEVICE_ADDR 0x60

#define REG_VREF_L 0x00

#define REG_VREF_H 0x01

#define REG_VREF_GO 0x02

#define REG_IOUT_LIM 0x03

#define REG_CTL1 0x04

#define reg_CTL2 0x05

#define REG_Status 0x09

#define REG_INTERRUPT 0x0A

#define REG_MASK 0x0B

#define REG_ID1 0x0C

#define REG_MFR_ID 0x27

#define REG_DEV_ID 0x28

#define REG_IC_REV 0x29


#endif //PCU_REV_B_CONTROLLER_MP28167A_REGISTER_H
