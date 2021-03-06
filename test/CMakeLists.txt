##########################################################################

cmake_minimum_required(VERSION 2.8)

##########################################################################

include_directories(include)

##########################################################################

add_subdirectory(external/catch/current)
add_subdirectory(external/libvireg)
add_subdirectory(internal/libtestcanopen)

##########################################################################

set(SNOWFOX_TEST_HOST_TARGET test-host)

##########################################################################
# COMSTACK ###############################################################
##########################################################################

set(SNOWFOX_TEST_COMSTACK_PATH src/comstack)

##########################################################################
# CANOPEN ################################################################
##########################################################################

set(SNOWFOX_TEST_COMSTACK_CANOPEN_PATH ${SNOWFOX_TEST_COMSTACK_PATH}/canopen)

set(SNOWFOX_TEST_HOST_COMSTACK_CANOPEN_SRCS
  ${SNOWFOX_TEST_COMSTACK_CANOPEN_PATH}/glue/Stack_onTransmitCallback.cpp
  ${SNOWFOX_TEST_COMSTACK_CANOPEN_PATH}/glue/Test_onTransmitCallback.cpp
  ${SNOWFOX_TEST_COMSTACK_CANOPEN_PATH}/test_BootUp.cpp
  ${SNOWFOX_TEST_COMSTACK_CANOPEN_PATH}/test_ObjectDictionary.cpp
)

##########################################################################
# HAL ####################################################################
##########################################################################

set(SNOWFOX_TEST_HAL_PATH src/hal)

##########################################################################
# AVR ####################################################################
##########################################################################

set(SNOWFOX_TEST_HAL_AVR_PATH ${SNOWFOX_TEST_HAL_PATH}/avr)

##########################################################################
# ATMEGA328P #############################################################
##########################################################################

set(SNOWFOX_TEST_HOST_HAL_AVR_ATMEGA328P_SRCS
  ${SNOWFOX_TEST_HAL_AVR_PATH}/ATMEGA328P/test_InterruptController.cpp
  ${SNOWFOX_TEST_HAL_AVR_PATH}/ATMEGA328P/test_TIMER0.cpp
  ${SNOWFOX_TEST_HAL_AVR_PATH}/ATMEGA328P/test_TIMER1.cpp
  ${SNOWFOX_TEST_HAL_AVR_PATH}/ATMEGA328P/test_TIMER2.cpp
)

##########################################################################
# common/AT90CAN32_64_128 ################################################
##########################################################################

set(SNOWFOX_TEST_HOST_HAL_AVR_COMMON_AT90CAN32_64_128_SRCS
  ${SNOWFOX_TEST_HAL_AVR_PATH}/common/AT90CAN32_64_128/test_InterruptController.cpp
  ${SNOWFOX_TEST_HAL_AVR_PATH}/common/AT90CAN32_64_128/test_TIMER0.cpp
  ${SNOWFOX_TEST_HAL_AVR_PATH}/common/AT90CAN32_64_128/test_TIMER1.cpp
  ${SNOWFOX_TEST_HAL_AVR_PATH}/common/AT90CAN32_64_128/test_TIMER2.cpp
  ${SNOWFOX_TEST_HAL_AVR_PATH}/common/AT90CAN32_64_128/test_TIMER3.cpp
)

##########################################################################
# common/ATMEGA164P_324P_644P_1284P ######################################
##########################################################################

set(SNOWFOX_TEST_HOST_HAL_AVR_COMMON_ATMEGA164P_324P_644P_1284P_SRCS
  ${SNOWFOX_TEST_HAL_AVR_PATH}/common/ATMEGA164P_324P_644P_1284P/test_InterruptController.cpp
)

##########################################################################
# common/ATMEGA16U4_32U4 #################################################
##########################################################################

set(SNOWFOX_TEST_HOST_HAL_AVR_COMMON_ATMEGA16U4_32U4_SRCS
  ${SNOWFOX_TEST_HAL_AVR_PATH}/common/ATMEGA16U4_32U4/test_InterruptController.cpp
)

##########################################################################
# common/ATxxxx ##########################################################
##########################################################################

