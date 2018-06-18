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

#ifndef INCLUDE_SPECTRE_DRIVER_CAN_MCP2515_MCP2515_ONTRANSMITBUFFEREMPTY_H_
#define INCLUDE_SPECTRE_DRIVER_CAN_MCP2515_MCP2515_ONTRANSMITBUFFEREMPTY_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <spectre/driver/can/MCP2515/interface/events/MCP2515_onTransmitBufferEmpty.h>

#include <spectre/driver/can/interface/CanFrameBuffer.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace driver
{

namespace can
{

namespace MCP2515
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class MCP2515_onTransmitBufferEmpty : public interface::MCP2515_onTransmitBufferEmpty
{

public:

           MCP2515_onTransmitBufferEmpty(can::interface::CanFrameBuffer     & can_tx_buf,
                                         interface::MCP2515_TransmitControl & ctrl);
  virtual ~MCP2515_onTransmitBufferEmpty();


  virtual void onTransmitBufferEmpty(interface::TransmitBufferSelect const tx_buf_sel) override;


private:

  can::interface::CanFrameBuffer     & _can_tx_buf;
  interface::MCP2515_TransmitControl & _ctrl;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* MCP2515 */

} /* can */

} /* driver */

} /* spectre */

#endif /* INCLUDE_SPECTRE_DRIVER_CAN_MCP2515_MCP2515_ONTRANSMITBUFFEREMPTY_H_ */
