cmake_minimum_required(VERSION 2.8.3)

project(quanta)

# Quanta Versions
set(QUANTA_VERSION_MAJOR 0)
set(QUANTA_VERSION_MINOR 1)

set(CMAKE_CXX_FLAGS "-std=c++11 -W3 -O")

set(QUANTA_SOURCE_DIR ${PROJECT_SOURCE_DIR}/source)
set(QUANTA_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(QUANTA_SOURCES
    
    # Game files
    ${QUANTA_SOURCE_DIR}/Main.cpp
    ${QUANTA_SOURCE_DIR}/quanta/Game.cpp

    # UI files
    ${QUANTA_SOURCE_DIR}/quanta/ui/HexagonShape.cpp
)

set(QUANTA_HEADERS

    # Game files
    ${QUANTA_INCLUDE_DIR}/Main.hpp
    ${QUANTA_INCLUDE_DIR}/quanta/Game.hpp

    # UI Files
    ${QUANTA_INCLUDE_DIR}/quanta/ui/HexagonShape.hpp
)

source_group("Header Files" FILES ${QUANTA_HEADERS})
source_group("Source Files" FILES ${QUANTA_SOURCES})

add_executable(quanta ${QUANTA_SOURCES} ${QUANTA_HEADERS})

include_directories(${QUANTA_INCLUDE_DIR})

if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

if(MSVC)
    if(NOT CMAKE_CXX_FLAGS MATCHES "/EHsc")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc") 
    endif()
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

find_package(SFML 2 COMPONENTS system window graphics REQUIRED)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(quanta ${SFML_LIBRARIES})
endif()


