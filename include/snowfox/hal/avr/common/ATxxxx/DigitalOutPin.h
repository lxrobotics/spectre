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

#ifndef INCLUDE_SNOWFOX_HAL_AVR_ATXXXX_DIGITALOUTPIN_H_
#define INCLUDE_SNOWFOX_HAL_AVR_ATXXXX_DIGITALOUTPIN_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdint.h>

#include <snowfox/hal/interface/gpio/DigitalOutPin.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::hal::ATxxxx
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class DigitalOutPin : public interface::DigitalOutPin
{

public:

           DigitalOutPin(volatile uint8_t * ddr, volatile uint8_t * port, uint8_t const out_pin_number);
  virtual ~DigitalOutPin();


  virtual void set() override;
  virtual void clr() override;


private:

  volatile uint8_t       * _port;
           uint8_t const  _out_pin_number;

  static void setGpioPinAsOutput(volatile uint8_t * ddr, uint8_t const out_pin_number);

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::hal::ATxxxx */

#endif /* INCLUDE_SNOWFOX_HAL_AVR_ATXXXX_DIGITALOUTPIN_H_ */
