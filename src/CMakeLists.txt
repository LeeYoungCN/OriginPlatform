target_include_directories(${LIB_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src CODE_SRCS)
target_sources(${LIB_NAME} PRIVATE ${CODE_SRCS})
