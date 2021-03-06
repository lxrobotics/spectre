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

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <snowfox/driver/sensor/INA220/INA220_Debug.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::driver::sensor::INA220
{

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

FLASH_DECLARE(static char const CONFIG     [] = "CONFIG      = ");
FLASH_DECLARE(static char const V_SHUNT    [] = "V_SHUNT     = ");
FLASH_DECLARE(static char const V_BUS      [] = "V_BUS       = ");
FLASH_DECLARE(static char const POWER      [] = "POWER       = ");
FLASH_DECLARE(static char const CURRENT    [] = "CURRENT     = ");
FLASH_DECLARE(static char const CALIBRATION[] = "CALIBRATION = ");

/**************************************************************************************
 * PUBLIC FUNCTIONS
 **************************************************************************************/

void INA220_Debug::debug_dumpAllRegs(trace::Trace & trace, hal::interface::Flash & flash, interface::INA220_Io & io)
{
  debug_dumpSingleReg(trace, flash, io, CONFIG     , interface::Register::CONFIG     );
  debug_dumpSingleReg(trace, flash, io, V_SHUNT    , interface::Register::V_SHUNT    );
  debug_dumpSingleReg(trace, flash, io, V_BUS      , interface::Register::V_BUS      );
  debug_dumpSingleReg(trace, flash, io, POWER      , interface::Register::POWER      );
  debug_dumpSingleReg(trace, flash, io, CURRENT    , interface::Register::CURRENT    );
  debug_dumpSingleReg(trace, flash, io, CALIBRATION, interface::Register::CALIBRATION);
}

/**************************************************************************************
 * PRIVATE FUNCTIONS
 **************************************************************************************/

void INA220_Debug::debug_dumpSingleReg(trace::Trace & trace, hal::interface::Flash & flash, interface::INA220_Io & io, char const * msg, interface::Register const reg)
{
  char     msg_ram[32];
  uint16_t reg_content = 0;

  flash.readStringFromFlash(msg_ram, msg);
  io.readRegister(reg, &reg_content);

  trace.println(trace::Level::Debug, "%s%04X", msg_ram, reg_content);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::driver::sensor::INA220 */
