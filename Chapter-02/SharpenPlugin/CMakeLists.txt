cmake_minimum_required(VERSION 3.14)

project(SharpenPlugin LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

include_directories(. ../ImageEditor/ImageEditor)
include_directories(/usr/local/opencv/include/opencv4)
link_directories(/usr/local/opencv/lib)

add_library(SharpenPlugin SHARED
  sharpenplugin.cpp
  sharpenplugin.h
)

target_link_libraries(SharpenPlugin PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets
                            opencv_core
                            opencv_imgproc)

target_compile_definitions(SharpenPlugin PRIVATE SHARPENPLUGIN_LIBRARY)

set_target_properties(SharpenPlugin PROPERTIES
    VERSION 1.0.0
    SOVERSION 1
)
