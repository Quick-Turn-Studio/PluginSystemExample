set(LIB_NAME Base)

add_library(${LIB_NAME} INTERFACE)
add_library(QuickTurnStudio::${LIB_NAME} ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME} INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)
