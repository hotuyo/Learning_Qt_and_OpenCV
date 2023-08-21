cmake_minimum_required(VERSION 3.14)

project(RotatePlugin LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(RotatePlugin SHARED
  RotatePlugin_global.h
  rotateplugin.cpp
  rotateplugin.h
)

include_directories(/usr/local/opencv/include/opencv4)
link_directories(/usr/local/opencv/lib)
include_directories(. ../ImageEditor/ImageEditor)

target_link_libraries(RotatePlugin PRIVATE Qt${QT_VERSION_MAJOR}::Core
                                                    opencv_core
                                                    opencv_imgproc)

target_compile_definitions(RotatePlugin PRIVATE ROTATEPLUGIN_LIBRARY)

set_target_properties(RotatePlugin PROPERTIES
    VERSION 1.0.0
)
