##########################################################################
# DRIVER #################################################################
##########################################################################

set(DRIVER_CAN_SRC_PATH src/driver/can)

if(${DRIVER_CAN_MCP2515} STREQUAL "yes")
  set(DRIVER_CAN_MCP2515_SRCS
    ${DRIVER_CAN_SRC_PATH}/MCP2515/events/MCP2515_EventCallback.cpp
    ${DRIVER_CAN_SRC_PATH}/MCP2515/events/MCP2515_onMessageError.cpp
  	${DRIVER_CAN_SRC_PATH}/MCP2515/events/MCP2515_onReceiveBufferFull.cpp
  	${DRIVER_CAN_SRC_PATH}/MCP2515/events/MCP2515_onTransmitBufferEmpty.cpp
  	${DRIVER_CAN_SRC_PATH}/MCP2515/events/MCP2515_onWakeup.cpp
  
    ${DRIVER_CAN_SRC_PATH}/MCP2515/interface/control/MCP2515_EventControl.cpp
  
    ${DRIVER_CAN_SRC_PATH}/MCP2515/MCP2515_CanConfiguration.cpp
    ${DRIVER_CAN_SRC_PATH}/MCP2515/MCP2515_CanControl.cpp
    ${DRIVER_CAN_SRC_PATH}/MCP2515/MCP2515_Control.cpp
    ${DRIVER_CAN_SRC_PATH}/MCP2515/MCP2515_Debug.cpp
  	${DRIVER_CAN_SRC_PATH}/MCP2515/MCP2515_IoSpi.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_CAN_MCP2515_SRCS})
endif()

if(${DRIVER_CAN_MCP2515} STREQUAL "yes")
  set(DRIVER_CAN_SRCS
    ${DRIVER_CAN_SRC_PATH}/Can.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_CAN_SRCS})
endif()

##########################################################################

set(DRIVER_GLCD_SRC_PATH src/driver/glcd)

if(${DRIVER_GLCD_RA6963} STREQUAL "yes")
  set(DRIVER_GLCD_RA6963_SRCS
    ${DRIVER_GLCD_SRC_PATH}/RA6963/RA6963_Control.cpp
  	${DRIVER_GLCD_SRC_PATH}/RA6963/RA6963_Data.cpp
    ${DRIVER_GLCD_SRC_PATH}/RA6963/RA6963_IoGpio8Bit.cpp
    ${DRIVER_GLCD_SRC_PATH}/RA6963/RA6963.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_GLCD_RA6963_SRCS})
endif()

##########################################################################

set(DRIVER_HAPTIC_SRC_PATH src/driver/haptic)

if(${DRIVER_HAPTIC_DRV2605} STREQUAL "yes")
  set(DRIVER_HAPTIC_DRV2605_SRCS
    ${DRIVER_HAPTIC_SRC_PATH}/DRV2605/DRV2605_Control.cpp
    ${DRIVER_HAPTIC_SRC_PATH}/DRV2605/DRV2605_Debug.cpp
    ${DRIVER_HAPTIC_SRC_PATH}/DRV2605/DRV2605_IoI2C.cpp
    ${DRIVER_HAPTIC_SRC_PATH}/DRV2605/DRV2605.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_HAPTIC_DRV2605_SRCS})
endif()

##########################################################################

set(DRIVER_IOEXPANDER_SRC_PATH src/driver/ioexpander)

if(${DRIVER_IOEXPANDER_PCA9547} STREQUAL "yes")
  set(DRIVER_IOEXPANDER_PCA9547_SRCS
    ${DRIVER_IOEXPANDER_SRC_PATH}/PCA9547/PCA9547_Control.cpp
    ${DRIVER_IOEXPANDER_SRC_PATH}/PCA9547/PCA9547_Debug.cpp
    ${DRIVER_IOEXPANDER_SRC_PATH}/PCA9547/PCA9547_IoI2c.cpp
    ${DRIVER_IOEXPANDER_SRC_PATH}/PCA9547/PCA9547.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_IOEXPANDER_PCA9547_SRCS})
endif()

##########################################################################

set(DRIVER_LORA_SRC_PATH src/driver/lora)

