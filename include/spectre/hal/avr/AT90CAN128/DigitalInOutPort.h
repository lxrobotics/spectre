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

#ifndef INCLUDE_SPECTRE_HAL_AVR_AT90CAN128_DIGITALINOUTPORT_H_
#define INCLUDE_SPECTRE_HAL_AVR_AT90CAN128_DIGITALINOUTPORT_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <spectre/hal/avr/ATxxxx/DigitalInOutPort.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace hal
{

namespace AT90CAN128
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class DigitalInOutPort : public ATxxxx::DigitalInOutPort
{

public:

           DigitalInOutPort(volatile uint8_t * ddr, volatile uint8_t * port, volatile uint8_t * pin) : ATxxxx::DigitalInOutPort(ddr, port, pin) { }
  virtual ~DigitalInOutPort() { }

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* AT90CAN128 */

} /* hal */

} /* spectre */

#endif /* INCLUDE_SPECTRE_HAL_AVR_AT90CAN128_DIGITALINOUTPORT_H_ */
