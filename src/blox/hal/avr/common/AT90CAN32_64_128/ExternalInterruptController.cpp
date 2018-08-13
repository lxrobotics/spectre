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

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <spectre/blox/hal/avr/common/AT90CAN32_64_128/ExternalInterruptController.h>

#include <spectre/hal/avr/common/AT90CAN32_64_128/InterruptController.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace blox
{

namespace AT90CAN32_64_128
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ExternalInterruptController::ExternalInterruptController(volatile uint8_t                    * eicra,
                                                         volatile uint8_t                    * eicrb,
                                                         hal::interface::InterruptController & int_ctrl)
: _ext_int_ctrl         (eicra, eicrb, int_ctrl),
  _eint0_event_callback (_ext_int_ctrl),
  _eint1_event_callback (_ext_int_ctrl),
  _eint2_event_callback (_ext_int_ctrl),
  _eint3_event_callback (_ext_int_ctrl),
  _eint4_event_callback (_ext_int_ctrl),
  _eint5_event_callback (_ext_int_ctrl),
  _eint6_event_callback (_ext_int_ctrl),
  _eint7_event_callback (_ext_int_ctrl)
{
  int_ctrl.registerInterruptCallback(hal::AT90CAN32_64_128::toIsrNum(hal::AT90CAN32_64_128::InterruptServiceRoutine::EXTERNAL_INT0), &_eint0_event_callback );
  int_ctrl.registerInterruptCallback(hal::AT90CAN32_64_128::toIsrNum(hal::AT90CAN32_64_128::InterruptServiceRoutine::EXTERNAL_INT1), &_eint1_event_callback );
  int_ctrl.registerInterruptCallback(hal::AT90CAN32_64_128::toIsrNum(hal::AT90CAN32_64_128::InterruptServiceRoutine::EXTERNAL_INT2), &_eint2_event_callback );
  int_ctrl.registerInterruptCallback(hal::AT90CAN32_64_128::toIsrNum(hal::AT90CAN32_64_128::InterruptServiceRoutine::EXTERNAL_INT3), &_eint3_event_callback );
  int_ctrl.registerInterruptCallback(hal::AT90CAN32_64_128::toIsrNum(hal::AT90CAN32_64_128::InterruptServiceRoutine::EXTERNAL_INT4), &_eint4_event_callback );
  int_ctrl.registerInterruptCallback(hal::AT90CAN32_64_128::toIsrNum(hal::AT90CAN32_64_128::InterruptServiceRoutine::EXTERNAL_INT5), &_eint5_event_callback );
  int_ctrl.registerInterruptCallback(hal::AT90CAN32_64_128::toIsrNum(hal::AT90CAN32_64_128::InterruptServiceRoutine::EXTERNAL_INT6), &_eint6_event_callback );
  int_ctrl.registerInterruptCallback(hal::AT90CAN32_64_128::toIsrNum(hal::AT90CAN32_64_128::InterruptServiceRoutine::EXTERNAL_INT7), &_eint7_event_callback );
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* AT90CAN32_64_128 */

} /* blox */

} /* spectre */