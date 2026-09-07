cmake_minimum_required(VERSION 3.15)
project(ImGuiWrapper VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE WRAPPER_SOURCES
    "Components/*.cpp"
    "Components/*.h"
    "Styling/*.cpp"
    "Styling/*.h"
    "Utils/*.cpp"
    "Utils/*.h"
)

add_library(${PROJECT_NAME} STATIC ${WRAPPER_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Components
    ${CMAKE_CURRENT_SOURCE_DIR}/Styling
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC 
        imgui
        glad
        glm
    PRIVATE
        stb
)

set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)

if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE NOMINMAX)
endif()