/**
 * Snowfox is a modular RTOS with extensive IO support.
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

#ifndef INCLUDE_SNOWFOX_DRIVER_MEMORY_N25Q256A_N25Q256A_IOSPI_H_
#define INCLUDE_SNOWFOX_DRIVER_MEMORY_N25Q256A_N25Q256A_IOSPI_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <snowfox/driver/memory/N25Q256A/interface/N25Q256A_Io.h>

#include <snowfox/hal/interface/gpio/DigitalOutPin.h>
#include <snowfox/hal/interface/spi/SpiMasterControl.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox
{

namespace driver
{

namespace memory
{

namespace N25Q256A
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class N25Q256A_IoSpi : public interface::N25Q256A_Io
{

public:

           N25Q256A_IoSpi(hal::interface::SpiMasterControl & spi_master, hal::interface::DigitalOutPin & cs);
  virtual ~N25Q256A_IoSpi();


  virtual bool transfer(interface::Command  const   cmd,
                        uint8_t             const * tx_buf,
                        uint32_t            const   tx_num_bytes,
                        uint8_t             const   tx_fill_data,
                        uint8_t                   * rx_buf,
                        uint32_t            const   rx_num_bytes,
                        uint32_t            const   rx_start_pos) override;

  virtual bool transfer(interface::Command  const   cmd,
                        uint8_t             const * tx_buf_1,
                        uint32_t            const   tx_num_bytes_1,
                        uint8_t             const * tx_buf_2,
                        uint32_t            const   tx_num_bytes_2) = 0;



  virtual bool readStatusReg            (uint8_t * status_reg)                                                        override;
  virtual bool readNonVolatileConfigReg (uint16_t * non_volatile_config_reg)                                          override;
  virtual bool writeNonVolatileConfigReg(uint16_t const non_volatile_config_reg)                                      override;
  virtual bool triggerSubsectorErase    (uint32_t const subsector_num)                                                override;

private:

  hal::interface::SpiMasterControl & _spi_master;
  hal::interface::DigitalOutPin    & _cs;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* N25Q256A */

} /* memory */

} /* driver */

} /* snowfox */

#endif /* INCLUDE_SNOWFOX_DRIVER_MEMORY_N25Q256A_N25Q256A_IOSPI_H_ */