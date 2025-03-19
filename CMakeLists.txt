cmake_minimum_required(VERSION 3.29)
project(lectureTask)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH "/home/radamir/Qt/6.8.2/gcc_64/lib/cmake/")


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(FORMS
        mainwindow.ui
)
add_executable(lectureTask main.cpp)
add_library(Library_lib STATIC Book.cpp Library.cpp)
add_subdirectory(Google_tests)
target_link_libraries(lectureTask

        Qt::Core
        Qt::Gui
        Qt::Widgets stdc++

)
target_link_libraries(Library_lib
        Qt::Core
        Qt::Gui
        Qt::Widgets stdc++
)
target_link_libraries(lectureTask Library_lib)

