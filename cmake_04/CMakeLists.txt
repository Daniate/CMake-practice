cmake_minimum_required(VERSION 3.0.0)
project(Hello VERSION 0.1.0)

configure_file(
    "config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

option(USE_MY_MATH "Use our math implementation" ON)

if(USE_MY_MATH)
    add_subdirectory(math)
endif(USE_MY_MATH)

include_directories("${PROJECT_BINARY_DIR}")

# 链接库文件 mymath。注：官方建议使用 target_link_libraries
# link_libraries(mymath)

# 生成可执行文件 Hello
add_executable(Hello main.c)

if(USE_MY_MATH)
    # 将库文件 mymath 链接到可执行文件 Hello
    target_link_libraries(Hello mymath)
endif(USE_MY_MATH)