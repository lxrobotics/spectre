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

#ifndef INCLUDE_SNOWFOX_DRIVER_SENSOR_BMP388_INTERFACE_BMP388_CONTROL_H_
#define INCLUDE_SNOWFOX_DRIVER_SENSOR_BMP388_INTERFACE_BMP388_CONTROL_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <snowfox/driver/sensor/BMP388/interface/BMP388_Types.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::driver::sensor::BMP388::interface
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class BMP388_Control
{

public:

  virtual ~BMP388_Control() { }


  virtual void readSensorData(SensorData & sensor_data) = 0;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::driver::sensor::BMP388::interface */

#endif /* INCLUDE_SNOWFOX_DRIVER_SENSOR_BMP388_INTERFACE_BMP388_CONTROL_H_ */
