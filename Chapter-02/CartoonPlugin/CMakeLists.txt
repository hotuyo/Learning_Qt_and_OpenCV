cmake_minimum_required(VERSION 3.14)

project(CartoonPlugin LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(CartoonPlugin SHARED
  CartoonPlugin_global.h
  cartoonplugin.cpp
  cartoonplugin.h
)
include_directories(/usr/local/opencv/include/opencv4)
link_directories(/usr/local/opencv/lib)
include_directories(. ../ImageEditor/ImageEditor)

target_link_libraries(CartoonPlugin PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    opencv_core
    opencv_imgproc)

target_compile_definitions(CartoonPlugin PRIVATE CARTOONPLUGIN_LIBRARY)

set_target_properties(CartoonPlugin PROPERTIES
    VERSION 1.0.0
    SOVERSION 1
)
