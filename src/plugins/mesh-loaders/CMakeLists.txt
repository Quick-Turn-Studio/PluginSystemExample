set(LIB_NAME StandardMeshLoaders)

aux_source_directory(. SRC_FILES)

add_plugin(${LIB_NAME} ${SRC_FILES})
add_library(QuickTurnStudio::${LIB_NAME} ALIAS ${LIB_NAME})

target_link_libraries(${LIB_NAME} PRIVATE QuickTurnStudio::PluginBase)
target_link_libraries(${LIB_NAME} PUBLIC QuickTurnStudio::MeshLoadersModuleInterface)
