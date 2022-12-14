// HelloCMake.cpp: 定义应用程序的入口点。
//
#include "hello_cmake.hh"

int main() {
#if defined(__ARM_ARCH_7A__)
    LOGD("[armeabi-v7a] Hello CMake~");
#elif defined(__aarch64__)
    LOGD("[aarch64] Hello CMake~");
#endif
    return 0;
}