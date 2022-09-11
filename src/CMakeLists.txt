target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_subdirectory(string_public_func)
add_subdirectory(num_string_format_manager)
add_subdirectory(log_print)
add_subdirectory(platform_basic_func)

FILE(GLOB HEAD_LIST ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h)
install(FILES ${HEAD_LIST} DESTINATION ${HEAD_INSTALL_PATH} COMPONENT ${PROJECT_NAME})