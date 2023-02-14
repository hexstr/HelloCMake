# CMakeList.txt: HelloCMake 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ANDROID_STL_TYPE c++_shared)
set(LibraryName HelloCMake)

# 文件写出位置
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/libs/${ANDROID_ABI})

# 处理Debug和Release版本的flags
string(TOUPPER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE_UP)
set(LINKER_FLAGS "")
set(COMPILER_FLAGS "")
if(CMAKE_BUILD_TYPE_UP STREQUAL DEBUG)
    message(STATUS "Debug Version")
    set(LINKER_FLAGS "-g")
else()
    message(STATUS "=== Remove debug information and symbols ===")
    set(COMPILER_FLAGS "${COMPILER_FLAGS} -Oz -flto")
    set(LINKER_FLAGS "${LINKER_FLAGS} -s -Wl,--exclude-libs,ALL -Wl,--gc-sections -flto")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILER_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_LIBCPP_DISABLE_VISIBILITY_ANNOTATIONS -fno-exceptions -fno-rtti")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LINKER_FLAGS}")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${LINKER_FLAGS}")

# 将源代码添加到此项目的可执行文件。
aux_source_directory(${PROJECT_SOURCE_DIR}/${LibraryName} program-src)

add_library (${LibraryName}
    SHARED
    ${program-src}
)
target_link_libraries(${LibraryName} log)