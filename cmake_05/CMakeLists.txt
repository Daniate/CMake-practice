cmake_minimum_required(VERSION 3.0.0)
project(hello VERSION 0.1.0)

add_executable(hello main.c)

target_include_directories(hello PRIVATE "/usr/local/include")

target_link_directories(hello PRIVATE "/usr/local/lib")

target_link_libraries(hello SDL2 SDL2_gfx SDL2_image SDL2_mixer SDL2_net SDL2_ttf)