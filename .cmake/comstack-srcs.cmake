##########################################################################
# COMSTACK ###############################################################
##########################################################################

##########################################################################
# CANOPEN ################################################################
##########################################################################

set(COMSTACK_CANOPEN_SRC_PATH src/comstack/canopen)

if(${COMSTACK_CANOPEN} STREQUAL "yes")
  set(SNOWFOX_LIBRARY_COMSTACK_CANOPEN_SRCS
    ${COMSTACK_CANOPEN_SRC_PATH}/util/CanOpenFrameUtil.cpp
    ${COMSTACK_CANOPEN_SRC_PATH}/nmt/NmtFrameHandler.cpp
    ${COMSTACK_CANOPEN_SRC_PATH}/nodeguard/NodeGuardFrameHandler.cpp
    ${COMSTACK_CANOPEN_SRC_PATH}/objdict/ObjectDictionaryBuilder.cpp
    ${COMSTACK_CANOPEN_SRC_PATH}/pdo/PdoFrameHandler.cpp
    ${COMSTACK_CANOPEN_SRC_PATH}/sdo/SdoFrameHandler.cpp
    ${COMSTACK_CANOPEN_SRC_PATH}/sync/SyncFrameHandler.cpp
    ${COMSTACK_CANOPEN_SRC_PATH}/CanOpenStack.cpp
    ${COMSTACK_CANOPEN_SRC_PATH}/FrameDispatcher.cpp
    ${COMSTACK_CANOPEN_SRC_PATH}/UnkownFrameHandler.cpp
  )
  set(SNOWFOX_LIBRARY_COMSTACK_SRCS ${SNOWFOX_LIBRARY_COMSTACK_SRCS} ${SNOWFOX_LIBRARY_COMSTACK_CANOPEN_SRCS})
endif()

##########################################################################
