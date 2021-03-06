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

#ifndef INCLUDE_SNOWFOX_DRIVER_HAPTIC_DRV2605_DRV2605_H_
#define INCLUDE_SNOWFOX_DRIVER_HAPTIC_DRV2605_DRV2605_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <snowfox/driver/haptic/HapticActuatorDriver.h>

#include <snowfox/driver/haptic/DRV2605/interface/DRV2605_Control.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::driver::haptic::DRV2605
{

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

class IoctlSetWaveFormArg
{

public:

  IoctlSetWaveFormArg(interface::WaveformSequencer const waveform_sequencer, uint8_t const waveform)
  {
    data.waveform_sequencer = waveform_sequencer;
    data.waveform           = waveform;
  }

  struct
  {
    interface::WaveformSequencer waveform_sequencer;
    uint8_t                      waveform;
  } data;
};

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static uint32_t constexpr IOCTL_SET_MODE             = 0; /* Arg: ModeSelect *            -> uint8_t *  */
static uint32_t constexpr IOCTL_SET_WAVEFORM_LIBRARY = 1; /* Arg: WaveformLibrarySelect * -> uint8_t *  */
static uint32_t constexpr IOCTL_SET_WAVEFORM         = 2; /* Arg: IoctlSetWaveFormArg *                 */
static uint32_t constexpr IOCTL_SET_ACTUATOR         = 3; /* Arg: ActuatorSelect *        -> uint8_t *  */
static uint32_t constexpr IOCTL_SET_GO               = 4; /* Arg: None                                  */
static uint32_t constexpr IOCTL_CLR_GO               = 5; /* Arg: None                                  */

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class DRV2605 final : public HapticActuatorDriver
{

public:

           DRV2605(interface::DRV2605_Control & ctrl);
  virtual ~DRV2605();


  virtual bool open () override;
  virtual void close() override;


protected:

  virtual bool ioctl_device(uint32_t const cmd, void * arg) override;


private:

  interface::DRV2605_Control & _ctrl;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::driver::haptic::DRV2605 */

#endif /* INCLUDE_SNOWFOX_DRIVER_HAPTIC_DRV2605_DRV2605_H_ */
