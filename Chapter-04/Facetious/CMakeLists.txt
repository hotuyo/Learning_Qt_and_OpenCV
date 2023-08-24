cmake_minimum_required(VERSION 3.5)

project(Facetious VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui Multimedia MultimediaWidgets)
find_package(OpenCV 4.0.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_definitions(-DOPENCV_DATA_DIR="/usr/local/share/opencv4/")



set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
)

qt_add_executable(Facetious
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        capturethread.h capturethread.cpp
        utilities.h utilities.cpp
        image.qrc
)


target_link_libraries(Facetious PRIVATE Qt6::Widgets
                        Qt6::Core
                        Qt6::Multimedia
                        Qt6::MultimediaWidgets
                        opencv_core
                        opencv_imgproc
                        opencv_video
                        opencv_videoio
                        opencv_highgui
                        opencv_imgcodecs
                        opencv_objdetect
                        opencv_face
                        )

set_target_properties(Facetious PROPERTIES
                        ${BUNDLE_ID_OPTION}
                        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#                        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
                        MACOSX_BUNDLE TRUE
#                        WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Facetious
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(Facetious)

