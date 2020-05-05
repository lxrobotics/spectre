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

#ifndef INCLUDE_SNOWFOX_HAL_SIFIVE_FE310_DELAY_H_
#define INCLUDE_SNOWFOX_HAL_SIFIVE_FE310_DELAY_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <snowfox/hal/interface/delay/Delay.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::hal::FE310
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Delay : public interface::Delay
{

public:

           Delay();
  virtual ~Delay();


  virtual void delay_ms(uint32_t const ms) override;
  virtual void delay_us(uint32_t const us) override;


private:

         void     delay_mcycle (uint64_t const num_mcycle);
  static uint64_t getCycleCount();

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::hal::FE310 */

#endif /* INCLUDE_SNOWFOX_HAL_SIFIVE_FE310_DELAY_H_ */
