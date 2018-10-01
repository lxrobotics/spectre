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

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <spectre/driver/memory/AT45DBx/AT45DBx_Control.h>

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
 * DEFINE
 **************************************************************************************/

#define AT45DBx_CHIPERASE_1   0xC7
#define AT45DBx_CHIPERASE_2   0x94
#define AT45DBx_CHIPERASE_3   0x80
#define AT45DBx_CHIPERASE_4   0x9A

#define AT45DBx_PGERASE       0x81

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

AT45DBx_Control::AT45DBx_Control(interface::AT45DBx_Io & io)
: _io(io)
{

}

AT45DBx_Control::~AT45DBx_Control()
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void AT45DBx_Control::erase()
{
  uint8_t const buf_in[4] =
  {
    AT45DBx_CHIPERASE_1,
    AT45DBx_CHIPERASE_2,
    AT45DBx_CHIPERASE_3,
    AT45DBx_CHIPERASE_4
  };

  _io.exchange(buf_in, 4);
}

void AT45DBx_Control::erase(uint32_t const page, uint32_t const page_shift)
{
  uint32_t const offset = page << page_shift;

  uint8_t const buf_in[4] =
  {
    AT45DBx_PGERASE,
    static_cast<uint8_t>((offset >> 16) & 0xFF),
    static_cast<uint8_t>((offset >>  8) & 0xFF),
    static_cast<uint8_t>((offset >>  0) & 0xFF)
  };

  _io.exchange(buf_in, 4);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* AT45DBx */

} /* memory */

} /* driver */

} /* spectre */