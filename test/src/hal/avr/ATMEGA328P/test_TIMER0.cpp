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

#include <sstream>
#include <algorithm>

#include <catch.hpp>

#include <Register.h>

#include <spectre/hal/avr/ATMEGA328P/TIMER0.h>

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

static uint8_t const TCNT0_RESET_VALUE   = 0b00000000;
static uint8_t const TCCR0B_RESET_VALUE  = 0b00000000;

/**************************************************************************************/

SCENARIO("A timer's prescaler is manipulated via 'setPrescaler'", "[ATMEGA328P::TIMER0]")
{
  Register<uint8_t> TCNT0 (TCNT0_RESET_VALUE ),
                    TCCR0B(TCCR0B_RESET_VALUE);

  ATMEGA328P::TIMER0 timer0(TCNT0(), TCCR0B());

  std::vector<uint32_t> const VALID_PRESCALER_VECT = {0, 1, 8, 64, 256, 1024};

  std::for_each(
      std::begin(VALID_PRESCALER_VECT),
      std::end  (VALID_PRESCALER_VECT),
      [&timer0, &TCCR0B](uint32_t const prescaler)
      {
        std::stringstream when_msg;
        when_msg << "The prescaler is configured via calling 'setPrescaler' with an argument of '" << prescaler << "'";

        WHEN(when_msg.str())
        {
          timer0.setPrescaler(prescaler);
          WHEN("'start' is called")
          {
            timer0.start();

            switch(prescaler)
            {
            case 0    : THEN("TCCR0B bits 2-0 == 0b000") REQUIRE(TCCR0B.isBitVectSet({     })); break;
            case 1    : THEN("TCCR0B bits 2-0 == 0b001") REQUIRE(TCCR0B.isBitVectSet({    0})); break;
            case 8    : THEN("TCCR0B bits 2-0 == 0b010") REQUIRE(TCCR0B.isBitVectSet({  1  })); break;
            case 64   : THEN("TCCR0B bits 2-0 == 0b011") REQUIRE(TCCR0B.isBitVectSet({  1,0})); break;
            case 256  : THEN("TCCR0B bits 2-0 == 0b100") REQUIRE(TCCR0B.isBitVectSet({2    })); break;
            case 1024 : THEN("TCCR0B bits 2-0 == 0b101") REQUIRE(TCCR0B.isBitVectSet({2,  0})); break;
            }
          }
          WHEN("'start' is not called")
          {
            THEN("TCCR0B bits 2-0 == 0b000") REQUIRE(TCCR0B == TCCR0B_RESET_VALUE);
          }
        }
      });
}

/**************************************************************************************/

SCENARIO("A timer is started ('start') and stopped ('stop')", "[ATMEGA328P::TIMER0]")
{
  Register<uint8_t> TCNT0 (TCNT0_RESET_VALUE ),
                    TCCR0B(TCCR0B_RESET_VALUE);

  uint32_t const prescaler = 8;

  ATMEGA328P::TIMER0 timer0(TCNT0(), TCCR0B());

  timer0.setPrescaler(prescaler);

  WHEN("'start' is called")
  {
    timer0.start();
    THEN("TCCR0B contains the expected prescaler bit pattern") REQUIRE(TCCR0B.isBitVectSet({1}));
    WHEN("'stop' is called")
    {
      timer0.stop();
      THEN("TCCR0B contains the RESET prescaler bit pattern") REQUIRE(TCCR0B == TCCR0B_RESET_VALUE);
      WHEN("'start' is called (again)")
      {
        timer0.start();
        THEN("TCCR0B contains the expected prescaler bit pattern (again)") REQUIRE(TCCR0B.isBitVectSet({1}));
      }
    }
  }
}

/**************************************************************************************/

SCENARIO("A timer's counter register is read ('get') and written ('set')", "[ATMEGA328P::TIMER0]")
{
  Register<uint8_t> TCNT0 (TCNT0_RESET_VALUE ),
                    TCCR0B(TCCR0B_RESET_VALUE);

  ATMEGA328P::TIMER0 timer0(TCNT0(), TCCR0B());

  WHEN("the counter register is read via 'get'")
  {
    TCNT0 = 0xCA;
    THEN("the current value should be returned")
    {
      REQUIRE(timer0.get() == 0xCA);
    }
  }
  WHEN("the counter register is written via 'set'")
  {
    timer0.set(0xFF);
    THEN("TCNT0 should contain the written value")
    {
      REQUIRE(TCNT0 == 0xFF);
    }
  }
}

/**************************************************************************************/

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

} /* test */

} /* ATMEGA328P */

} /* hal */

} /* spectre */
