cmake_minimum_required(VERSION 3.0.0)
project(Tutorial VERSION 0.1.0)

# 版本号
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

# 配置一个头文件，以将某些设置传递到源代码中
configure_file(
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h"
)

# 将目录添加到搜索路径中，以找到 TutorialConfig.h 头文件
include_directories("${PROJECT_BINARY_DIR}")

add_executable(Tutorial tutorial.cpp)