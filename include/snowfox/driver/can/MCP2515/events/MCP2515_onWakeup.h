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

#ifndef INCLUDE_SNOWFOX_DRIVER_CAN_MCP2515_MCP2515_ONWAKEUP_H_
#define INCLUDE_SNOWFOX_DRIVER_CAN_MCP2515_MCP2515_ONWAKEUP_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <snowfox/driver/can/MCP2515/interface/events/MCP2515_onWakeup.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::driver::can::MCP2515
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class MCP2515_onWakeup final : public interface::MCP2515_onWakeup
{

public:

           MCP2515_onWakeup();
  virtual ~MCP2515_onWakeup();


  virtual void onWakeup() override;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::driver::can::MCP2515 */

#endif /* INCLUDE_SNOWFOX_DRIVER_CAN_MCP2515_MCP2515_ONWAKEUP_H_ */
