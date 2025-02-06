cmake_minimum_required(VERSION 3.10)
project(Lenz)

add_subdirectory(external/raylib)

set(SOURCES
    src/main.cpp
)

add_executable(Lenz
    ${SOURCES}
)

target_include_directories(Lenz PRIVATE
    external/raylib
    src
)

target_link_libraries(Lenz PRIVATE
    raylib
    glfw
    GL  
    m 
    dl
    pthread
)

set_target_properties(Lenz PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)