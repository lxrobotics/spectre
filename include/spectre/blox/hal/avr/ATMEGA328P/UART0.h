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

#ifndef INCLUDE_SPECTRE_BLOX_HAL_AVR_ATMEGA328P_UART0_H_
#define INCLUDE_SPECTRE_BLOX_HAL_AVR_ATMEGA328P_UART0_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <spectre/blox/hal/avr/common/ATxxxx/UART0.hpp>

#include <spectre/hal/avr/ATMEGA328P/InterruptController.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace blox
{

namespace ATMEGA328P
{

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef ATxxxx::UART0<hal::ATMEGA328P::toIntNum(hal::ATMEGA328P::Interrupt::USART_UART_DATA_REGISTER_EMPTY),
                      hal::ATMEGA328P::toIntNum(hal::ATMEGA328P::Interrupt::USART_RECEIVE_COMPLETE        )> UART0;

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* AT90CAN32_64_128 */

} /* blox */

} /* spectre */


#endif /* INCLUDE_SPECTRE_BLOX_HAL_AVR_ATMEGA328P_UART0_H_ */
