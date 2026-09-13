cmake_minimum_required(VERSION 3.15)
project(ImGuiWrapper VERSION 1.0.0 LANGUAGES CXX)

set(WRAPPER_SOURCES
    Components/Button.cpp
    Components/Button.h
    Components/CheckBox.cpp
    Components/CheckBox.h
    Components/Component.h
    Components/Dummy.h
    Components/ImageButton.cpp
    Components/ImageButton.h
    Components/InputBox.h
    Components/Label.cpp
    Components/Label.h
    Components/Layout.h
    Components/Linkable.h
    Components/RadioButton.cpp
    Components/RadioButton.h
    Components/RadioImageButton.cpp
    Components/RadioImageButton.h
    Components/SameLine.h
    Components/Separator.h
    Components/Slider.h
    Components/Window.cpp
    Components/Window.h
    Styling/Button.cpp
    Styling/Button.h
    Styling/CheckBox.cpp
    Styling/CheckBox.h
    Styling/Common.h
    Styling/Font.h
    Styling/InputBox.cpp
    Styling/InputBox.h
    Styling/Label.cpp
    Styling/Label.h
    Styling/Slider.h
    Styling/Window.cpp
    Styling/Window.h
    Utils/ImageLoader.cpp
    Utils/ImageLoader.h
    Utils/VisibilityHandler.cpp
    Utils/VisibilityHandler.h
)

add_library(${PROJECT_NAME} STATIC ${WRAPPER_SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC 
        imgui
        glad
        glm
    PRIVATE
        stb
)

if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE NOMINMAX)
endif()
