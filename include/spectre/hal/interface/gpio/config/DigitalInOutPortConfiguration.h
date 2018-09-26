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

#ifndef INCLUDE_SPECTRE_HAL_INTERFACE_GPIO_DIGITALINOUTPORTCONFIGURATION_H_
#define INCLUDE_SPECTRE_HAL_INTERFACE_GPIO_DIGITALINOUTPORTCONFIGURATION_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <spectre/hal/interface/gpio/config/PullUpMode.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace hal
{

namespace interface
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class DigitalInOutPortConfiguration
{

public:

           DigitalInOutPortConfiguration() { }
  virtual ~DigitalInOutPortConfiguration() { }


  typedef enum
  {
    INPUT,
    OUTPUT
  } ModeSelect;

  virtual void setMode(ModeSelect const mode, PullUpMode const pullup_mode = PullUpMode::NONE) = 0;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* interface*/

} /* hal */

} /* spectre */

#endif /* INCLUDE_SPECTRE_HAL_INTERFACE_GPIO_DIGITALINOUTPORTCONFIGURATION_H_ */