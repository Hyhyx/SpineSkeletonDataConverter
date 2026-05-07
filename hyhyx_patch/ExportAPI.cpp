#include "ExportAPI.h"
#include <string>

// 屏蔽入口函数并包含逻辑
#define main original_main
#include "../src/main.cpp"
#undef main

bool ConvertSpineData(const char* input_path, const char* output_path, const char* version) {
    if (!input_path || !output_path || !version) return false;
    
    // 直接复用 main.cpp 里的核心函数
    return convertFile(input_path, output_path, version);
}
