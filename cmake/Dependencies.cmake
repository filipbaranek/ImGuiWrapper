# Provides the targets ImGuiWrapper links against (imgui, glad, glm, stb) for a standalone build.
# When ImGuiWrapper is added to another project, that project provides these targets instead.

include(FetchContent)

FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        v1.92.5-docking
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(imgui)

add_library(imgui STATIC
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
)
target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})
set_target_properties(imgui PROPERTIES POSITION_INDEPENDENT_CODE ON)

FetchContent_Declare(
    stb
    GIT_REPOSITORY https://github.com/nothings/stb.git
    GIT_TAG        4e9b368bfc071e97206ea5c6adba68dd0cbf8897
)
FetchContent_MakeAvailable(stb)

add_library(stb INTERFACE)
target_include_directories(stb INTERFACE ${stb_SOURCE_DIR})

set(GLM_BUILD_LIBRARY OFF CACHE BOOL "Use GLM as a header-only library")
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG        1.0.1
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(glm)

enable_language(C)
FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG        73db193f853e2ee079bf3ca8a64aa2eaf6459043
    SOURCE_SUBDIR  cmake
)
FetchContent_MakeAvailable(glad)

glad_add_library(glad_core STATIC REPRODUCIBLE LOADER API gl:core=3.3)
set_target_properties(glad_core PROPERTIES POSITION_INDEPENDENT_CODE ON)
add_library(glad ALIAS glad_core)
