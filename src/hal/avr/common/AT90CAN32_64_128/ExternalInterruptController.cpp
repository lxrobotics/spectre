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

#include <spectre/hal/avr/common/AT90CAN32_64_128/ExternalInterruptController.h>

#include <spectre/hal/avr/common/AT90CAN32_64_128/InterruptController.h>
#include <spectre/hal/avr/common/ATxxxx/util/ExternalInterruptTriggerModeConfig.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace hal
{

namespace AT90CAN32_64_128
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ExternalInterruptController::ExternalInterruptController(volatile uint8_t            * eicra,
                                                         volatile uint8_t            * eicrb,
                                                         interface::InterruptControl & int_ctrl)
: _EICRA   (eicra   ),
  _EICRB   (eicrb   ),
  _int_ctrl(int_ctrl)
{

}

ExternalInterruptController::~ExternalInterruptController()
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void ExternalInterruptController::setTriggerMode(uint8_t const ext_int_num, interface::TriggerMode const trigger_mode)
{
  switch(ext_int_num)
  {
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT0): ATxxxx::ExternalInterruptTriggerModeConfig::setTriggerModeEint0(trigger_mode, _EICRA); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT1): ATxxxx::ExternalInterruptTriggerModeConfig::setTriggerModeEint1(trigger_mode, _EICRA); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT2): ATxxxx::ExternalInterruptTriggerModeConfig::setTriggerModeEint2(trigger_mode, _EICRA); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT3): ATxxxx::ExternalInterruptTriggerModeConfig::setTriggerModeEint3(trigger_mode, _EICRA); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT4): ATxxxx::ExternalInterruptTriggerModeConfig::setTriggerModeEint4(trigger_mode, _EICRB); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT5): ATxxxx::ExternalInterruptTriggerModeConfig::setTriggerModeEint5(trigger_mode, _EICRB); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT6): ATxxxx::ExternalInterruptTriggerModeConfig::setTriggerModeEint6(trigger_mode, _EICRB); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT7): ATxxxx::ExternalInterruptTriggerModeConfig::setTriggerModeEint7(trigger_mode, _EICRB); break;
  default                                           : /* PCINT trigger mode is Any */                                                        break;
  }
}

void ExternalInterruptController::enable(uint8_t const ext_int_num)
{
  switch(ext_int_num)
  {
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT0): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT0)); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT1): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT1)); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT2): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT2)); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT3): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT3)); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT4): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT4)); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT5): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT5)); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT6): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT6)); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT7): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT7)); break;
  }
}

void ExternalInterruptController::disable(uint8_t const ext_int_num)
{
  switch(ext_int_num)
  {
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT0): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT0)); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT1): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT1)); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT2): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT2)); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT3): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT3)); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT4): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT4)); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT5): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT5)); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT6): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT6)); break;
  case toExtIntNum(ExternalInterrupt::EXTERNAL_INT7): _int_ctrl.enableInterrupt(toIntNum(Interrupt::EXTERNAL_INT7)); break;
  }
}

void ExternalInterruptController::registerExternalInterruptCallback(uint8_t const ext_int_num, interface::ExternalInterruptCallback * external_interrupt_callback)
{
  if(ext_int_num < NUM_EXTERNAL_INTERRUPTS)
  {
    _external_interrupt_callback[ext_int_num] = external_interrupt_callback;
  }
}

void ExternalInterruptController::ISR_onEint0Event()
{
  if(_external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT0)])
  {
    _external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT0)]->onExternalEventCallback();
  }
}

void ExternalInterruptController::ISR_onEint1Event()
{
  if(_external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT1)])
  {
    _external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT1)]->onExternalEventCallback();
  }
}

void ExternalInterruptController::ISR_onEint2Event()
{
  if(_external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT2)])
  {
    _external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT2)]->onExternalEventCallback();
  }
}

void ExternalInterruptController::ISR_onEint3Event()
{
  if(_external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT3)])
  {
    _external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT3)]->onExternalEventCallback();
  }
}

void ExternalInterruptController::ISR_onEint4Event()
{
  if(_external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT4)])
  {
    _external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT4)]->onExternalEventCallback();
  }
}

void ExternalInterruptController::ISR_onEint5Event()
{
  if(_external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT5)])
  {
    _external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT5)]->onExternalEventCallback();
  }
}

void ExternalInterruptController::ISR_onEint6Event()
{
  if(_external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT6)])
  {
    _external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT6)]->onExternalEventCallback();
  }
}

void ExternalInterruptController::ISR_onEint7Event()
{
  if(_external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT7)])
  {
    _external_interrupt_callback[toExtIntNum(ExternalInterrupt::EXTERNAL_INT7)]->onExternalEventCallback();
  }
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* AT90CAN32_64_128 */

} /* hal */

} /* spectre */