/**
 * Spectre is a modular RTOS with extensive IO support.
 * Copyright (C) 2017 Alexander Entinger / LXRobotics GmbH
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
 * INCLUDES
 **************************************************************************************/

#include <spectre/driver/can/MCP2515/MCP2515_EventCallback.h>

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

MCP2515_EventCallback::MCP2515_EventCallback(interface::MCP2515_InterruptControl      & int_ctrl,
                                             interface::MCP2515_onMessageError        & on_message_error,
                                             interface::MCP2515_onWakeup              & on_wakeup,
                                             interface::MCP2515_onTransmitBufferEmpty & on_transmit_buffer_2_empty,
                                             interface::MCP2515_onTransmitBufferEmpty & on_transmit_buffer_1_empty,
                                             interface::MCP2515_onTransmitBufferEmpty & on_transmit_buffer_0_empty,
                                             interface::MCP2515_onReceiveBufferFull   & on_receive_buffer_1_full,
                                             interface::MCP2515_onReceiveBufferFull   & on_receive_buffer_0_full)
: _int_ctrl                   (int_ctrl                  ),
  _on_message_error           (on_message_error          ),
  _on_wakeup                  (on_wakeup                 ),
  _on_transmit_buffer_2_empty (on_transmit_buffer_2_empty),
  _on_transmit_buffer_1_empty (on_transmit_buffer_1_empty),
  _on_transmit_buffer_0_empty (on_transmit_buffer_0_empty),
  _on_receive_buffer_1_full   (on_receive_buffer_1_full  ),
  _on_receive_buffer_0_full   (on_receive_buffer_0_full  )
{

}

MCP2515_EventCallback::~MCP2515_EventCallback()
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void MCP2515_EventCallback::onExternalEventCallback()
{
  uint8_t int_flags = 0;

  _int_ctrl.getIntFlags(&int_flags);

  /* MESSAGE ERROR ********************************************************************/
  if(interface::MCP2515_InterruptControl::isMessageError(int_flags))
  {
    _on_message_error.onMessageError();
    _int_ctrl.clearIntFlag(interface::InterruptFlag::MessageError);
  }
  /* WAKEUP ***************************************************************************/
  if(interface::MCP2515_InterruptControl::isWakeup(int_flags))
  {
    _on_wakeup.onWakeup();
    _int_ctrl.clearIntFlag(interface::InterruptFlag::Wakeup);
  }
  /* GENERAL ERROR ********************************************************************/
  if(interface::MCP2515_InterruptControl::isGeneralError(int_flags))
  {
    /* No callback yet */
    _int_ctrl.clearIntFlag(interface::InterruptFlag::GeneralError);
  }
  /* TRANSMIT BUFFER 2 EMPTY **********************************************************/
  if(interface::MCP2515_InterruptControl::isTxBuf2Empty(int_flags))
  {
    _on_transmit_buffer_2_empty.onTransmitBufferEmpty();
    _int_ctrl.clearIntFlag(interface::InterruptFlag::TxBuf2Empty);
  }
  /* TRANSMIT BUFFER 1 EMPTY **********************************************************/
  if(interface::MCP2515_InterruptControl::isTxBuf1Empty(int_flags))
  {
    _on_transmit_buffer_1_empty.onTransmitBufferEmpty();
    _int_ctrl.clearIntFlag(interface::InterruptFlag::TxBuf1Empty);
  }
  /* TRANSMIT BUFFER 0 EMPTY **********************************************************/
  if(interface::MCP2515_InterruptControl::isTxBuf0Empty(int_flags))
  {
    _on_transmit_buffer_0_empty.onTransmitBufferEmpty();
    _int_ctrl.clearIntFlag(interface::InterruptFlag::TxBuf0Empty);
  }
  /* RECEIVE BUFFER 1 FULL ************************************************************/
  if(interface::MCP2515_InterruptControl::isRxBuf1Full(int_flags))
  {
    _on_receive_buffer_1_full.onReceiveBufferFull();
    _int_ctrl.clearIntFlag(interface::InterruptFlag::RxBuf1Full);
  }
  /* RECEIVE BUFFER 0 FULL ************************************************************/
  if(interface::MCP2515_InterruptControl::isRxBuf0Full(int_flags))
  {
    _on_receive_buffer_0_full.onReceiveBufferFull();
    _int_ctrl.clearIntFlag(interface::InterruptFlag::RxBuf0Full);
  }
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* MCP2515 */

} /* can */

} /* driver */

} /* spectre */
