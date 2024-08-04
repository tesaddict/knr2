cmake_minimum_required(VERSION 3.1...3.29)

project(
  KNR2
  VERSION 1.0
  LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(libknr2 libknr2/knr2_string.c libknr2/knr2_string.h)

add_executable(knr2 src/main.c src/chapter_one.c)
include_directories(libknr2/ inc/)

target_link_libraries(knr2 PRIVATE libknr2)
