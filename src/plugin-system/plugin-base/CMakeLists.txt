set(LIB_NAME PluginBase)

aux_source_directory(. SRC_FILES)

add_library(${LIB_NAME} STATIC ${SRC_FILES})
add_library(QuickTurnStudio::${LIB_NAME} ALIAS ${LIB_NAME})

set_target_properties(${LIB_NAME} PROPERTIES
        POSITION_INDEPENDENT_CODE ON
)

target_include_directories(${LIB_NAME} INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(${LIB_NAME} PUBLIC QuickTurnStudio::Base)
