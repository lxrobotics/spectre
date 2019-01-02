/**
 * Spectre is a modular RTOS with extensive IO support.
 * Copyright (C) 2017 - 2019 Alexander Entinger / LXRobotics GmbH
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

#ifndef INCLUDE_SPECTRE_HAL_AVR_ATMEGA324P_EEPROM_H_
#define INCLUDE_SPECTRE_HAL_AVR_ATMEGA324P_EEPROM_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <spectre/hal/avr/common/ATxxxx/EEPROM.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace hal
{

namespace ATMEGA324P
{

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef ATxxxx::EEPROM EEPROM;

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* ATMEGA324P */

} /* hal */

} /* spectre */

#endif /* INCLUDE_SPECTRE_HAL_AVR_ATMEGA324P_EEPROM_H_ */
