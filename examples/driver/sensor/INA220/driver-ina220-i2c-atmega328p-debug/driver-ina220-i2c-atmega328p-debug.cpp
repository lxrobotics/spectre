/**
 * Spectre is a modular RTOS with extensive IO support.
 * Copyright (C) 2017 - 2018 Alexander Entinger / LXRobotics GmbH
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

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <avr/io.h>

#include <spectre/hal/avr/ATMEGA328P/Flash.h>
#include <spectre/hal/avr/ATMEGA328P/I2cMaster.h>
#include <spectre/hal/avr/ATMEGA328P/CriticalSection.h>
#include <spectre/hal/avr/ATMEGA328P/InterruptController.h>

#include <spectre/blox/hal/avr/ATMEGA328P/UART0.h>

#include <spectre/blox/driver/serial/SerialUart.h>

#include <spectre/driver/sensor/INA220/INA220_IoI2c.h>
#include <spectre/driver/sensor/INA220/INA220_Debug.h>

#include <spectre/debug/serial/DebugSerial.h>

/**************************************************************************************
 * NAMESPACES
 **************************************************************************************/

using namespace spectre;
using namespace spectre::hal;
using namespace spectre::driver;

/**************************************************************************************
 * GLOBAL CONSTANTS
 **************************************************************************************/

static uint16_t const UART_RX_BUFFER_SIZE = 0;
static uint16_t const UART_TX_BUFFER_SIZE = 16;

static uint8_t  const INA220_I2C_ADDR     = (0x40 << 1); /* A1 and A0 = GND */

/**************************************************************************************
 * MAIN
 **************************************************************************************/

int main()
{
  /************************************************************************************
   * HAL
   ************************************************************************************/

  ATMEGA328P::Flash               flash;
  ATMEGA328P::InterruptController int_ctrl  (&EIMSK, &PCICR, &WDTCSR, &TIMSK2, &TIMSK1, &TIMSK0, &SPCR, &UCSR0B, &ADCSRA, &EECR, &ACSR, &TWCR, &SPMCSR);
  ATMEGA328P::CriticalSection     crit_sec  (&SREG);
  ATMEGA328P::I2cMaster           i2c_master(&TWCR, &TWDR, &TWSR, &TWBR);

  blox::ATMEGA328P::UART0         uart0     (&UDR0, &UCSR0A, &UCSR0B, &UCSR0C, &UBRR0, int_ctrl, F_CPU);

  i2c_master.setI2cClock(hal::interface::I2cClock::F_100_kHz);


  /************************************************************************************
   * DRIVER
   ************************************************************************************/

  /* SERIAL ***************************************************************************/
  blox::SerialUart   serial(crit_sec,
                            uart0(),
                            UART_RX_BUFFER_SIZE,
                            UART_TX_BUFFER_SIZE,
                            serial::interface::SerialBaudRate::B115200,
                            serial::interface::SerialParity::None,
                            serial::interface::SerialStopBit::_1);

  debug::DebugSerial debug_serial(serial());

  /* INA220 ***************************************************************************/
  sensor::INA220::INA220_IoI2c ina220_io(INA220_I2C_ADDR, i2c_master);

  /* GLOBAL INTERRUPT *****************************************************************/
  int_ctrl.enableInterrupt(ATMEGA328P::toIntNum(ATMEGA328P::Interrupt::GLOBAL));


  /************************************************************************************
   * APPLICATION
   ************************************************************************************/

  sensor::INA220::INA220_Debug::debug_dumpAllRegs(debug_serial, flash, ina220_io);

  for(;;)
  {
  }

  return 0;
}