if(${DRIVER_LORA_RFM9x} STREQUAL "yes")
  set(DRIVER_LORA_RFM9x_SRCS
    ${DRIVER_LORA_SRC_PATH}/RFM9x/events/DIO0/RFM9x_Dio0EventCallback.cpp
    ${DRIVER_LORA_SRC_PATH}/RFM9x/events/DIO0/RFM9x_onCadDoneCallback.cpp
    ${DRIVER_LORA_SRC_PATH}/RFM9x/events/DIO0/RFM9x_onRxDoneCallback.cpp
    ${DRIVER_LORA_SRC_PATH}/RFM9x/events/DIO0/RFM9x_onTxDoneCallback.cpp
    
    ${DRIVER_LORA_SRC_PATH}/RFM9x/events/DIO1/RFM9x_Dio1EventCallback.cpp
    ${DRIVER_LORA_SRC_PATH}/RFM9x/events/DIO1/RFM9x_onCadDetectedCallback.cpp
    ${DRIVER_LORA_SRC_PATH}/RFM9x/events/DIO1/RFM9x_onFhssChangeChannelCallback.cpp
    ${DRIVER_LORA_SRC_PATH}/RFM9x/events/DIO1/RFM9x_onRxTimeoutCallback.cpp
    
    ${DRIVER_LORA_SRC_PATH}/RFM9x/interface/RFM9x_EventControl.cpp
    
    ${DRIVER_LORA_SRC_PATH}/RFM9x/RFM9x_Configuration.cpp
    ${DRIVER_LORA_SRC_PATH}/RFM9x/RFM9x_Control.cpp
    ${DRIVER_LORA_SRC_PATH}/RFM9x/RFM9x_Debug.cpp
    ${DRIVER_LORA_SRC_PATH}/RFM9x/RFM9x_IoSpi.cpp
    ${DRIVER_LORA_SRC_PATH}/RFM9x/RFM9x_Status.cpp
    ${DRIVER_LORA_SRC_PATH}/RFM9x/RFM9x.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_LORA_RFM9x_SRCS})
endif()

##########################################################################

set(DRIVER_MEMORY_SRC_PATH src/driver/memory)

if(${DRIVER_MEMORY_AT45DBX} STREQUAL "yes")
  set(DRIVER_MEMORY_AT45DBX_SRCS
    ${DRIVER_MEMORY_SRC_PATH}/AT45DBx/AT45DBx.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_MEMORY_AT45DBX_SRCS})  

endif()

if(${DRIVER_MEMORY_PCF8570} STREQUAL "yes")
  set(DRIVER_MEMORY_PCF8570_SRCS
    ${DRIVER_MEMORY_SRC_PATH}/PCF8570/PCF8570_Control.cpp
	${DRIVER_MEMORY_SRC_PATH}/PCF8570/PCF8570_IoI2c.cpp
	${DRIVER_MEMORY_SRC_PATH}/PCF8570/PCF8570.cpp        
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_MEMORY_PCF8570_SRCS})
endif()

##########################################################################

set(DRIVER_SENSOR_SRC_PATH src/driver/sensor)

if(${DRIVER_SENSOR_AD7151} STREQUAL "yes")
  set(DRIVER_SENSOR_AD7151_SRCS
    ${DRIVER_SENSOR_SRC_PATH}/AD7151/AD7151_Control.cpp
    ${DRIVER_SENSOR_SRC_PATH}/AD7151/AD7151_Debug.cpp
    ${DRIVER_SENSOR_SRC_PATH}/AD7151/AD7151_IoI2c.cpp
    ${DRIVER_SENSOR_SRC_PATH}/AD7151/AD7151.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_SENSOR_AD7151_SRCS})
endif()

if(${DRIVER_SENSOR_AS5600} STREQUAL "yes")
  set(DRIVER_SENSOR_AS5600_SRCS
    ${DRIVER_SENSOR_SRC_PATH}/AS5600/AS5600_Control.cpp
    ${DRIVER_SENSOR_SRC_PATH}/AS5600/AS5600_Debug.cpp
    ${DRIVER_SENSOR_SRC_PATH}/AS5600/AS5600_IoI2c.cpp
    ${DRIVER_SENSOR_SRC_PATH}/AS5600/AS5600.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_SENSOR_AS5600_SRCS})
endif()

if(${DRIVER_SENSOR_BMG160} STREQUAL "yes")
  set(DRIVER_SENSOR_BMG160_SRCS
    ${DRIVER_SENSOR_SRC_PATH}/BMG160/BMG160_Control.cpp
    ${DRIVER_SENSOR_SRC_PATH}/BMG160/BMG160_Debug.cpp
    ${DRIVER_SENSOR_SRC_PATH}/BMG160/BMG160_IoI2c.cpp
    ${DRIVER_SENSOR_SRC_PATH}/BMG160/BMG160.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_SENSOR_BMG160_SRCS})
endif()

