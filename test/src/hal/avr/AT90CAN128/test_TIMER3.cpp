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

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <catch.hpp>

#include <Register.h>
#include <hal/avr/AT90CAN128/RegisterResetValueList.h>

#include <spectre/hal/avr/AT90CAN128/TIMER3.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace hal
{

namespace AT90CAN128
{

namespace test
{

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

SCENARIO("AT90CAN128::TIMER3 - A timer's prescaler is manipulated via 'setPrescaler'", "[AT90CAN128::TIMER3]")
{
  Register<uint16_t> TCNT3 (TCNT3_RESET_VALUE );
  Register<uint8_t>  TCCR3B(TCCR3B_RESET_VALUE);
  Register<uint16_t> OCR3A (OCR3A_RESET_VALUE ),
                     OCR3B (OCR3B_RESET_VALUE ),
                     OCR3C (OCR3C_RESET_VALUE );

  AT90CAN128::TIMER3 timer0(TCNT3(), TCCR3B(), OCR3A(), OCR3B(), OCR3C());

  /* TODO */

}

/**************************************************************************************
 * NAMESPACES
 **************************************************************************************/

} /* test */

} /* AT90CAN128 */

} /* hal */

} /* spectre */