message(
    "
    Fictional-system is a neural network for face recognition.
    Written by Vyacheslav Roshchin and Nikita Sergievsky.
    Windows + Linux and MiniGW + MVStuido.
    "
)

cmake_minimum_required(VERSION 3.19)
project(FictionalSystem)
set(username $ENV{USERNAME})

# yepIwt config laptop
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.1.3\\mingw81_64\\lib\\cmake")
set(EXECUTABLE_OUTPUT_PATH "..\\release")

if (WIN32)
    # bg1622h config laptop
    if (username MATCHES "Вячеслав")
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
    set(CMAKE_PREFIX_PATH "C:\\Qt\\6.1.3\\mingw81_64\\lib\\cmake")
    set(EXECUTABLE_OUTPUT_PATH "..\\..\\..\\release")
    endif (username MATCHES "Вячеслав")
else()
    # yepiwt config laptop
    set(CMAKE_PREFIX_PATH "~/Qt/6.1.3/mingw81_64/lib/cmake")
endif (WIN32)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Build and link
add_library (
    PICS 
    "src/pics/set/pics.h"
    "src/pics/set/lbp.h"
)

add_library (
    NET
    #"src/net/templates/algen.h"
    #"src/net/countmask.h"
    #"src/net/structure/prefim.h"
    #"src/net/templates/create_w.h"
)
add_library(
    LEARNING
    "src/learning/adaboost.h"
  #  "src/learning/countmask.h"
   # "src/learning/create_w.h"
)
add_library(
    STRUCT
    "src/struct/algen.h"
    "src/struct/prefim.h"
    "src/struct/shab.h"
    "src/struct/sigmoid.h"
)

add_library(
    SRC
    "src/learning.h"
    "src/net.h"
    "src/pics_get.h"
    "src/pics_set.h"
)
add_executable(fict main.cpp ${SRC})

target_link_libraries(fict Qt6::Widgets)
