set(LIB_NAME WindowsPluginHandle)

add_library(${LIB_NAME} STATIC WindowsPluginHandle.cpp)

set_target_properties(${LIB_NAME} PROPERTIES
        POSITION_INDEPENDENT_CODE ON
)

target_include_directories(${LIB_NAME} INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)