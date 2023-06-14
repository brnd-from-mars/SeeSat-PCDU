cmake_minimum_required(VERSION 3.16)

set(AVR_MCU atmega328p)
set(AVR_PROGRAMMER stk500)
set(AVR_PORT /dev/cu.usbmodem84F7_03C7_C19C1)
set(AVR_BAUDRATE auto)

set(AVR_LFUSE 0xff)
set(AVR_HFUSE 0xdd)
set(AVR_EFUSE 0xff)
set(AVR_FREQ 16000000UL)

project(PCU_Rev-B_Controller C)

avr_generate_fixed_targets()

avr_add_executable(PCU_Rev-B_Controller main.c i2c/i2c.c mp28167a/mp28167a.c)
