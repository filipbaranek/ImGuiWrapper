#pragma once
#include <imgui.h>
#include <string>
#include <functional>
#include "Common.h"

namespace ui::styling
{

    struct ChildWindowSizeConfig
    {
        float width;     // represents percentage of screen to achieve responsive design - implicitly responsive (no need to define)
        float height;    // represents percentage of screen to achieve responsive design - implicitly responsive (no need to define)
        float minWidth;  // represents percentage of screen to achieve responsive design
        float minHeight; // represents percentage of screen to achieve responsive design
        ImVec2 rawSize;  // used automaticly by IWindow class
        ImVec2 realSize; // auto fit size value
    };

    struct ChildWindowConfig : IConfig
    {
        std::string name;
        ImVec4 backgroundColor;
        float rounding;
        float borderSize = 1.0f;
        ImVec2 padding{0,0};
        ImGuiChildFlags childFlags = ImGuiChildFlags_None;
        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_None;
        ChildWindowSizeConfig size;
    };

    class ChildWindow
    {
    public:
        ChildWindow() = delete;

        static void setSize(ChildWindowConfig &config);

        static void setRelativeSize(ChildWindowConfig &config);

        static void init(ChildWindowConfig &config);

        static void destroy(ChildWindowConfig &config);

        static void addToLayout(std::function<void()> asignComponents, const ImVec2 &margin = {});
    };
} // ui::styling