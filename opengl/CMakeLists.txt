cmake_minimum_required(VERSION 3.28.0)                  #版本号
project(opengl)                                         #项目名

set(CMAKE_CXX_STANDARD 17)                              #设置C++标准
include_directories(include)                           #把include纳入包含目录中
link_libraries("${PROJECT_SOURCE_DIR}/lib/glfw3.lib") #链接之前生成的静态库文件
aux_source_directory(./src DIR_ALL_SRC)			   #src目录下所有文件取个DIR_ALL_SRC名字
add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)


add_executable(opengl ${DIR_ALL_SRC})                   #生成可执行文件
target_include_directories(opengl PRIVATE include)     #指定头文件目录
target_link_libraries(opengl PRIVATE "${PROJECT_SOURCE_DIR}/lib/glfw3.lib")                     #链接glfw3库

