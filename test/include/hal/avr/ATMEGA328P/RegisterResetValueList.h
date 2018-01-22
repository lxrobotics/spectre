/**
 * Spectre is a modular RTOS with extensive IO support.
 * Copyright (C) 2017 Alexander Entinger / LXRobotics GmbH
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TEST_INCLUDE_HAL_AVR_ATMEGA328P_REGISTERRESETVALUELIST_H_
#define TEST_INCLUDE_HAL_AVR_ATMEGA328P_REGISTERRESETVALUELIST_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <stdint.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace hal
{

namespace ATMEGA328P
{

namespace test
{

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

/* EINT0/1 */
static uint8_t  const EIMSK_RESET_VALUE   = 0;

/* PIN CHANGE */
static uint8_t  const PCICR_RESET_VALUE   = 0;

/* WATCHDOG */
static uint8_t  const WDTCSR_RESET_VALUE  = 0;

/* TIMER2 */
static uint8_t  const TCNT2_RESET_VALUE   = 0;
static uint8_t  const TCCR2B_RESET_VALUE  = 0b00000000;
static uint8_t  const OCR2A_RESET_VALUE   = 0;
static uint8_t  const OCR2B_RESET_VALUE   = 0;
static uint8_t  const TIMSK2_RESET_VALUE  = 0;

/* TIMER1 */
static uint16_t const TCNT1_RESET_VALUE   = 0;
static uint8_t  const TCCR1B_RESET_VALUE  = 0b00000000;
static uint16_t const OCR1A_RESET_VALUE   = 0;
static uint16_t const OCR1B_RESET_VALUE   = 0;
static uint8_t  const TIMSK1_RESET_VALUE  = 0;

/* TIMER0 */
static uint8_t  const TCNT0_RESET_VALUE   = 0;
static uint8_t  const TCCR0B_RESET_VALUE  = 0b00000000;
static uint8_t  const OCR0A_RESET_VALUE   = 0;
static uint8_t  const OCR0B_RESET_VALUE   = 0;
static uint8_t  const TIMSK0_RESET_VALUE  = 0;

/* SPI */
static uint8_t  const SPCR_RESET_VALUE    = 0;
static uint8_t  const SPSR_RESET_VALUE    = 0;
static uint8_t  const SPDR_RESET_VALUE    = 0;

/* UART0 */
static uint8_t  const UCSR0B_RESET_VALUE  = 0;

/* ADC */
static uint8_t  const ADCSRA_RESET_VALUE  = 0;

/* EEPROM */
static uint8_t  const EECR_RESET_VALUE    = 0;

/* ANALOG COMPARATOR */
static uint8_t  const ACSR_RESET_VALUE    = 0;

/* TWI (I2C) */
static uint8_t  const TWCR_RESET_VALUE    = 0;

/* STACK POINTER */
static uint8_t  const SPMCSR_RESET_VALUE  = 0;

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

} /* test */

} /* ATMEGA328P */

} /* hal */

} /* spectre */

#endif /* TEST_INCLUDE_HAL_AVR_ATMEGA328P_REGISTERRESETVALUELIST_H_ */