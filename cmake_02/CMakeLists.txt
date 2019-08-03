# 所要求的 cmake 最低版本
cmake_minimum_required(VERSION 3.0.0)

# 指定项目名称 Hello
project(Hello VERSION 0.1.0)

# 生成库文件 mymath
add_library(mymath my_math.c)

# 链接库文件 mymath。注：官方建议使用 target_link_libraries，见下方
# link_libraries(mymath)

# 生成可执行文件 a.out
add_executable(a.out main.c)

# 将库文件 mymath 链接到可执行文件 a.out
target_link_libraries(a.out mymath)