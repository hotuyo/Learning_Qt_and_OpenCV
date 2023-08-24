cmake_minimum_required(VERSION 3.5)

project(Gazer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui Multimedia MultimediaWidgets Concurrent Network)
find_package(OpenCV 4.0.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

#add_definitions(-DGAZER_USE_QT_CAMERA=1)



set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
)

qt_add_executable(Gazer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        capturethread.h capturethread.cpp
        utilities.h utilities.cpp
)


target_link_libraries(Gazer PRIVATE Qt6::Widgets
                        Qt6::Core
                        Qt6::Multimedia
                        Qt6::MultimediaWidgets
                        Qt6::Concurrent
                        Qt6::Network
                        opencv_core
                        opencv_imgproc
                        opencv_video
                        opencv_videoio
                        opencv_highgui
                        )

set_target_properties(Gazer PROPERTIES
                        ${BUNDLE_ID_OPTION}
                        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#                        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
                        MACOSX_BUNDLE TRUE
#                        WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Gazer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(Gazer)

