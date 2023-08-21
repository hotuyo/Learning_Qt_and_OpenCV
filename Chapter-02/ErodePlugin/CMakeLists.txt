cmake_minimum_required(VERSION 3.14)

project(ErodePlugin LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt6 REQUIRED COMPONENTS Widgets)
message(STATUS "Qt6 Widgets Include Dir: ${Qt6Widgets_INCLUDE_DIRS}")
message(STATUS "Qt6 Widgets Library Dir: ${Qt6Widgets_LIBRARIES}")

include_directories(/usr/local/opencv/include/opencv4)
link_directories(/usr/local/opencv/lib)
include_directories(. ../ImageEditor/ImageEditor)

add_library(ErodePlugin SHARED
    erode_plugin.h
    erode_plugin.cpp

)

target_link_libraries(ErodePlugin PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(ErodePlugin PRIVATE Qt${QT_VERSION_MAJOR}::Widgets


                        opencv_core
                        opencv_imgproc
                        )

target_compile_definitions(ErodePlugin PRIVATE ERODEPLUGIN_LIBRARY)

set_target_properties(ErodePlugin PROPERTIES
    VERSION 1.0.0
    SOVERSION 1
)


