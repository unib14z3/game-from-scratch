cmake_minimum_required(VERSION 3.20)

project(scgame1
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find raylib
find_package(raylib REQUIRED)

# Executable
add_executable(${PROJECT_NAME}
    src/main.cpp
)

# Include directories
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# Link raylib
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        raylib
)
