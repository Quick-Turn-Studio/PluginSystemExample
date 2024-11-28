set(LIB_NAME PluginSample)

aux_source_directory(. SRC_FILES)

add_plugin(PluginSample ${SRC_FILES})
add_library(QuickTurnStudio::${LIB_NAME} ALIAS ${LIB_NAME})

target_link_libraries(${LIB_NAME} PRIVATE QuickTurnStudio::PluginBase)
