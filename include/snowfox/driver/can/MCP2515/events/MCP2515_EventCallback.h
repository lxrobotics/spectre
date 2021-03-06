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

#ifndef INCLUDE_SNOWFOX_DRIVER_CAN_MCP2515_INTERFACE_MCP2515_CALLBACK_H_
#define INCLUDE_SNOWFOX_DRIVER_CAN_MCP2515_INTERFACE_MCP2515_CALLBACK_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <snowfox/hal/interface/extint/ExternalInterruptCallback.h>

#include <snowfox/driver/can/MCP2515/interface/events/MCP2515_onWakeup.h>
#include <snowfox/driver/can/MCP2515/interface/events/MCP2515_onMessageError.h>
#include <snowfox/driver/can/MCP2515/interface/events/MCP2515_onReceiveBufferFull.h>
#include <snowfox/driver/can/MCP2515/interface/events/MCP2515_onTransmitBufferEmpty.h>

#include <snowfox/driver/can/MCP2515/interface/control/MCP2515_EventControl.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::driver::can::MCP2515
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class MCP2515_EventCallback final : public hal::interface::ExternalInterruptCallback
{

public:

           MCP2515_EventCallback(interface::MCP2515_EventControl          & event_ctrl,
                                 interface::MCP2515_onMessageError        & on_message_error,
                                 interface::MCP2515_onWakeup              & on_wakeup,
                                 interface::MCP2515_onTransmitBufferEmpty & on_transmit_buffer_2_empty,
                                 interface::MCP2515_onTransmitBufferEmpty & on_transmit_buffer_1_empty,
                                 interface::MCP2515_onTransmitBufferEmpty & on_transmit_buffer_0_empty,
                                 interface::MCP2515_onReceiveBufferFull   & on_receive_buffer_1_full,
                                 interface::MCP2515_onReceiveBufferFull   & on_receive_buffer_0_full);
  virtual ~MCP2515_EventCallback();


  virtual void onExternalInterrupt() override;


private:

  interface::MCP2515_EventControl          & _event_ctrl;
  interface::MCP2515_onMessageError        & _on_message_error;
  interface::MCP2515_onWakeup              & _on_wakeup;
  interface::MCP2515_onTransmitBufferEmpty & _on_transmit_buffer_2_empty;
  interface::MCP2515_onTransmitBufferEmpty & _on_transmit_buffer_1_empty;
  interface::MCP2515_onTransmitBufferEmpty & _on_transmit_buffer_0_empty;
  interface::MCP2515_onReceiveBufferFull   & _on_receive_buffer_1_full;
  interface::MCP2515_onReceiveBufferFull   & _on_receive_buffer_0_full;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::driver::can::MCP2515 */

#endif /* INCLUDE_SNOWFOX_DRIVER_CAN_MCP2515_INTERFACE_MCP2515_CALLBACK_H_ */
