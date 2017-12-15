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

#ifndef INCLUDE_SPECTRE_MCU_AVR_ATMEGA328P_I2CMASTER_H_
#define INCLUDE_SPECTRE_MCU_AVR_ATMEGA328P_I2CMASTER_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <spectre/hal/avr/ATxxxx/I2CMaster.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace hal
{

namespace ATMEGA328P
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class I2CMaster : public ATxxxx::I2CMaster
{

public:

           I2CMaster();
  virtual ~I2CMaster();

protected:

  virtual bool start                 (uint8_t    const   address) override;
  virtual bool transmitByte          (uint8_t    const   data   ) override;
  virtual void receiveByteAndSendACK (uint8_t          * data   ) override;
  virtual void receiveByteAndSendNACK(uint8_t          * data   ) override;
  virtual void stop                  (                          ) override;

  virtual void setTWIPrescaler       (eTWIPrescaler const prescaler    ) override;
  virtual void setTWBR               (uint32_t      const i2c_speed_Hz,
                                      uint32_t      const i2c_prescaler) override;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* ATMEGA328P */

} /* hal */

} /* spectre */

#endif /* INCLUDE_SPECTRE_MCU_AVR_ATMEGA328P_I2CMASTER_H_ */