if(${DRIVER_SENSOR_INA220} STREQUAL "yes")
  set(DRIVER_SENSOR_INA220_SRCS
    ${DRIVER_SENSOR_SRC_PATH}/INA220/INA220_Control.cpp
    ${DRIVER_SENSOR_SRC_PATH}/INA220/INA220_Debug.cpp
    ${DRIVER_SENSOR_SRC_PATH}/INA220/INA220_IoI2c.cpp
    ${DRIVER_SENSOR_SRC_PATH}/INA220/INA220.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_SENSOR_INA220_SRCS})
endif()

if(${DRIVER_SENSOR_L3GD20} STREQUAL "yes")
  set(DRIVER_SENSOR_L3GD20_SRCS
    ${DRIVER_SENSOR_SRC_PATH}/L3GD20/L3GD20_Control.cpp
    ${DRIVER_SENSOR_SRC_PATH}/L3GD20/L3GD20_Debug.cpp
    ${DRIVER_SENSOR_SRC_PATH}/L3GD20/L3GD20_IoI2c.cpp
    ${DRIVER_SENSOR_SRC_PATH}/L3GD20/L3GD20.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_SENSOR_L3GD20_SRCS})
endif()

if(${DRIVER_SENSOR_LIS2DSH} STREQUAL "yes")
  set(DRIVER_SENSOR_LIS2DSH_SRCS
    ${DRIVER_SENSOR_SRC_PATH}/LIS2DSH/LIS2DSH_Control.cpp
    ${DRIVER_SENSOR_SRC_PATH}/LIS2DSH/LIS2DSH_Debug.cpp
    ${DRIVER_SENSOR_SRC_PATH}/LIS2DSH/LIS2DSH_IoI2c.cpp
    ${DRIVER_SENSOR_SRC_PATH}/LIS2DSH/LIS2DSH.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_SENSOR_LIS2DSH_SRCS})
endif()

if(${DRIVER_SENSOR_LIS3DSH} STREQUAL "yes")
  set(DRIVER_SENSOR_LIS3DSH_SRCS
    ${DRIVER_SENSOR_SRC_PATH}/LIS3DSH/LIS3DSH_Control.cpp
    ${DRIVER_SENSOR_SRC_PATH}/LIS3DSH/LIS3DSH_Debug.cpp
    ${DRIVER_SENSOR_SRC_PATH}/LIS3DSH/LIS3DSH_IoI2c.cpp
    ${DRIVER_SENSOR_SRC_PATH}/LIS3DSH/LIS3DSH.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_SENSOR_LIS3DSH_SRCS})
endif()

if(${DRIVER_SENSOR_LIS3MDL} STREQUAL "yes")
  set(DRIVER_SENSOR_LIS3MDL_SRCS
    ${DRIVER_SENSOR_SRC_PATH}/LIS3MDL/LIS3MDL_Control.cpp
    ${DRIVER_SENSOR_SRC_PATH}/LIS3MDL/LIS3MDL_Debug.cpp
    ${DRIVER_SENSOR_SRC_PATH}/LIS3MDL/LIS3MDL_IoI2c.cpp
    ${DRIVER_SENSOR_SRC_PATH}/LIS3MDL/LIS3MDL.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_SENSOR_LIS3MDL_SRCS})
endif()

##########################################################################

set(DRIVER_SERIAL_SRC_PATH src/driver/serial)

if(${DRIVER_SERIAL} STREQUAL "yes")
  set(DRIVER_SERIAL_SRCS
    ${DRIVER_SERIAL_SRC_PATH}/Serial.cpp
    ${DRIVER_SERIAL_SRC_PATH}/UART/events/UART_onRxDoneCallback.cpp
    ${DRIVER_SERIAL_SRC_PATH}/UART/events/UART_onTxDoneCallback.cpp
    ${DRIVER_SERIAL_SRC_PATH}/UART/UART_SerialConfig.cpp
    ${DRIVER_SERIAL_SRC_PATH}/UART/UART_SerialControl.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_SERIAL_SRCS})
endif()

##########################################################################

set(DRIVER_STEPPER_SRC_PATH src/driver/stepper)

if(${DRIVER_STEPPER_TMC26x} STREQUAL "yes")
  set(DRIVER_STEPPER_TMC26x_SRCS
    ${DRIVER_STEPPER_SRC_PATH}/TMC26x/TMC26x.cpp
  )
  set(SPECTRE_LIBRARY_DRIVER ${SPECTRE_LIBRARY_DRIVER} ${DRIVER_STEPPER_TMC26x_SRCS})
endif()

##########################################################################
