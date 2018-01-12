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

#ifndef INCLUDE_SPECTRE_DRIVER_GLCD_RA6963_RA6963_DATA_H_
#define INCLUDE_SPECTRE_DRIVER_GLCD_RA6963_RA6963_DATA_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <spectre/driver/glcd/RA6963/interface/RA6963_Data_Interface.h>

#include <spectre/driver/glcd/RA6963/interface/RA6963_IO_Interface.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace driver
{

namespace glcd
{

namespace RA6963
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class RA6963_Data : public RA6963_Data_Interface
{

public:

           RA6963_Data(RA6963_IO_Interface & io);
  virtual ~RA6963_Data();


  virtual uint8_t readData    (OperationMode const mode                        ) override;
  virtual void    writeData   (OperationMode const mode, uint8_t const data_val) override;
  virtual void    writeCommand(OperationMode const mode, uint8_t const cmd_val ) override;

private:

  RA6963_IO_Interface & _io;

  void waitForReady     (OperationMode const mode                      ) const;
  bool isReady          (OperationMode const mode, uint8_t const status) const;
  bool isReadyNormalMode(                          uint8_t const status) const;
  bool isReadyAutoMode  (                          uint8_t const status) const;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* RA6963 */

} /* glcd */

} /* driver */

} /* spectre */

#endif /* INCLUDE_SPECTRE_DRIVER_GLCD_RA6963_RA6963_DATA_H_ */