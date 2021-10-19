cmake_minimum_required(VERSION 3.19)
project(Qt-CMake-HelloWorld)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(CMAKE_PREFIX_PATH "C:\\QtMultimedia\\6.2.0\\msvc2019_64\\lib\\cmake")


find_package(Qt6Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(EXECUTABLE_OUTPUT_PATH "..\\..\\..\\release")

add_library (pics "src/pics.h" "src/lbp.h")
add_executable(helloworld main.cpp)

target_link_libraries(helloworld Qt6::Widgets)