set(LIB_NAME UnixPluginHandle)

add_library(${LIB_NAME} STATIC UnixPluginHandle.cpp)

target_link_libraries(${LIB_NAME} PUBLIC QuickTurnStudio::PluginBase)

set_target_properties(${LIB_NAME} PROPERTIES
        POSITION_INDEPENDENT_CODE ON
)

target_include_directories(${LIB_NAME} INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)