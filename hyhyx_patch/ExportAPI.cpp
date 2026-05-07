#include "ExportAPI.h"

// 屏蔽 main
#define main original_main

// 直接包含源文件。
// 注意：不要在之前包含 <string> 或 <vector>，完全复用 main.cpp 的环境。
#include "../src/main.cpp"

// 此时 convertFile 已经在作用域内，且 string 等类型完全对齐
bool ConvertSpineData(const char* input_path, const char* output_path, const char* version) {
    // 基础防御性检查
    if (!input_path || !output_path || !version) return false;

    try {
        // 直接调用。由于我们就在 main.cpp 的编译单元里，
        // 编译器会直接匹配到 bool convertFile(string, string, string)
        return convertFile(input_path, output_path, version);
    } catch (...) {
        return false;
    }
}

#undef main
