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

#ifndef INCLUDE_SNOWFOX_COMSTACK_CANOPEN_INTERFACE_CAN_ONTRANSMITCALLBACK_H_
#define INCLUDE_SNOWFOX_COMSTACK_CANOPEN_INTERFACE_CAN_ONTRANSMITCALLBACK_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <snowfox/util/type/CanFrame.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::comstack::canopen::interface
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class CanOpen_onTransmitCallback
{

public:

  virtual ~CanOpen_onTransmitCallback() { }


  virtual void onTransmit(util::type::CanFrame const & frame) = 0;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::comstack::canopen::interface */

#endif /* INCLUDE_SNOWFOX_COMSTACK_CANOPEN_INTERFACE_CAN_ONTRANSMITCALLBACK_H_ */
