# 1. 显式定义源码，确保 ExportAPI.cpp 在第一位优先编译
# 注意：严禁将 src/main.cpp 加入此列表，因为它已被 ExportAPI.cpp 包含
set(LIB_SOURCES "hyhyx_patch/ExportAPI.cpp")

# 2. 搜集其他工具类源码
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# ⚠️ 关键优化：必须排除 main.cpp 以免代码重复增加一倍体积
# 同时排除 SpineAtlasDowngrade.cpp
list(FILTER SRC_FILES EXCLUDE REGEX "main.cpp|SpineAtlasDowngrade.cpp")
list(APPEND LIB_SOURCES ${SRC_FILES})

# 3. 定义静态库
add_library(SpineConverterStatic STATIC ${LIB_SOURCES})

# 4. 开启体积优化黑科技 (仅针对 MSVC)
if(MSVC)
    target_compile_options(SpineConverterStatic PRIVATE 
        /Gy # 开启函数级链接 (Function-Level Linking)
        /GF # 合并重复字符串
        /Gw # 优化全局数据
        /O2 # 优化速度和大小
    )
    # 强制不生成调试信息在库内 (减少体积)
    set_target_properties(SpineConverterStatic PROPERTIES 
        COMPILE_PDB_NAME "SpineConverterStatic"
        MSVC_RUNTIME_LIBRARY "MultiThreaded"
    )
endif()

# 5. 标准与路径
target_compile_features(SpineConverterStatic PUBLIC cxx_std_20)
target_include_directories(SpineConverterStatic PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/hyhyx_patch
)
