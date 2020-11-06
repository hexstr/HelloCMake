# CMakeList.txt: HelloCMake 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
# 将源代码添加到此项目的可执行文件。
add_library (HelloCMake SHARED "HelloCMake.cpp" "HelloCMake.h")
find_library(log-lib log)
target_link_libraries( HelloCMake ${log-lib})
# TODO: 如有需要，请添加测试并安装目标。