/**
 * Spectre is a modular RTOS with extensive IO support.
 * Copyright (C) 2017 - 2019 Alexander Entinger / LXRobotics GmbH
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

#include <spectre/driver/can/MCP2515/events/MCP2515_onTransmitBufferEmpty.h>

#include <spectre/driver/can/MCP2515/interface/MCP2515_RegisterBits.h>

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
 * CTOR/DTOR
 **************************************************************************************/

MCP2515_onTransmitBufferEmpty::MCP2515_onTransmitBufferEmpty(can::interface::CanFrameBuffer & can_tx_buf, interface::MCP2515_TransmitControl & ctrl)
: _can_tx_buf(can_tx_buf),
  _ctrl      (ctrl      )
{

}

MCP2515_onTransmitBufferEmpty::~MCP2515_onTransmitBufferEmpty()
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void MCP2515_onTransmitBufferEmpty::onTransmitBufferEmpty(interface::TransmitBufferSelect const tx_buf_sel)
{
  if(!_can_tx_buf.isEmpty())
  {
    util::type::CanFrame frame;
    _can_tx_buf.pop(&frame);

    _ctrl.writeToTransmitBuffer(tx_buf_sel, frame);
    _ctrl.requestTransmit      (tx_buf_sel);
  }
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* MCP2515 */

} /* can */

} /* driver */

} /* spectre */
