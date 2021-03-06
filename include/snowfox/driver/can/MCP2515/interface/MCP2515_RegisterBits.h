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

#ifndef INCLUDE_SNOWFOX_DRIVER_CAN_MCP2515_INTERFACE_MCP2515_REGISTERBITS_H_
#define INCLUDE_SNOWFOX_DRIVER_CAN_MCP2515_INTERFACE_MCP2515_REGISTERBITS_H_

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::driver::can::MCP2515::interface
{

/**************************************************************************************
 * DEFINES
 **************************************************************************************/

/* REG_CANINTF ************************************************************************/
#define MCP2515_REG_CANINTF_MERRF_bm                        (1<<7)
#define MCP2515_REG_CANINTF_WAKIF_bm                        (1<<6)
#define MCP2515_REG_CANINTF_ERRIF_bm                        (1<<5)
#define MCP2515_REG_CANINTF_TX2IF_bm                        (1<<4)
#define MCP2515_REG_CANINTF_TX1IF_bm                        (1<<3)
#define MCP2515_REG_CANINTF_TX0IF_bm                        (1<<2)
#define MCP2515_REG_CANINTF_RX1IF_bm                        (1<<1)
#define MCP2515_REG_CANINTF_RX0IF_bm                        (1<<0)

/* REG_TXBnCTRL ***********************************************************************/
#define MCP2515_REG_TXBnCTRL_TXREQ_bm                       (1<<3)

/* REG_TXBnSIDL ***********************************************************************/
#define MCP2515_REG_TXBnSIDL_EXIDE_bm                       (1<<3)

/* REG_TXBnDLC ************************************************************************/
#define MCP2515_REG_TXBnDLC_RTR_bm                          (1<<6)

/* REG_RXBnSIDL ***********************************************************************/
#define MCP2515_REG_RXBnSIDL_SRR_bm                         (1<<4)
#define MCP2515_REG_RXBnSIDL_IDE_bm                         (1<<3)

/* REG_RXBnDLC ************************************************************************/
#define MCP2515_REG_RXBnDLC_RTR_bm                          (1<<6)

/* REG_CANCTRL ************************************************************************/
#define MCP2515_REG_CANCTRL_REQOP2_bm                       (1<<7)
#define MCP2515_REG_CANCTRL_REQOP1_bm                       (1<<6)
#define MCP2515_REG_CANCTRL_REQOP0_bm                       (1<<5)
#define MCP2515_REG_CANCTRL_ABAT_bm                         (1<<4)
#define MCP2515_REG_CANCTRL_OSM_bm                          (1<<3)
#define MCP2515_REG_CANCTRL_CLKEN_bm                        (1<<2)
#define MCP2515_REG_CANCTRL_CLKPRE1_bm                      (1<<1)
#define MCP2515_REG_CANCTRL_CLKPRE0_bm                      (1<<0)

/* REG_CANSTAT ************************************************************************/
#define MCP2515_REG_CANSTAT_OPMOD2_bm                       (1<<7)
#define MCP2515_REG_CANSTAT_OPMOD1_bm                       (1<<6)
#define MCP2515_REG_CANSTAT_OPMOD0_bm                       (1<<5)

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::driver::can::MCP2515::interface */

#endif /* INCLUDE_SNOWFOX_DRIVER_CAN_MCP2515_INTERFACE_MCP2515_REGISTERBITS_H_ */
