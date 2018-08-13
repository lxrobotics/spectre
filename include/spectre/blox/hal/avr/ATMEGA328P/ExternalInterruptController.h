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

#ifndef INCLUDE_SPECTRE_BLOX_HAL_AVR_ATMEGA328P_EXTERNALINTERRUPTCONTROLLER_H_
#define INCLUDE_SPECTRE_BLOX_HAL_AVR_ATMEGA328P_EXTERNALINTERRUPTCONTROLLER_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <spectre/hal/avr/ATMEGA328P/ExternalInterruptController.h>

#include <spectre/hal/interface/interrupt/InterruptController.h>

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
 * CTOR/DTOR
 **************************************************************************************/

class ExternalInterruptController
{

public:

  ExternalInterruptController(volatile uint8_t                    * eicra,
                              volatile uint8_t                    * pcmsk0,
                              volatile uint8_t                    * pcmsk1,
                              volatile uint8_t                    * pcmsk2,
                              hal::interface::InterruptController & int_ctrl);


  hal::ATMEGA328P::ExternalInterruptController & operator () () { return _ext_int_ctrl; }


private:

  hal::ATMEGA328P::ExternalInterruptController               _ext_int_ctrl;
  hal::ATMEGA328P::EINT0_ExternalInterruptEventCallback      _eint0_event_callback;
  hal::ATMEGA328P::EINT1_ExternalInterruptEventCallback      _eint1_event_callback;
  hal::ATMEGA328P::PinChange0_ExternalInterruptEventCallback _pcint0_event_callback;
  hal::ATMEGA328P::PinChange1_ExternalInterruptEventCallback _pcint1_event_callback;
  hal::ATMEGA328P::PinChange2_ExternalInterruptEventCallback _pcint2_event_callback;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* ATMEGA328P */

} /* blox */

} /* spectre */

#endif /* INCLUDE_SPECTRE_BLOX_HAL_AVR_ATMEGA328P_EXTERNALINTERRUPTCONTROLLER_H_ */