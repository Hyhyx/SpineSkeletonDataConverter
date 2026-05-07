#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 导出 Spine 骨骼数据转换功能
 * @param input_path  输入文件或目录路径
 * @param output_path 输出路径
 * @param version     目标版本号 (如 "4.0")
 * @return 转换是否成功
 */
bool __declspec(dllexport) ConvertSpineData(const char* input_path, const char* output_path, const char* version);

#ifdef __cplusplus
}
#endif
