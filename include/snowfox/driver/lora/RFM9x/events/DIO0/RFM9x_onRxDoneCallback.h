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

#ifndef INCLUDE_SNOWFOX_DRIVER_LORA_RFM9X_PACKET_MODE_RFM9X_ONPAYLOADREADYCALLBACK_H_
#define INCLUDE_SNOWFOX_DRIVER_LORA_RFM9X_PACKET_MODE_RFM9X_ONPAYLOADREADYCALLBACK_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <snowfox/driver/lora/RFM9x/interface/events/DIO0/RFM9x_onRxDoneCallback.h>

#include <snowfox/os/event/interface/EventProducer.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::driver::lora::RFM9x
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class RFM9x_onRxDoneCallback final : public interface::RFM9x_onRxDoneCallback
{

public:

           RFM9x_onRxDoneCallback(os::interface::EventProducer & rx_done_event);
  virtual ~RFM9x_onRxDoneCallback();


  virtual void onRxDone() override;


private:

  os::interface::EventProducer & _rx_done_event;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::driver::lora::RFM9x */

#endif /* INCLUDE_SNOWFOX_DRIVER_LORA_RFM9X_PACKET_MODE_RFM9X_ONPAYLOADREADYCALLBACK_H_ */
