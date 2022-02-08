file(GLOB_RECURSE SOURCES src/*.c)
add_library(lv_chinese_ime STATIC ${SOURCES})
