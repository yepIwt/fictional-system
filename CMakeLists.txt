cmake_minimum_required(VERSION 3.19)
project(Qt-CMake-HelloWorld)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(CMAKE_PREFIX_PATH "C:\\QtNikita\\6.1.3\\msvc2019_64\\lib\\cmake")


find_package(Qt6Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(EXECUTABLE_OUTPUT_PATH "..\\..\\..\\release")

add_library (pics "release/src/pics.h" "release/src/lbp.h" "net/gist.h" "net/algen.h" "net/countmask.h" "net/prefim.h" "net/create_w.h")

add_executable(helloworld main.cpp "net/gist.h" "net/algen.h" "net/countmask.h" "net/prefim.h" "net/create_w.h")

target_link_libraries(helloworld Qt6::Widgets)