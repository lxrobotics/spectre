##########################################################################

add_definitions(-DMCU_ARCH_${MCU_ARCH})
add_definitions(-DMCU_TYPE_${MCU_TYPE})
add_definitions(-DF_CPU=${MCU_SPEED})

##########################################################################

set(SNOWFOX_ALL_GCC_CMAKE_C_FLAGS     "")
set(SNOWFOX_ALL_GCC_CMAKE_CXX_FLAGS   "-std=c++11")
set(SNOWFOX_ALL_GCC_CMAKE_C_CXX_FLAGS "")

##########################################################################

set(SNOWFOX_CMAKE_C_FLAGS   "${SNOWFOX_CMAKE_C_FLAGS}   ${SNOWFOX_ALL_GCC_CMAKE_C_FLAGS}   ${SNOWFOX_ALL_GCC_CMAKE_C_CXX_FLAGS}")
set(SNOWFOX_CMAKE_CXX_FLAGS "${SNOWFOX_CMAKE_CXX_FLAGS} ${SNOWFOX_ALL_GCC_CMAKE_CXX_FLAGS} ${SNOWFOX_ALL_GCC_CMAKE_C_CXX_FLAGS}")
 
##########################################################################
