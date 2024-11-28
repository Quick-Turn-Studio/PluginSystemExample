set(APP_NAME Application)

aux_source_directory(. SRC_FILES)

add_executable(${APP_NAME} ${SRC_FILES})

target_link_libraries(${APP_NAME} PRIVATE QuickTurnStudio::PluginLoader)
target_link_libraries(${APP_NAME} PRIVATE QuickTurnStudio::GraphicsModuleInterface)
target_link_libraries(${APP_NAME} PRIVATE QuickTurnStudio::MeshLoadersModuleInterface)

include(QtsPlugin)

target_plugin_dependency(${APP_NAME}
        PLUGINS
            QuickTurnStudio::PluginSample
            QuickTurnStudio::OpenGLGraphics
#                QuickTurnStudio::StandardMeshLoaders
        DEPLOY_PATH plugins
)