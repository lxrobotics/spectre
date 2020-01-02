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

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <snowfox/hal/riscv64/FE310/util/InterruptUtil.h>

#include <stdint.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox
{

namespace hal
{

namespace FE310
{

/**************************************************************************************
 * DEFINE
 **************************************************************************************/

#define REG_MSTATUS_MACHINE_INTERRUPT_ENABLE_bm (1<<3)

/**************************************************************************************
 * PUBLIC FUNCTIONS
 **************************************************************************************/

void enableGlobalInterrupt()
{
  uintptr_t mstatus;
  asm volatile ("csrrs %0, mstatus, %1" : "=r"(mstatus) : "r"(REG_MSTATUS_MACHINE_INTERRUPT_ENABLE_bm));
}

void disableGlobalInterrupt()
{
  uintptr_t mstatus;
  asm volatile ("csrrc %0, mstatus, %1" : "=r"(mstatus) : "r"(REG_MSTATUS_MACHINE_INTERRUPT_ENABLE_bm));
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* FE310 */

} /* hal */

} /* snowfox */