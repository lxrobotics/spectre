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

#include <avr/io.h>

#include <spectre/hal/avr/AT90CAN64/DigitalInPin.h>
#include <spectre/hal/avr/AT90CAN64/DigitalOutPin.h>

/**************************************************************************************
 * NAMESPACES
 **************************************************************************************/

using namespace spectre::hal;

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

AT90CAN64::DigitalInPin  switch_in(&DDRD, &PORTD, &PIND, PD2);
AT90CAN64::DigitalOutPin led_out  (&DDRB, &PORTB, PB5);

/**************************************************************************************
 * MAIN
 **************************************************************************************/

int main()
{
  switch_in.setPullUpMode(interface::PullUpMode::PULL_UP);

  for(;;)
  {
    if  (switch_in.isSet()) led_out.set();
    else                    led_out.clr();
  }

  return 0;
}
