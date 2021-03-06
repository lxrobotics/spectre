/**
 * Snowfox is a modular RTOS with extensive IO support.
 * Copyright (C) 2017 - 2020 Alexander Entinger / LXRobotics GmbH
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

#ifndef INTERFACE_UART_CONFIGURATION_H_
#define INTERFACE_UART_CONFIGURATION_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdint.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::hal::interface
{

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

enum class UartBaudRate : uint8_t
{
  B115200
};

enum class UartParity : uint8_t
{
  None,
  Even,
  Odd
};

enum class UartStopBit : uint8_t
{
  _1,
  _2
};

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class UartConfiguration
{

public:

           UartConfiguration() { }
  virtual ~UartConfiguration() { }


  virtual bool setBaudRate(UartBaudRate const baud_rate) = 0;
  virtual bool setParity  (UartParity   const parity   ) = 0;
  virtual bool setStopBit (UartStopBit  const stop_bit ) = 0;
  
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::hal::interface*/

#endif /* INTERFACE_UART_CONFIGURATION_H_ */
