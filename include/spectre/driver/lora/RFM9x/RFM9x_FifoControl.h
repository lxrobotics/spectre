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

#ifndef INCLUDE_SPECTRE_DRIVER_LORA_RFM9X_RFM9X_FIFOCONTROL_H_
#define INCLUDE_SPECTRE_DRIVER_LORA_RFM9X_RFM9X_FIFOCONTROL_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <spectre/driver/lora/RFM9x/interface/RFM9x_FifoControl.h>

#include <spectre/driver/lora/RFM9x/interface/RFM9x_Io.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace driver
{

namespace lora
{

namespace RFM9x
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class RFM9x_FifoControl : public interface::RFM9x_FifoControl
{

public:

           RFM9x_FifoControl(interface::RFM9x_Io & io);
  virtual ~RFM9x_FifoControl();


  virtual bool     setTxFifoSize (uint16_t const   tx_fifo_size                  ) override;
  virtual bool     setRxFifoSize (uint16_t const   rx_fifo_size                  ) override;
  virtual uint16_t writeToTxFifo (uint8_t  const * data, uint16_t const num_bytes) override;
  virtual uint16_t readFromRxFifo(uint8_t        * data, uint16_t const num_bytes) override;

private:

  interface::RFM9x_Io & _io;
  uint16_t              _tx_fifo_size,
                        _rx_fifo_size;


  uint8_t calcTxFifoBaseAddress();
  uint8_t calcRxFifoBaseAddress();
  void    setTxFifoBaseAddress (uint8_t const tx_base_addr);
  void    setRxFifoBaseAddress (uint8_t const rx_base_addr);

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* RFM9x */

} /* lora */

} /* driver */

} /* spectre */

#endif /* INCLUDE_SPECTRE_DRIVER_LORA_RFM9X_RFM9X_FIFOCONTROL_H_ */