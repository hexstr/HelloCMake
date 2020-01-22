// ModFGO.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once
#include "android/log.h"
#define LOG_TAG "ethereal"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
// TODO: 在此处引用程序需要的其他标头。