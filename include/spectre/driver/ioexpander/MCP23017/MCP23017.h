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

#ifndef INCLUDE_SPECTRE_DRIVER_IOEXPANDER_MCP23017_MCP23017_H_
#define INCLUDE_SPECTRE_DRIVER_IOEXPANDER_MCP23017_MCP23017_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <spectre/driver/interface/Driver.h>

#include <spectre/driver/ioexpander/MCP23017/interface/control/MCP23017_Control.h>
#include <spectre/driver/ioexpander/MCP23017/interface/config/MCP23017_Configuration.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace driver
{

namespace ioexpander
{

namespace MCP23017
{

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef struct
{
  interface::Port       port;
  interface::Pin        pin;
  interface::PullUpMode pull_up_mode;
} ConfigInputParameter;

typedef struct
{
  interface::Port       port;
  interface::Pin        pin;
  interface::PullUpMode pull_up_mode;
} ConfigOutputParameter;

typedef struct
{
  interface::Port port;
  interface::Pin  pin;
  bool            set;
} SetOutputPinParam;

typedef struct
{
  interface::Port port;
  interface::Pin  pin;
  bool            is_set;
} GetInputPinParam;

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static uint32_t constexpr IOCTL_CONFIG_INPUT   = 0; /* Arg: ConfigInputParameter  *  */
static uint32_t constexpr IOCTL_CONFIG_OUTPUT  = 1; /* Arg: ConfigOutputParameter *  */
static uint32_t constexpr IOCTL_SET_OUTPUT_PIN = 2; /* Arg: SetOutputPinParam     *  */
static uint32_t constexpr IOCTL_GET_INPUT_PIN = 3;  /* Arg: GetInputPinParam      *  */

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class MCP23017 : public driver::interface::Driver
{

public:

           MCP23017(interface::MCP23017_Configuration & config,
                    interface::MCP23017_Control       & control);
  virtual ~MCP23017();


  virtual bool    open (                                                  ) override;
  virtual ssize_t read (uint8_t        * buffer, ssize_t const   num_bytes) override;
  virtual ssize_t write(uint8_t  const * buffer, ssize_t const   num_bytes) override;
  virtual bool    ioctl(uint32_t const   cmd,    void          * arg      ) override;
  virtual void    close(                                                  ) override;


private:

  interface::MCP23017_Configuration & _config;
  interface::MCP23017_Control       & _control;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* MCP23017 */

} /* ioexpander */

} /* driver */

} /* spectre */

#endif /* INCLUDE_SPECTRE_DRIVER_IOEXPANDER_MCP23017_MCP23017_H_ */