file(GLOB_RECURSE ALL_SRC "src/*.cpp")
# 必须排除，因为 ExportAPI.cpp 已经 #include 了 main.cpp
list(FILTER ALL_SRC EXCLUDE REGEX "main.cpp|SpineAtlasDowngrade.cpp")

add_library(SpineConverterStatic STATIC ${ALL_SRC} "hyhyx_patch/ExportAPI.cpp")

target_compile_features(SpineConverterStatic PUBLIC cxx_std_20)
target_include_directories(SpineConverterStatic PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/hyhyx_patch
)
