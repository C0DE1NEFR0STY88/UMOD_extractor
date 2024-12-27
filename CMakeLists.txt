cmake_minimum_required(VERSION 3.5)

#proj name
project(UMODExtractor)

#set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find required Qt libraries
find_package(Qt5 COMPONENTS Widgets REQUIRED)

#add sources
set(SOURCES
    main.cpp
    umodextractor.cpp
    umodfile.cpp
    )

#add headers
set(HEADERS
    umodextractor.h
    umodfile.h
    )

#add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

#link Qt libraries
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
