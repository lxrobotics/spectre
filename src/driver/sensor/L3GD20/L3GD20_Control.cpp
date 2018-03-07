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

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <spectre/driver/sensor/L3GD20/L3GD20_Control.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace driver
{

namespace sensor
{

namespace L3GD20
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

L3GD20_Control::L3GD20_Control(interface::L3GD20_Io & io)
: _io(io)
{
  enablePower          ();
  disableAllAxis       ();
  enableBlockDataUpdate();
}

L3GD20_Control::~L3GD20_Control()
{

}

/**************************************************************************************
 * PUBLIC FUNCTIONS
 **************************************************************************************/

bool L3GD20_Control::setOutputDataRateAndBandwith(interface::OutputDataRateAndBandwithSelect const sel)
{
  uint8_t ctrl_reg1_content = 0;

  if(!_io.readRegister(interface::Register::CTRL_REG1, &ctrl_reg1_content)) return false;

  ctrl_reg1_content &= ~(L3GD20_CTRL_REG1_DR1_bm | L3GD20_CTRL_REG1_DR0_bm | L3GD20_CTRL_REG1_BW1_bm | L3GD20_CTRL_REG1_BW0_bm);
  ctrl_reg1_content |= static_cast<uint8_t>(sel);

  if(!_io.writeRegister(interface::Register::CTRL_REG1, ctrl_reg1_content)) return false;

  return true;
}

bool L3GD20_Control::setFullScale(interface::FullScaleSelect const sel)
{
  uint8_t ctrl_reg4_content = 0;

  if(!_io.readRegister(interface::Register::CTRL_REG4, &ctrl_reg4_content)) return false;

  ctrl_reg4_content &= ~(L3GD20_CTRL_REG4_FS1_bm | L3GD20_CTRL_REG4_FS0_bm);
  ctrl_reg4_content |= static_cast<uint8_t>(sel);

  if(!_io.writeRegister(interface::Register::CTRL_REG4, ctrl_reg4_content)) return false;

  return true;
}

bool L3GD20_Control::enableXYZAxis()
{
  uint8_t ctrl_reg1_content = 0;

  if(!_io.readRegister(interface::Register::CTRL_REG1, &ctrl_reg1_content)) return false;

  ctrl_reg1_content |= (L3GD20_CTRL_REG1_ZEN_bm | L3GD20_CTRL_REG1_YEN_bm | L3GD20_CTRL_REG1_XEN_bm);

  if(!_io.writeRegister(interface::Register::CTRL_REG1, ctrl_reg1_content)) return false;

  return true;
}

bool L3GD20_Control::enableXAxis()
{
  uint8_t ctrl_reg1_content = 0;

  if(!_io.readRegister(interface::Register::CTRL_REG1, &ctrl_reg1_content)) return false;

  ctrl_reg1_content |= (L3GD20_CTRL_REG1_XEN_bm);

  if(!_io.writeRegister(interface::Register::CTRL_REG1, ctrl_reg1_content)) return false;

  return true;
}

bool L3GD20_Control::enableYAxis()
{
  uint8_t ctrl_reg1_content = 0;

  if(!_io.readRegister(interface::Register::CTRL_REG1, &ctrl_reg1_content)) return false;

  ctrl_reg1_content |= (L3GD20_CTRL_REG1_YEN_bm);

  if(!_io.writeRegister(interface::Register::CTRL_REG1, ctrl_reg1_content)) return false;

  return true;
}

bool L3GD20_Control::enableZAxis()
{
  uint8_t ctrl_reg1_content = 0;

  if(!_io.readRegister(interface::Register::CTRL_REG1, &ctrl_reg1_content)) return false;

  ctrl_reg1_content |= (L3GD20_CTRL_REG1_ZEN_bm);

  if(!_io.writeRegister(interface::Register::CTRL_REG1, ctrl_reg1_content)) return false;

  return true;
}

bool L3GD20_Control::checkIfNewDataIsAvailable_XYZ(bool * is_new_data_available_xyz)
{
  uint8_t status_reg_content  = 0;

  if(!_io.readRegister(interface::Register::STATUS_REG, &status_reg_content)) return false;

  *is_new_data_available_xyz = (status_reg_content & L3GD20_STATUS_REG_ZYXDA_bm) != 0;

  return true;
}

bool L3GD20_Control::checkIfNewDataIsAvailable_X(bool * is_new_data_available_x)
{
  uint8_t status_reg_content  = 0;

  if(!_io.readRegister(interface::Register::STATUS_REG, &status_reg_content)) return false;

  *is_new_data_available_x = (status_reg_content & L3GD20_STATUS_REG_XDA_bm) != 0;

  return true;
}

bool L3GD20_Control::checkIfNewDataIsAvailable_Y(bool * is_new_data_available_y)
{
  uint8_t status_reg_content  = 0;

  if(!_io.readRegister(interface::Register::STATUS_REG, &status_reg_content)) return false;

  *is_new_data_available_y = (status_reg_content & L3GD20_STATUS_REG_YDA_bm) != 0;

  return true;
}

bool L3GD20_Control::checkIfNewDataIsAvailable_Z(bool * is_new_data_available_z)
{
  uint8_t status_reg_content  = 0;

  if(!_io.readRegister(interface::Register::STATUS_REG, &status_reg_content)) return false;

  *is_new_data_available_z = (status_reg_content & L3GD20_STATUS_REG_ZDA_bm) != 0;

  return true;
}

bool L3GD20_Control::checkIfDataOverrun_XYZ(bool * is_data_overrun_xyz)
{
  uint8_t status_reg_content  = 0;

  if(!_io.readRegister(interface::Register::STATUS_REG, &status_reg_content)) return false;

  *is_data_overrun_xyz = (status_reg_content & L3GD20_STATUS_REG_ZYXOR_bm) != 0;

  return true;
}

bool L3GD20_Control::checkIfDataOverrun_X(bool * is_data_overrun_x)
{
  uint8_t status_reg_content  = 0;

  if(!_io.readRegister(interface::Register::STATUS_REG, &status_reg_content)) return false;

  *is_data_overrun_x = (status_reg_content & L3GD20_STATUS_REG_XOR_bm) != 0;

  return true;
}

bool L3GD20_Control::checkIfDataOverrun_Y(bool * is_data_overrun_y)
{
  uint8_t status_reg_content  = 0;

  if(!_io.readRegister(interface::Register::STATUS_REG, &status_reg_content)) return false;

  *is_data_overrun_y = (status_reg_content & L3GD20_STATUS_REG_YOR_bm) != 0;

  return true;
}

bool L3GD20_Control::checkIfDataOverrun_Z(bool * is_data_overrun_z)
{
  uint8_t status_reg_content  = 0;

  if(!_io.readRegister(interface::Register::STATUS_REG, &status_reg_content)) return false;

  *is_data_overrun_z = (status_reg_content & L3GD20_STATUS_REG_ZOR_bm) != 0;

  return true;
}

bool L3GD20_Control::readXYZAxis(int16_t * raw_x, int16_t * raw_y, int16_t * raw_z)
{
  uint8_t raw_xyz_data[6];

  if(!_io.readRegister(interface::Register::OUT_X_L, raw_xyz_data, 6)) return false;

  uint8_t const x_l = raw_xyz_data[0];
  uint8_t const x_h = raw_xyz_data[1];
  uint8_t const y_l = raw_xyz_data[2];
  uint8_t const y_h = raw_xyz_data[3];
  uint8_t const z_l = raw_xyz_data[4];
  uint8_t const z_h = raw_xyz_data[5];

  *raw_x = static_cast<int16_t>((static_cast<uint16_t>(x_h) << 8) + (static_cast<uint16_t>(x_l)));
  *raw_y = static_cast<int16_t>((static_cast<uint16_t>(y_h) << 8) + (static_cast<uint16_t>(y_l)));
  *raw_z = static_cast<int16_t>((static_cast<uint16_t>(z_h) << 8) + (static_cast<uint16_t>(z_l)));

  return true;
}

bool L3GD20_Control::readXAxis(int16_t * raw_x)
{
  uint8_t raw_x_data[2];

  if(!_io.readRegister(interface::Register::OUT_X_L, raw_x_data, 2)) return false;

  uint8_t const x_l = raw_x_data[0];
  uint8_t const x_h = raw_x_data[1];

  *raw_x = static_cast<int16_t>((static_cast<uint16_t>(x_h) << 8) + (static_cast<uint16_t>(x_l)));

  return true;
}

bool L3GD20_Control::readYAxis(int16_t * raw_y)
{
  uint8_t raw_y_data[2];

  if(!_io.readRegister(interface::Register::OUT_Y_L, raw_y_data, 2)) return false;

  uint8_t const y_l = raw_y_data[0];
  uint8_t const y_h = raw_y_data[1];

  *raw_y = static_cast<int16_t>((static_cast<uint16_t>(y_h) << 8) + (static_cast<uint16_t>(y_l)));

  return true;
}

bool L3GD20_Control::readZAxis(int16_t * raw_z)
{
  uint8_t raw_z_data[2];

  if(!_io.readRegister(interface::Register::OUT_Z_L, raw_z_data, 2)) return false;

  uint8_t const z_l = raw_z_data[0];
  uint8_t const z_h = raw_z_data[1];

  *raw_z = static_cast<int16_t>((static_cast<uint16_t>(z_h) << 8) + (static_cast<uint16_t>(z_l)));

  return true;
}

void L3GD20_Control::debug_dumpAllRegs(debug::interface::Debug & debug_interface)
{
  debug_dumpSingleReg(debug_interface, "WHO_AM_I      = ", interface::Register::WHO_AM_I     );
  debug_dumpSingleReg(debug_interface, "CTRL_REG1     = ", interface::Register::CTRL_REG1    );
  debug_dumpSingleReg(debug_interface, "CTRL_REG2     = ", interface::Register::CTRL_REG2    );
  debug_dumpSingleReg(debug_interface, "CTRL_REG3     = ", interface::Register::CTRL_REG3    );
  debug_dumpSingleReg(debug_interface, "CTRL_REG4     = ", interface::Register::CTRL_REG4    );
  debug_dumpSingleReg(debug_interface, "CTRL_REG5     = ", interface::Register::CTRL_REG5    );
  debug_dumpSingleReg(debug_interface, "REFERENCE     = ", interface::Register::REFERENCE    );
  debug_dumpSingleReg(debug_interface, "OUT_TEMP      = ", interface::Register::OUT_TEMP     );
  debug_dumpSingleReg(debug_interface, "STATUS_REG    = ", interface::Register::STATUS_REG   );
  debug_dumpSingleReg(debug_interface, "OUT_X_L       = ", interface::Register::OUT_X_L      );
  debug_dumpSingleReg(debug_interface, "OUT_X_H       = ", interface::Register::OUT_X_H      );
  debug_dumpSingleReg(debug_interface, "OUT_Y_L       = ", interface::Register::OUT_Y_L      );
  debug_dumpSingleReg(debug_interface, "OUT_Y_H       = ", interface::Register::OUT_Y_H      );
  debug_dumpSingleReg(debug_interface, "OUT_Z_L       = ", interface::Register::OUT_Z_L      );
  debug_dumpSingleReg(debug_interface, "OUT_Z_H       = ", interface::Register::OUT_Z_H      );
  debug_dumpSingleReg(debug_interface, "FIFO_CTRL_REG = ", interface::Register::FIFO_CTRL_REG);
  debug_dumpSingleReg(debug_interface, "FIFO_SRC_REG  = ", interface::Register::FIFO_SRC_REG );
  debug_dumpSingleReg(debug_interface, "INT1_CFG      = ", interface::Register::INT1_CFG     );
  debug_dumpSingleReg(debug_interface, "INT1_SRC      = ", interface::Register::INT1_SRC     );
  debug_dumpSingleReg(debug_interface, "TSH_XH        = ", interface::Register::TSH_XH       );
  debug_dumpSingleReg(debug_interface, "TSH_XH        = ", interface::Register::TSH_XH       );
  debug_dumpSingleReg(debug_interface, "TSH_XL        = ", interface::Register::TSH_XL       );
  debug_dumpSingleReg(debug_interface, "TSH_YH        = ", interface::Register::TSH_YH       );
  debug_dumpSingleReg(debug_interface, "TSH_YL        = ", interface::Register::TSH_YL       );
  debug_dumpSingleReg(debug_interface, "TSH_ZH        = ", interface::Register::TSH_ZH       );
  debug_dumpSingleReg(debug_interface, "TSH_ZL        = ", interface::Register::TSH_ZL       );
  debug_dumpSingleReg(debug_interface, "INT1_DURATION = ", interface::Register::INT1_DURATION);
}

/**************************************************************************************
 * PRIVATE FUNCTIONS
 **************************************************************************************/

bool L3GD20_Control::enablePower()
{
  uint8_t ctrl_reg1_content = 0;

  if(!_io.readRegister(interface::Register::CTRL_REG1, &ctrl_reg1_content)) return false;

  ctrl_reg1_content |= L3GD20_CTRL_REG1_PD_bm;

  if(!_io.writeRegister(interface::Register::CTRL_REG1, ctrl_reg1_content)) return false;

  return true;
}

bool L3GD20_Control::disableAllAxis()
{
  uint8_t ctrl_reg1_content = 0;

  if(!_io.readRegister(interface::Register::CTRL_REG1, &ctrl_reg1_content)) return false;

  ctrl_reg1_content &= ~(L3GD20_STATUS_REG_ZDA_bm | L3GD20_STATUS_REG_YDA_bm | L3GD20_STATUS_REG_XDA_bm);

  if(!_io.writeRegister(interface::Register::CTRL_REG1, ctrl_reg1_content)) return false;

  return true;
}

bool L3GD20_Control::enableBlockDataUpdate()
{
  uint8_t ctrl_reg4_content = 0;

  if(!_io.readRegister(interface::Register::CTRL_REG4, &ctrl_reg4_content)) return false;

  ctrl_reg4_content |= L3GD20_CTRL_REG4_BDU_bm;

  if(!_io.writeRegister(interface::Register::CTRL_REG4, ctrl_reg4_content)) return false;

  return true;
}

void L3GD20_Control::debug_dumpSingleReg(debug::interface::Debug & debug_interface, char const * msg, interface::Register const reg)
{
  uint8_t reg_content = 0;

  _io.readRegister(reg, &reg_content);

  debug_interface.print("%s%X\n", msg, reg_content);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* L3GD20 */

} /* sensor */

} /* driver */

} /* spectre */
