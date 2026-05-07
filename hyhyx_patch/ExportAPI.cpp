#include "ExportAPI.h"

// 1. 屏蔽 main 入口
#define main original_main
#include "../src/main.cpp"
#undef main

bool ConvertSpineData(const char* input_path, const char* output_path, const char* version) {
    if (!input_path || !output_path || !version) return false;

    std::string inPath = input_path;
    std::string outPath = output_path;
    std::string verStr = version;

    // 2. 复用 main.cpp 里的解析函数
    // 解析目标版本枚举
    SpineVersion outVer = parseVersionString(verStr);
    if (outVer == SpineVersion::Invalid) return false;

    // 识别输入格式
    FileFormat inFmt = (inPath.ends_with(".json")) ? FileFormat::Json : FileFormat::Skel;
    // 识别输出格式
    FileFormat outFmt = (outPath.ends_with(".json")) ? FileFormat::Json : FileFormat::Skel;
    
    // 自动检测输入文件的版本
    SpineVersion inVer = detectSpineVersion(inPath);

    // 3. 调用 8 参数的核心函数
    return convertFile(
        inPath,      // inputFile
        outPath,     // outputFile
        inFmt,       // inputFormat
        outFmt,      // outputFormat
        inVer,       // inputVersion
        outVer,      // outputVersion
        verStr,      // outputVersionString (这里传完整的三段式版本号)
        false        // removeCurveOption
    );
}
