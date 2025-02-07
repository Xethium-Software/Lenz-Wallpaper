cmake_minimum_required(VERSION 3.10)
project(Lenz)

# Find X11 libraries
find_package(X11 REQUIRED)

# Add raylib subdirectory
add_subdirectory(external/raylib)

# Set source files
set(SOURCES
    src/main.cpp
)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Create the executable
add_executable(Lenz
    ${SOURCES}
)

# Link libraries
target_link_libraries(Lenz PRIVATE
    raylib
    glfw
    GL  
    m 
    dl
    pthread
    ${X11_LIBRARIES}
)

# Set C++ standard
set_target_properties(Lenz PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)