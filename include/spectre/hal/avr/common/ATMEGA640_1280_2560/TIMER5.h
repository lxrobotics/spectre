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

#ifndef INCLUDE_SPECTRE_HAL_AVR_COMMON_ATMEGA640_1280_2560_TIMER5_H_
#define INCLUDE_SPECTRE_HAL_AVR_COMMON_ATMEGA640_1280_2560_TIMER5_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdint.h>

#include <spectre/hal/interface/timer/Timer.h>
#include <spectre/hal/interface/timer/TimerConfiguration.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace hal
{

namespace ATMEGA640_1280_2560
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class TIMER5 : public interface::Timer<uint16_t>,
               public interface::TimerConfiguration
{

public:

           TIMER5(volatile uint16_t * tcnt5,
                  volatile uint8_t  * tccr5b,
                  volatile uint16_t * ocr5a,
                  volatile uint16_t * ocr5b,
                  volatile uint16_t * ocr5c);
  virtual ~TIMER5();


  static uint8_t const COMPARE_A = 0;
  static uint8_t const COMPARE_B = 1;
  static uint8_t const COMPARE_C = 2;


  /* Timer Interface */

  virtual void     start             (                  ) override;
  virtual void     stop              (                  ) override;
  virtual void     set               (uint16_t const val) override;
  virtual uint16_t get               (                  ) override;

  virtual void     setCompareRegister(uint8_t const reg_sel, uint16_t const reg_val) override;


  /* Timer Configuration Interface */

  virtual void setPrescaler(uint32_t const prescaler) override;

private:

           uint32_t   _prescaler;

  volatile uint16_t * _TCNT5;
  volatile uint8_t  * _TCCR5B;
  volatile uint16_t * _OCR5A,
                    * _OCR5B,
                    * _OCR5C;


  void setPrescaler_TCCR5B(uint32_t const prescaler);

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* ATMEGA640_1280_2560 */

} /* hal */

} /* spectre */

#endif /* INCLUDE_SPECTRE_HAL_AVR_COMMON_ATMEGA640_1280_2560_TIMER5_H_ */
