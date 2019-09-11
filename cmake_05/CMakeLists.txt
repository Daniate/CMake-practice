cmake_minimum_required(VERSION 3.0.0)
project(hello VERSION 0.1.0)

add_executable(${PROJECT_NAME} main.c)

#
# https://cmake.org/cmake/help/latest/module/FindPkgConfig.html
#
# pkg_check_modules(<prefix>
#                   [REQUIRED] [QUIET]
#                   [NO_CMAKE_PATH]
#                   [NO_CMAKE_ENVIRONMENT_PATH]
#                   [IMPORTED_TARGET [GLOBAL]]
#                   <moduleSpec> [<moduleSpec>...])
#
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2_LIBS REQUIRED IMPORTED_TARGET sdl2 SDL2_image SDL2_mixer SDL2_net SDL2_ttf)

# target_include_directories(hello PRIVATE "/usr/local/include")
# target_link_directories(hello PRIVATE "/usr/local/lib")

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_LIBS_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} PkgConfig::SDL2_LIBS)
