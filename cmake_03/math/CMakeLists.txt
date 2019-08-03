# 所要求的 cmake 最低版本
cmake_minimum_required(VERSION 3.0.0)

# 生成动态链接库文件 mymath，最终的库文件名为 libmymath.dylib
add_library(mymath SHARED my_math.c)
