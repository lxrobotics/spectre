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

#ifndef INCLUDE_SNOWFOX_HAL_AVR_COMMON_ATXXXX_I2CMASTERLOWLEVEL_H_
#define INCLUDE_SNOWFOX_HAL_AVR_COMMON_ATXXXX_I2CMASTERLOWLEVEL_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <snowfox/hal/avr/common/ATxxxx/interface/I2cMasterLowLevel.h>

#include <snowfox/os/event/interface/EventConsumer.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::hal::ATxxxx
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class I2cMasterLowLevel : public interface::I2cMasterLowLevel
{

public:

           I2cMasterLowLevel(volatile uint8_t             * twcr,
                             volatile uint8_t             * twdr,
                             volatile uint8_t             * twsr,
                             volatile uint8_t             * twbr,
                             os::interface::EventConsumer & i2c_transfer_complete_event);
  virtual ~I2cMasterLowLevel();


  virtual bool start                 (uint8_t const   address                                  ) override;
  virtual bool transmitByte          (uint8_t const   data                                     ) override;
  virtual void receiveByteAndSendACK (uint8_t       * data                                     ) override;
  virtual void receiveByteAndSendNACK(uint8_t       * data                                     ) override;
  virtual void stop                  (                                                         ) override;
  virtual void setTwiPrescaler       (uint32_t const prescaler                                 ) override;
  virtual void setTwiBitRateRegister (uint32_t const i2c_speed_Hz, uint32_t const i2c_prescaler) override;

private:


  volatile uint8_t             * _TWCR,
                               * _TWDR,
                               * _TWSR,
                               * _TWBR;
  os::interface::EventConsumer & _i2c_transfer_complete_event;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::hal::ATxxxx */

#endif /* INCLUDE_SNOWFOX_HAL_AVR_COMMON_ATXXXX_I2CMASTERLOWLEVEL_H_ */
