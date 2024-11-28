set(LIB_NAME PluginLoader)

aux_source_directory(. SRC_FILES)

add_library(${LIB_NAME} STATIC ${SRC_FILES})
add_library(QuickTurnStudio::${LIB_NAME} ALIAS ${LIB_NAME})

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_subdirectory(windows)
    target_compile_definitions(${LIB_NAME} PRIVATE SEVENIDE_WINDOWS)
    target_link_libraries(${LIB_NAME} PRIVATE WindowsPluginHandle)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux" OR CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    add_subdirectory(unix)
    target_compile_definitions(${LIB_NAME} PRIVATE SEVENIDE_UNIX)
    target_link_libraries(${LIB_NAME} PRIVATE UnixPluginHandle)
else ()
    message(FATAL_ERROR "Platform \"${CMAKE_SYSTEM_NAME}\" not supported")
endif()


target_link_libraries(${LIB_NAME} PUBLIC QuickTurnStudio::PluginBase)

set_target_properties(${LIB_NAME} PROPERTIES
        POSITION_INDEPENDENT_CODE ON
)

target_include_directories(${LIB_NAME} INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)
