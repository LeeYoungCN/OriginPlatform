project(OriginPlatform)
cmake_minimum_required(VERSION 3.4.1)
include(${CMAKE_SOURCE_DIR}/cmake/${CMAKE_SYSTEM_NAME}/os_variable_def.cmake)
set(CMAKE_CXX_STANDARD 17)

set(LIBRARY_OUTPUT_PATH     ${CMAKE_SOURCE_DIR}/lib)

if (CMAKE_INSTALL_PREFIX MATCHES /usr/local)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/release CACHE STRING "Default install path" FORCE)
endif()

if (NOT HEAD_FILE_INSTALL_PATH)
    set(HEAD_FILE_INSTALL_PATH ${CMAKE_INSTALL_PREFIX}/inc CACHE STRING "Default head file install path" FORCE)
endif()

if (NOT LIB_INSTALL_PATH)
    set(LIB_INSTALL_PATH ${CMAKE_INSTALL_PREFIX}/lib CACHE STRING "Library head file install path" FORCE)
endif()

set(LIB_NAME OriginPlatform)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(OPT     "-g -O0")
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    set(OPT     "-O3")
endif()

set(CMAKE_C_FLAGS   "-Wall ${OPT}")
set(CMAKE_CXX_FLAGS "-Wall ${OPT}")

add_library(${LIB_NAME} SHARED)
add_subdirectory(src)

file(GLOB LIB_LIST ${LIBRARY_OUTPUT_PATH}/*${DANYMIC_LIBRARY_SUFFIX})
install(FILES ${LIB_LIST} DESTINATION ${LIB_INSTALL_PATH} COMPONENT ${PROJECT_NAME})

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_subdirectory(tests)
endif()
