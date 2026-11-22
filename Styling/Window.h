#pragma once
#include <imgui.h>
#include <string>
#include <functional>
#include "Common.h"

namespace ui::placements
{
    class Placement;
} // ui::placements

namespace ui::styling
{

    struct WindowPosConfig
    {
        ImVec2 rawPos;            // used automaticly by Window class
    };

    struct WindowSizeConfig
    {
        float  width;       // represents percentage of screen to achieve responsive design - implicitly responsive (no need to define)
        float  height;      // represents percentage of screen to achieve responsive design - implicitly responsive (no need to define)
        float  minWidth;    // represents percentage of screen to achieve responsive design
        float  minHeight;   // represents percentage of screen to achieve responsive design
        ImVec2 rawSize;     // used automaticly by IWindow class
        ImVec2 realSize;    // auto fit size value
    };

    struct WindowTitleBarConfig
    {
        ImVec4  background;
        ImFont* font;
    };

    struct WindowConfig
    {
        std::string          name;
        std::string          layerName;
        ImVec4               backgroundColor;
        float                rounding;
        ImGuiWindowFlags     flags;
        WindowPosConfig      pos;
        WindowSizeConfig     size;
        WindowTitleBarConfig titleBar;
        AppliedStyling       styles;
    };

    class Window
    {
    public:
        Window() = delete;

        static void setSize(WindowConfig& config);

        static void setPos(WindowConfig& config, const ui::placements::Placement& placement);

        static void init(WindowConfig& config);

        static void destroy(WindowConfig& config);

        static void addToLayout(std::function<void()> asignComponents, const ImVec2& margin = {});
    };
} // ui::styling