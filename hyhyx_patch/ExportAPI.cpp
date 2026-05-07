#include "ExportAPI.h"
#include <string>

// 屏蔽入口函数并包含逻辑
#define main original_main
#include "../src/main.cpp"
#undef main

bool ConvertSpineData(const char* input_path, const char* output_path, const char* version) {
    if (!input_path || !output_path || !version) return false;
    
    // 显式转换为 std::string 以匹配 main.cpp 中的 bool convertFile(string, string, string)
    return convertFile(
        std::string(input_path), 
        std::string(output_path), 
        std::string(version)
    );
}
