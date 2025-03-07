 cmake_minimum_required(VERSION 3.20)
 set(CMAKE_UTF8_MODE 1)
 # 设置项目名称并指定使用的语言
 project(smzy_study LANGUAGES C CXX)

 # 设置 C 和 C++ 标准
 set(CMAKE_C_STANDARD 11)
 set(CMAKE_CXX_STANDARD 17)

 # 强制使用指定的标准并禁用编译器扩展以提高可移植性
 set(CMAKE_C_STANDARD_REQUIRED ON)


 set(CMAKE_CXX_STANDARD_REQUIRED ON)
 set(CMAKE_C_EXTENSIONS OFF)
 set(CMAKE_CXX_EXTENSIONS OFF)

 # 定义可执行目标
 add_executable(smzy
  cpp_study/day_61_c++_review_2/test1.cpp
 )
 # 为目标设置包含目录
 #target_include_directories(smzy PRIVATE ${PROJECT_SOURCE_DIR}/include) 放置头文件

 # 可选：为提高代码质量添加编译器警告
 if (MSVC)
     target_compile_options(smzy PRIVATE /W4)
 else()
     target_compile_options(smzy PRIVATE -Wall -Wextra -pedantic)
 endif()