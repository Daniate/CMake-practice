cmake_minimum_required(VERSION 3.0.0)
project(Tutorial VERSION 0.1.0)

# 版本号
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

include(CheckFunctionExists)
check_function_exists(log EXISTS_LOG)
check_function_exists(exp EXISTS_EXP)

message("\${EXISTS_LOG} is ${EXISTS_LOG}")
message("\${EXISTS_EXP} is ${EXISTS_EXP}")

# 是否使用自己的数学函数
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# 配置一个头文件，以将某些设置传递到源代码中
configure_file(
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h"
)

# 将目录添加到搜索路径中，以找到 TutorialConfig.h 头文件
include_directories("${PROJECT_SOURCE_DIR}")

# 是否添加 MathFunctions 库
if(USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory(MathFunctions)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(USE_MYMATH)

add_executable(Tutorial tutorial.cpp)

target_link_libraries(Tutorial ${EXTRA_LIBS})

install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_SOURCE_DIR}/TutorialConfig.h" DESTINATION include)

include(CTest)

# 程序是否可以运行
add_test(TutorialRuns Tutorial 25)
# 25的平方根
add_test(TutorialComp25 Tutorial 25)
set_tests_properties (TutorialComp25 PROPERTIES PASS_REGULAR_EXPRESSION "25.000000 is 5.000000")
# 处理负数
add_test(TutorialNegative Tutorial -25)
set_tests_properties(TutorialNegative PROPERTIES PASS_REGULAR_EXPRESSION "-25.000000 is 0.000000")
# 处理小数
add_test(TutorialSmall Tutorial 0.0001)
set_tests_properties(TutorialSmall PROPERTIES PASS_REGULAR_EXPRESSION "0.000100 is 0.010000")
# 提示如何使用该程序的信息，是否有效
add_test(TutorialUsage Tutorial)
set_tests_properties(TutorialUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")
