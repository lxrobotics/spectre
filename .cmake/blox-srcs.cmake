##########################################################################
# BLOX ###################################################################
##########################################################################

##########################################################################
# DRIVER #################################################################
##########################################################################

##########################################################################
# SERIAL #################################################################
##########################################################################

set(SPECTRE_LIBRARY_BLOX_DRIVER_SERIAL_PATH src/blox/driver/serial)

# UART ###################################################################

set(SPECTRE_LIBRARY_BLOX_DRIVER_SERIAL_UART_SRCS 
  ${SPECTRE_LIBRARY_BLOX_DRIVER_SERIAL_PATH}/SerialUart.cpp
)

##########################################################################

set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_DRIVER_SERIAL_UART_SRCS})

##########################################################################
# HAL ####################################################################
##########################################################################

##########################################################################
# AVR ####################################################################
##########################################################################

set(SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH src/blox/hal/avr)

# ATMEGA1284P ############################################################

set(SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA1284P_SRCS 
  ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA1284P/UART0.cpp
  ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA1284P/UART1.cpp
)

# ATMEGA164P #############################################################

set(SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA164P_SRCS 
  ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA164P/UART0.cpp
)

# ATMEGA324P #############################################################

set(SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA324P_SRCS 
  ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA324P/UART0.cpp
)

# ATMEGA328P #############################################################

set(SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA328P_SRCS 
  ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA328P/UART0.cpp
)

# ATMEGA644P #############################################################

set(SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA644P_SRCS 
  ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA644P/UART0.cpp
)

##########################################################################

if(${MCU_ARCH} STREQUAL "avr")

  if(${MCU_TYPE} STREQUAL "atmega1284p")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA1284P_SRCS})  
  endif()
  
  if(${MCU_TYPE} STREQUAL "atmega164p")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA164P_SRCS})  
  endif()

  if(${MCU_TYPE} STREQUAL "atmega324p")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA324P_SRCS})  
  endif()

  if(${MCU_TYPE} STREQUAL "atmega328p")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA328P_SRCS})  
  endif()

  if(${MCU_TYPE} STREQUAL "atmega644p")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA644P_SRCS})  
  endif()

endif()

##########################################################################

