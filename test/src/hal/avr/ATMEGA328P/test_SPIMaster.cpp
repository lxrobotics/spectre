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
#include <hal/avr/ATMEGA328P/RegisterResetValueList.h>

#include <spectre/hal/avr/ATMEGA328P/SPIMaster.h>

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
 * TEST CODE
 **************************************************************************************/

SCENARIO("ATMEGA328P::SPIMaster - A SPIMaster object is constructed", "[ATMEGA328P::SPIMaster]")
{
  Register<uint8_t> SPCR(SPCR_RESET_VALUE),
                    SPSR(SPSR_RESET_VALUE),
                    SPDR(SPDR_RESET_VALUE);

  ATMEGA328P::SPIMaster spi_master(SPCR(), SPSR(), SPDR());

  THEN("SPCR bit #6 should be set (SPI ENABLE)")
  {
    REQUIRE(SPCR.isBitSet(6));
  }
}

/**************************************************************************************/

SCENARIO("ATMEGA328P::SPIMaster - A SPI mode is configured via 'setSpiMode'", "[ATMEGA328P::SPIMaster]")
{
  Register<uint8_t> SPCR(SPCR_RESET_VALUE),
                    SPSR(SPSR_RESET_VALUE),
                    SPDR(SPDR_RESET_VALUE);

  ATMEGA328P::SPIMaster spi_master(SPCR(), SPSR(), SPDR());

  WHEN("SPI Mode #0 is configured via 'setSpiMode'")
  {
    spi_master.setSpiMode(interface::SPIMode::MODE_0);
    THEN("SPCR bits 3-2 = 0b00 (CPHA | CPOL)")
    {
      REQUIRE(SPCR.isBitClr(3));
      REQUIRE(SPCR.isBitClr(2));
    }
  }
  WHEN("SPI Mode #1 is configured via 'setSpiMode'")
  {
    spi_master.setSpiMode(interface::SPIMode::MODE_1);
    THEN("SPCR bits 3-2 = 0b01 (CPHA | CPOL)")
    {
      REQUIRE(SPCR.isBitVectSet({2}));
    }
  }
  WHEN("SPI Mode #2 is configured via 'setSpiMode'")
  {
    spi_master.setSpiMode(interface::SPIMode::MODE_2);
    THEN("SPCR bits 3-2 = 0b10 (CPHA | CPOL)")
    {
      REQUIRE(SPCR.isBitVectSet({3}));
    }
  }
  WHEN("SPI Mode #3 is configured via 'setSpiMode'")
  {
    spi_master.setSpiMode(interface::SPIMode::MODE_3);
    THEN("SPCR bits 3-2 = 0b11 (CPHA | CPOL)")
    {
      REQUIRE(SPCR.isBitVectSet({3,2}));
    }
  }
}

/**************************************************************************************/

SCENARIO("ATMEGA328P::SPIMaster - A SPI prescaler is configured via 'setSpiPrescaler'", "[ATMEGA328P::SPIMaster]")
{
 Register<uint8_t> SPCR(SPCR_RESET_VALUE),
                   SPSR(SPSR_RESET_VALUE),
                   SPDR(SPDR_RESET_VALUE);

 ATMEGA328P::SPIMaster spi_master(SPCR(), SPSR(), SPDR());

 std::vector<uint32_t> const TEST_PRESCALER_VECT = {2, 4, 8, 16, 32, 64, 128, 1};

 std::for_each(
     std::begin(TEST_PRESCALER_VECT),
     std::end  (TEST_PRESCALER_VECT),
     [&spi_master, &SPSR, &SPCR](uint32_t const prescaler)
     {
       std::stringstream when_msg;
       when_msg << "The SPI prescaler is configured via calling 'setSpiPrescaler' with an argument of '" << prescaler << "'";

       WHEN(when_msg.str())
       {
         spi_master.setSpiPrescaler(prescaler);

         switch(prescaler)
         {
         case 2  : THEN("SPSR bit #0 = 0b1 | SPCR bits 1-0 = 0b00") { REQUIRE(SPSR.isBitSet(0)); REQUIRE(SPCR.isBitClr(1)); REQUIRE(SPCR.isBitClr(0)); } break;
         case 4  : THEN("SPSR bit #0 = 0b0 | SPCR bits 1-0 = 0b00") { REQUIRE(SPSR.isBitClr(0)); REQUIRE(SPCR.isBitClr(1)); REQUIRE(SPCR.isBitClr(0)); } break;
         case 8  : THEN("SPSR bit #0 = 0b1 | SPCR bits 1-0 = 0b01") { REQUIRE(SPSR.isBitSet(0)); REQUIRE(SPCR.isBitClr(1)); REQUIRE(SPCR.isBitSet(0)); } break;
         case 16 : THEN("SPSR bit #0 = 0b0 | SPCR bits 1-0 = 0b01") { REQUIRE(SPSR.isBitClr(0)); REQUIRE(SPCR.isBitClr(1)); REQUIRE(SPCR.isBitSet(0)); } break;
         case 32 : THEN("SPSR bit #0 = 0b1 | SPCR bits 1-0 = 0b10") { REQUIRE(SPSR.isBitSet(0)); REQUIRE(SPCR.isBitSet(1)); REQUIRE(SPCR.isBitClr(0)); } break;
         case 64 : THEN("SPSR bit #0 = 0b0 | SPCR bits 1-0 = 0b10") { REQUIRE(SPSR.isBitClr(0)); REQUIRE(SPCR.isBitSet(1)); REQUIRE(SPCR.isBitClr(0)); } break;
         case 128: THEN("SPSR bit #0 = 0b0 | SPCR bits 1-0 = 0b11") { REQUIRE(SPSR.isBitClr(0)); REQUIRE(SPCR.isBitSet(1)); REQUIRE(SPCR.isBitSet(0)); } break;
         case 1  : THEN("SPSR bit #0 = 0b0 | SPCR bits 1-0 = 0b00") { REQUIRE(SPSR.isBitClr(0)); REQUIRE(SPCR.isBitClr(1)); REQUIRE(SPCR.isBitClr(0)); } break;
         }
       }
     });
}

/**************************************************************************************
 * NAMESPACES
 **************************************************************************************/

} /* test */

} /* ATMEGA328P */

} /* hal */

} /* spectre */
