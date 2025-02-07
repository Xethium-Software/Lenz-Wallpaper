cmake_minimum_required(VERSION 3.10)
project(Lenz)

find_package(X11 REQUIRED)

add_subdirectory(external/raylib)

set(SOURCES
    src/main.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(Lenz
    ${SOURCES}
)

target_link_libraries(Lenz PRIVATE
    raylib
    glfw
    GL  
    m 
    dl
    pthread
    ${X11_LIBRARIES}
)

set_target_properties(Lenz PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)