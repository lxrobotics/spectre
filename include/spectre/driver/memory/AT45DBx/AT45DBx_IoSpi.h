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

#ifndef INCLUDE_SPECTRE_DRIVER_MEMORY_AT45DBX_AT45DBX_IOSPI_H_
#define INCLUDE_SPECTRE_DRIVER_MEMORY_AT45DBX_AT45DBX_IOSPI_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <spectre/driver/memory/AT45DBx/interface/AT45DBx_Io.h>

#include <spectre/hal/interface/gpio/DigitalOutPin.h>
#include <spectre/hal/interface/spi/SpiMasterControl.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace driver
{

namespace memory
{

namespace AT45DBx
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class AT45DBx_IoSpi : public interface::AT45DBx_Io
{

public:

           AT45DBx_IoSpi(hal::interface::SpiMasterControl & spi_master, hal::interface::DigitalOutPin & cs);
  virtual ~AT45DBx_IoSpi();


  virtual void exchange(uint8_t const * buf_in, uint16_t const buf_in_size                ) override;
  virtual void exchange(uint8_t const * buf_in, uint8_t * buf_out, uint16_t const buf_size) override;

private:

  hal::interface::SpiMasterControl & _spi_master;
  hal::interface::DigitalOutPin    & _cs;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* AT45DBx */

} /* memory */

} /* driver */

} /* spectre */

#endif /* INCLUDE_SPECTRE_DRIVER_MEMORY_AT45DBX_AT45DBX_IOSPI_H_ */