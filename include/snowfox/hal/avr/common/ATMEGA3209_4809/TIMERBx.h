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

#ifndef INCLUDE_SNOWFOX_HAL_AVR_COMMON_ATMEGA3209_4809_TIMERBX_H_
#define INCLUDE_SNOWFOX_HAL_AVR_COMMON_ATMEGA3209_4809_TIMERBX_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdint.h>

#include <snowfox/hal/interface/timer/Timer.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::hal::ATMEGA3209_4809
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class TIMERBx : public interface::Timer<uint16_t>
{

public:

           TIMERBx(volatile uint8_t  * tcbx_ctrla,
                   volatile uint16_t * tcbx_cnt);
  virtual ~TIMERBx();


  /* Timer Interface */

  virtual void     start             (                  ) override;
  virtual void     stop              (                  ) override;
  virtual void     set               (uint16_t const val) override;
  virtual uint16_t get               (                  ) override;

  virtual void     setCompareRegister(uint8_t const reg_sel, uint16_t const reg_val) override;


  /* Timer Configuration Interface */

  virtual void setPrescaler(uint32_t const prescaler) override;


private:

  volatile uint8_t  * _TCBx_CTRLA;
  volatile uint16_t * _TCBx_CNT;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::hal::ATMEGA3209_4809 */

#endif /* INCLUDE_SNOWFOX_HAL_AVR_COMMON_ATMEGA3209_4809_TIMERBX_H_ */
