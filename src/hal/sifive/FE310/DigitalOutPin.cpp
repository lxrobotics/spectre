/**
 * Snowfox is a modular RTOS with extensive IO support.
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

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <snowfox/hal/sifive/FE310/DigitalOutPin.h>

#include <util/BitManip.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox
{

namespace hal
{

namespace FE310
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

DigitalOutPin::DigitalOutPin(volatile uint32_t       * gpio_input_en,
                             volatile uint32_t       * gpio_output_en,
                             volatile uint32_t       * gpio_output_val,
                                      uint8_t  const   out_pin_number)
: _gpio_output_val(gpio_output_val),
  _out_pin_number (out_pin_number )
{
  setGpioPinAsOutput(gpio_input_en, gpio_output_en, out_pin_number);
}

DigitalOutPin::~DigitalOutPin()
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void DigitalOutPin::set()
{
  util::setBit(_gpio_output_val, _out_pin_number);
}

void DigitalOutPin::clr()
{
  util::clrBit(_gpio_output_val, _out_pin_number);
}

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

void DigitalOutPin::setGpioPinAsOutput(volatile uint32_t * gpio_input_en, volatile uint32_t * gpio_output_en, uint8_t const out_pin_number)
{
  util::clrBit(gpio_input_en,  out_pin_number);
  util::setBit(gpio_output_en, out_pin_number);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* FE310 */

} /* hal */

} /* snowfox */
