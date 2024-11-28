set(LIB_NAME MeshLoadersModuleInterface)

add_library(${LIB_NAME} INTERFACE)
add_library(QuickTurnStudio::${LIB_NAME} ALIAS ${LIB_NAME})

target_link_libraries(${LIB_NAME} INTERFACE QuickTurnStudio::Base)

target_include_directories(${LIB_NAME} INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)
