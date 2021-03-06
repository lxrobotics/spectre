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

#ifndef INCLUDE_SNOWFOX_HAL_SIFIVE_FE310_UARTX_H_
#define INCLUDE_SNOWFOX_HAL_SIFIVE_FE310_UARTX_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <snowfox/hal/interface/uart/Uart.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::hal::FE310
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class UARTx : public interface::Uart
{

public:


           UARTx(volatile uint32_t * uartx_txdata,
                 volatile uint32_t * uartx_rxdata,
                 volatile uint32_t * uartx_txctrl,
                 volatile uint32_t * uartx_rxctrl,
                 volatile uint32_t * uartx_div,
                 uint32_t const      tlclk_Hz);
  virtual ~UARTx();


  /* UART Control Interface */

  virtual void transmit         (uint8_t  const    data) override;
  virtual void receive          (uint8_t         & data) override;
  virtual void enableTx         (                      ) override;
  virtual void enableRx         (                      ) override;
  virtual void disableTx        (                      ) override;


  /* UART Configuration Interface */

  virtual bool setBaudRate      (interface::UartBaudRate const   baud_rate) override;
  virtual bool setParity        (interface::UartParity   const   parity   ) override;
  virtual bool setStopBit       (interface::UartStopBit  const   stop_bit ) override;


  /* UART Assembly */

  virtual void register_onRxDoneCallback(interface::UART_onRxDoneCallback * on_rx_done_callback) override;
  virtual void register_onTxDoneCallback(interface::UART_onTxDoneCallback * on_tx_done_callback) override;

private:

  volatile uint32_t * _uartx_txdata,
                    * _uartx_rxdata,
                    * _uartx_txctrl,
                    * _uartx_rxctrl,
                    * _uartx_div;
  uint32_t const      _tlclk_Hz;

  interface::UART_onRxDoneCallback       * _on_rx_done_callback;
  interface::UART_onTxDoneCallback       * _on_tx_done_callback;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::hal::FE310 */

#endif /* INCLUDE_SNOWFOX_HAL_SIFIVE_FE310_UARTX_H_ */
