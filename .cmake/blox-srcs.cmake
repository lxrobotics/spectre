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

if(${MCU_ARCH} STREQUAL "avr")

##########################################################################

  set(SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH src/blox/hal/avr)

  # AT90CAN128 ###########################################################

  set(SPECTRE_LIBRARY_BLOX_HAL_AVR_AT90CAN128_SRCS 
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/AT90CAN128/UART0.cpp
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/AT90CAN128/UART1.cpp
  )

  if(${MCU_TYPE} STREQUAL "at90can128")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_AT90CAN128_SRCS})  
  endif()
  
  # AT90CAN32 ############################################################

  set(SPECTRE_LIBRARY_BLOX_HAL_AVR_AT90CAN32_SRCS 
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/AT90CAN32/UART0.cpp
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/AT90CAN32/UART1.cpp
  )

  if(${MCU_TYPE} STREQUAL "at90can32")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_AT90CAN32_SRCS})  
  endif()
  
  # AT90CAN64 ############################################################

  set(SPECTRE_LIBRARY_BLOX_HAL_AVR_AT90CAN64_SRCS 
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/AT90CAN64/UART0.cpp
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/AT90CAN64/UART1.cpp
  )

  if(${MCU_TYPE} STREQUAL "at90can64")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_AT90CAN64_SRCS})  
  endif()
  
  # ATMEGA1280 ###########################################################

  set(SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA1280_SRCS 
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/common/ATMEGA640_1280_2560/ExternalInterruptController.cpp
  )

  if(${MCU_TYPE} STREQUAL "atmega1280")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA1280_SRCS})  
  endif()

  # ATMEGA1284P ##########################################################

  set(SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA1284P_SRCS 
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA1284P/ExternalInterruptController.cpp
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA1284P/UART0.cpp
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA1284P/UART1.cpp
  )

  if(${MCU_TYPE} STREQUAL "atmega1284p")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA1284P_SRCS})  
  endif()

  # ATMEGA164P ###########################################################

  set(SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA164P_SRCS 
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA164P/UART0.cpp
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA164P/UART1.cpp
  )
  
  if(${MCU_TYPE} STREQUAL "atmega164p")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA164P_SRCS})  
  endif()
  
  # ATMEGA2560 ###########################################################

  set(SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA2560_SRCS 
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/common/ATMEGA640_1280_2560/ExternalInterruptController.cpp
  )

  if(${MCU_TYPE} STREQUAL "atmega2560")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA2560_SRCS})  
  endif()
  
  # ATMEGA324P ###########################################################

  set(SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA324P_SRCS 
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA324P/UART0.cpp
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA324P/UART1.cpp
  )
  
  if(${MCU_TYPE} STREQUAL "atmega324p")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA324P_SRCS})  
  endif()

  # ATMEGA328P ###########################################################

  set(SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA328P_SRCS 
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA328P/UART0.cpp
  )
  
  if(${MCU_TYPE} STREQUAL "atmega328p")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA328P_SRCS})  
  endif()
  
  # ATMEGA640 ############################################################

  set(SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA640_SRCS 
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/common/ATMEGA640_1280_2560/ExternalInterruptController.cpp
  )

  if(${MCU_TYPE} STREQUAL "atmega640")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA640_SRCS})  
  endif()
  
  # ATMEGA644P ###########################################################

  set(SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA644P_SRCS 
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA644P/UART0.cpp
    ${SPECTRE_LIBRARY_BLOX_HAL_AVR_PATH}/ATMEGA644P/UART1.cpp
  )
  
  if(${MCU_TYPE} STREQUAL "atmega644p")
    set(SPECTRE_LIBRARY_BLOX_SRCS ${SPECTRE_LIBRARY_BLOX_SRCS} ${SPECTRE_LIBRARY_BLOX_HAL_AVR_ATMEGA644P_SRCS})  
  endif()
  
##########################################################################

endif()

##########################################################################
