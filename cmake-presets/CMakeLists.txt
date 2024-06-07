cmake_minimum_required(VERSION 3.5.0)
project(hello VERSION 0.1.0 LANGUAGES C CXX)

##### 不需要在这里设置 CMAKE_BUILD_TYPE，已在预设中配置过 #####
# set(CMAKE_BUILD_TYPE "Debug")
# set(CMAKE_BUILD_TYPE "Release")
# set(CMAKE_BUILD_TYPE "RelWithDebInfo")
# set(CMAKE_BUILD_TYPE "MinSizeRel")

message("CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE})

add_executable(hello main.cpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

if(${CMAKE_HOST_UNIX})
    message("当前是UNIX or UNIX like (i.e. APPLE and CYGWIN)")
    if(${CMAKE_HOST_APPLE})
        message("当前是macOS系统")
    else()
        message("当前是Linux/其他Unix系统")
    endif(${CMAKE_HOST_APPLE})
elseif(${CMAKE_HOST_WIN32})
    message("当前是Windows系统")
elseif(${CMAKE_HOST_SOLARIS})
    message("当前是Solaris系统")
endif(${CMAKE_HOST_UNIX})

if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
    message("这是Linux系统")
elseif(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
    message("这是Windows系统")
elseif(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin")
    message("这是macOS系统")
endif(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")

message("CMAKE_SYSTEM_NAME: " ${CMAKE_SYSTEM_NAME})
message("CMAKE_HOST_SYSTEM_NAME: " ${CMAKE_HOST_SYSTEM_NAME})
message("CMAKE_SYSTEM_PROCESSOR: " ${CMAKE_SYSTEM_PROCESSOR})
message("CMAKE_HOST_SYSTEM_PROCESSOR: " ${CMAKE_HOST_SYSTEM_PROCESSOR})

# CMAKE_GENERATOR_PLATFORM、CMAKE_GENERATOR_TOOLSET 仅支持 Visual Studio
message("CMAKE_GENERATOR_PLATFORM: " ${CMAKE_GENERATOR_PLATFORM}) # x64
message("CMAKE_GENERATOR_TOOLSET: " ${CMAKE_GENERATOR_TOOLSET}) # host=x64