set(SNOWFOX_TEST_HOST_HAL_AVR_COMMON_ATxxxx_SRCS
  ${SNOWFOX_TEST_HAL_AVR_PATH}/common/ATxxxx/util/test_UartUtil.cpp
  ${SNOWFOX_TEST_HAL_AVR_PATH}/common/ATxxxx/test_DigitalInPin.cpp
  ${SNOWFOX_TEST_HAL_AVR_PATH}/common/ATxxxx/test_DigitalInPort.cpp
  ${SNOWFOX_TEST_HAL_AVR_PATH}/common/ATxxxx/test_DigitalOutPin.cpp
  ${SNOWFOX_TEST_HAL_AVR_PATH}/common/ATxxxx/test_DigitalOutPort.cpp
)

##########################################################################

set(SNOWFOX_TEST_HOST_HAL_AVR_SRCS
  ${SNOWFOX_TEST_HOST_HAL_AVR_ATMEGA328P_SRCS}
  ${SNOWFOX_TEST_HOST_HAL_AVR_COMMON_AT90CAN32_64_128_SRCS}
  ${SNOWFOX_TEST_HOST_HAL_AVR_COMMON_ATMEGA164P_324P_644P_1284P_SRCS}
  ${SNOWFOX_TEST_HOST_HAL_AVR_COMMON_ATMEGA16U4_32U4_SRCS}
  ${SNOWFOX_TEST_HOST_HAL_AVR_COMMON_ATxxxx_SRCS}
  ${SNOWFOX_TEST_HAL_AVR_PATH}/util/InterruptControllerTestUtil.cpp
)

##########################################################################
# RISCV64 ################################################################
##########################################################################

set(SNOWFOX_TEST_HAL_RISCV64_PATH ${SNOWFOX_TEST_HAL_PATH}/riscv64)

##########################################################################
# SIFIVE FE310 ###########################################################
##########################################################################

set(SNOWFOX_TEST_HOST_HAL_RISCV64_FE310_SRCS
  ${SNOWFOX_TEST_HAL_RISCV64_PATH}/FE310/util/test_ClockUtil.cpp
  ${SNOWFOX_TEST_HAL_RISCV64_PATH}/FE310/util/test_UartUtil.cpp
  ${SNOWFOX_TEST_HAL_RISCV64_PATH}/FE310/test_DigitalInPin.cpp
  ${SNOWFOX_TEST_HAL_RISCV64_PATH}/FE310/test_DigitalOutPin.cpp
  ${SNOWFOX_TEST_HAL_RISCV64_PATH}/FE310/test_Spi1Master.cpp
  ${SNOWFOX_TEST_HAL_RISCV64_PATH}/FE310/test_Spi2Master.cpp
  ${SNOWFOX_TEST_HAL_RISCV64_PATH}/FE310/test_SpiMasterBase.cpp
  ${SNOWFOX_TEST_HAL_RISCV64_PATH}/FE310/test_UART0.cpp
  ${SNOWFOX_TEST_HAL_RISCV64_PATH}/FE310/test_UART1.cpp
)

##########################################################################

set(SNOWFOX_TEST_HOST_HAL_RISCV64_SRCS
  ${SNOWFOX_TEST_HOST_HAL_RISCV64_FE310_SRCS}
)

##########################################################################
# UTIL ###################################################################
##########################################################################

set(SNOWFOX_TEST_UTIL_PATH src/util)

##########################################################################

set(SNOWFOX_TEST_HOST_UTIL_SRCS
  ${SNOWFOX_TEST_UTIL_PATH}/container/test_Queue.cpp
)

##########################################################################
# OS #####################################################################
##########################################################################

set(SNOWFOX_TEST_OS_PATH src/os)

##########################################################################

set(SNOWFOX_TEST_HOST_OS_SRCS
)

##########################################################################
# TEST ###################################################################
##########################################################################

add_executable(
  ${SNOWFOX_TEST_HOST_TARGET}
  
  src/test_check_version.cpp
  src/test_main.cpp
  
  ${SNOWFOX_TEST_HOST_COMSTACK_CANOPEN_SRCS}
  ${SNOWFOX_TEST_HOST_HAL_AVR_SRCS}
  ${SNOWFOX_TEST_HOST_HAL_RISCV64_FE310_SRCS}
  ${SNOWFOX_TEST_HOST_UTIL_SRCS}
  ${SNOWFOX_TEST_HOST_OS_SRCS}
)

target_link_libraries(
  ${SNOWFOX_TEST_HOST_TARGET}
  
  snowfox-host
  catch
  vireg
  testcanopen
  gcov
)

##########################################################################

add_custom_command(TARGET ${SNOWFOX_TEST_HOST_TARGET} POST_BUILD
  COMMENT "Copying JSON register files to test binary directory"
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMAND cp -R test/json ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

##########################################################################
