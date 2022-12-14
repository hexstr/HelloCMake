// hello_cmake.hh: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#ifndef HELLO_CMAKE_HEADER
#define HELLO_CMAKE_HEADER

#include <android/log.h>
#define LOG_TAG "hexstr"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

#endif // hello_cmake.hh

// TODO: 在此处引用程序需要的其他标头。