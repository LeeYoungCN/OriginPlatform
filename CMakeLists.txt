project(OriginPlatform)
cmake_minimum_required(VERSION 3.4.1)
include(${CMAKE_SOURCE_DIR}/cmake/${CMAKE_SYSTEM_NAME}/os_variable_def.cmake)
set(CMAKE_CXX_STANDARD 17)

set(LIBRARY_OUTPUT_PATH     ${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_INSTALL_PREFIX    ${CMAKE_SOURCE_DIR})
set(RELEASE_APTH            ${CMAKE_SOURCE_DIR}/release)
set(HEAD_INSTALL_PATH       ${RELEASE_APTH}/inc)
set(LIB_INSTALL_PATH        ${RELEASE_APTH}/lib)
set(LIB_CODE_PATH           ${CMAKE_SOURCE_DIR}/src)

set(LIB_NAME    OriginPlatform)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(OPT     "-g")
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    set(OPT     "-O3")
endif()

set(CMAKE_C_FLAGS   "-Wall ${OPT}")
set(CMAKE_CXX_FLAGS "-Wall ${OPT}")

add_library(${LIB_NAME} SHARED)
add_subdirectory(${LIB_CODE_PATH})

file(GLOB LIB_LIST ${LIBRARY_OUTPUT_PATH}/*${DANYMIC_LIBRARY_SUFFIX})
install(FILES ${LIB_LIST} DESTINATION ${LIB_INSTALL_PATH} COMPONENT ${PROJECT_NAME})

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_subdirectory(tests)
endif()