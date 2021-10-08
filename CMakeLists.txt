cmake_minimum_required(VERSION 3.21)
project(Qt-CMake-HelloWorld)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(CMAKE_PREFIX_PATH "/home/sergievsky/Qt/6.1.3/gcc_64/lib/cmake/")


find_package(Qt6Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(EXECUTABLE_OUTPUT_PATH "..\\release")

add_library (pics "src/pics.h")
add_executable(helloworld main.cpp)

target_link_libraries(helloworld Qt6::Widgets)