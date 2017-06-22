cmake_minimum_required(VERSION 3.5)
project(StringLibrary)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -g -Wall -Wextra -pedantic")

set(INCL_DIR include)
set(SRC_DIR src)
set(TEST_DIR tests)

set(SOURCE_FILES ${SRC_DIR}/stringlib.c)
set(HEADER_FILES ${INCL_DIR}/stringlib.h)

set(TEST_FILES ${TEST_DIR}/test_stringlib.c)

add_executable(stringlib_tests ${SOURCE_FILES} ${TEST_FILES} ${INCL_DIR})
# target_compile_definitions(hw02_tests PRIVATE __USE_MINGW_ANSI_STDIO=1)