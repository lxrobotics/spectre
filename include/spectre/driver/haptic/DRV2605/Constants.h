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

#ifndef INCLUDE_SPECTRE_DRIVER_HAPTIC_DRV2605_CONSTANTS_H_
#define INCLUDE_SPECTRE_DRIVER_HAPTIC_DRV2605_CONSTANTS_H_

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace spectre
{

namespace driver
{

namespace DRV2605
{

/**************************************************************************************
 * DEFINES
 **************************************************************************************/

/* DRV2605_REG_MODE Bit Definitions ***************************************************/
#define DRV2605_REG_MODE_DEV_RESET_bm       (1<<7)
#define DRV2605_REG_MODE_STANDBY_bm         (1<<6)
#define DRV2605_REG_MODE_2_bm               (1<<2)
#define DRV2605_REG_MODE_1_bm               (1<<1)
#define DRV2605_REG_MODE_0_bm               (1<<0)

/* DRV2605_REG_LIB Bit Definitions ****************************************************/
#define DRV2605_REG_LIB_LIBRARY_SEL_2_bm    (1<<2)
#define DRV2605_REG_LIB_LIBRARY_SEL_1_bm    (1<<1)
#define DRV2605_REG_LIB_LIBRARY_SEL_0_bm    (1<<0)

/* DRV2605_REG_GO Bit Definitions *****************************************************/
#define DRV2605_REG_GO_GO_bm                (1<<0)

/* DRV2605_REG_FEEDBACK Bit Definitions ***********************************************/
#define DRV2605_REG_FEEDBACK_N_ERM_LRA_bm   (1<<7)

/**************************************************************************************
 * TYPEDEFS
 **************************************************************************************/

typedef enum
{
  INTERNAL_TRIGGER        = 0,
  EXTERNAL_TRIGGER_EDGE   =                                                 DRV2605_REG_MODE_0_bm,
  EXTERNAL_TRIGGER_LEVEL  =                         DRV2605_REG_MODE_1_bm,
  PWM_OR_ANALOG           =                         DRV2605_REG_MODE_1_bm | DRV2605_REG_MODE_0_bm,
  AUDIO_TO_VIBE           = DRV2605_REG_MODE_2_bm,
  REAL_TIME_PLAYBACK      = DRV2605_REG_MODE_2_bm |                         DRV2605_REG_MODE_0_bm,
  DIAGNOSTICS             = DRV2605_REG_MODE_2_bm | DRV2605_REG_MODE_1_bm,
  AUTO_CALIBRATION        = DRV2605_REG_MODE_2_bm | DRV2605_REG_MODE_1_bm | DRV2605_REG_MODE_0_bm
} eDRV2605ModeSelect;

typedef enum
{
  LIB_NONE    = 0,
  LIB_ERM_A   =                                                                       DRV2605_REG_LIB_LIBRARY_SEL_0_bm,
  LIB_ERM_B   =                                    DRV2605_REG_LIB_LIBRARY_SEL_1_bm,
  LIB_ERM_C   =                                    DRV2605_REG_LIB_LIBRARY_SEL_1_bm | DRV2605_REG_LIB_LIBRARY_SEL_0_bm,
  LIB_ERM_D   = DRV2605_REG_LIB_LIBRARY_SEL_2_bm,
  LIB_ERM_E   = DRV2605_REG_LIB_LIBRARY_SEL_2_bm |                                    DRV2605_REG_LIB_LIBRARY_SEL_0_bm,
  LIB_LRA     = DRV2605_REG_LIB_LIBRARY_SEL_2_bm | DRV2605_REG_LIB_LIBRARY_SEL_1_bm,
  LIB_ERM_F   = DRV2605_REG_LIB_LIBRARY_SEL_2_bm | DRV2605_REG_LIB_LIBRARY_SEL_1_bm | DRV2605_REG_LIB_LIBRARY_SEL_0_bm
} eDRV2605WaveformLibrarySelect;

typedef enum
{
  WAVEFORM_SEQUENCER_1 = 0,
  WAVEFORM_SEQUENCER_2 = 1,
  WAVEFORM_SEQUENCER_3 = 2,
  WAVEFORM_SEQUENCER_4 = 3,
  WAVEFORM_SEQUENCER_5 = 4,
  WAVEFORM_SEQUENCER_6 = 5,
  WAVEFORM_SEQUENCER_7 = 6,
  WAVEFORM_SEQUENCER_8 = 7
} eDRV2605WaveformSequencerSelect;

typedef enum
{
  ERM = 0,
  LRA = DRV2605_REG_FEEDBACK_N_ERM_LRA_bm
} eDRV2605ActuatorSelect;


typedef enum
{
  REG_STATUS            = 0x00,
  REG_MODE              = 0x01,
  REG_RTP               = 0x02,
  REG_LIB               = 0x03,
  REG_WAVESEQ1          = 0x04,
  REG_WAVESEQ2          = 0x05,
  REG_WAVESEQ3          = 0x06,
  REG_WAVESEQ4          = 0x07,
  REG_WAVESEQ5          = 0x08,
  REG_WAVESEQ6          = 0x09,
  REG_WAVESEQ7          = 0x0A,
  REG_WAVESEQ8          = 0x0B,
  REG_GO                = 0x0C,
  REG_OVERDRIVE         = 0x0D,
  REG_SUSTAINOFFSETPOS  = 0x0E,
  REG_SUSTAINOFFSETNEG  = 0x0F,
  REG_BREAKTIME         = 0x10,
  REG_AUDIOCTRL         = 0x11,
  REG_AUDMINLVL         = 0x12,
  REG_AUDMAXLVL         = 0x13,
  REG_AUDMINDRIVE       = 0x14,
  REG_AUDMAXDRIVE       = 0X15,
  REG_RATEDVOLT         = 0x16,
  REG_OVERDRIVECLAMP    = 0x17,
  REG_COMPRESULT        = 0x18,
  REG_BACKEMF           = 0x19,
  REG_FEEDBACK          = 0x1A,
  REG_CONTROL1          = 0x1B,
  REG_CONTROL2          = 0x1C,
  REG_CONTROL3          = 0x1D,
  REG_CONTROL4          = 0x1E,
  REG_CONTROL5          = 0x1F,
  REG_OLP               = 0x20,
  REG_VBATMONITOR       = 0x21,
  REG_LRARESPERIOD      = 0x22
} eDRV2605RegisterSelect;

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* DRV2605 */

} /* driver */

} /* spectre */

#endif /* INCLUDE_SPECTRE_DRIVER_HAPTIC_DRV2605_CONSTANTS_H_ */