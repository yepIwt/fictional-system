message(
    "
    Fictional-system is a neural network for face recognition.
    Written by Vyacheslav Roshchin and Nikita Sergievsky.
    Windows + Linux and MiniGW + MVStuido.
    "
)

cmake_minimum_required(VERSION 3.19)
project(Fictional-System)
set(username $ENV{USERNAME})
set(compiler "g++")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.1.3\\mingw81_64\\lib\\cmake")

if (WIN32)
    if (username MATCHES "Вячеслав")
        set(CMAKE_CXX_COMPILER MVSC)
        set(CMAKE_PREFIX_PATH "C:\\QtNikita\\6.1.3\\msvc2019_64\\lib\\cmake")
        set(compiler "MSVC")
    endif (username MATCHES "Вячеслав")
else()
    set(CMAKE_PREFIX_PATH "~/Qt/6.1.3/mingw81_64/lib/cmake")
endif (WIN32)

if (compiler MATCHES "MSVC")
    message("Using MSVC")
else ()
    message("Using MiniGW")
endif (compiler MATCHES "MSVC")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(EXECUTABLE_OUTPUT_PATH "..\\release")

add_library (
    PICS 
    src/pics/pics.h
    src/pics/lbp.h
)

add_library (
    NET
    src/net/gist.h
    src/net/algen.h
    src/net/countmask.h
    src/net/prefim.h
    src/net/create_w.h
)

add_executable(fict main.cpp)
target_link_libraries(fict Qt6::Widgets)