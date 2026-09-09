#pragma once
#include <string>
#include <imgui.h>
#include "Component.h"

namespace ui::components
{
    class CheckBox;
} // ui::components

namespace ui::styling
{

    struct CheckBoxConfig : IConfig
    {
        ImVec4         checkMarkColor;
        ImVec4         background;
        ImVec4         hoveredBackground;
        ImVec4         activeBackground;
        ImVec2         framePadding;
    };

    class CheckBox
    {
    public:
        CheckBox() = delete;

        static void render(ui::components::CheckBox* checkBox);
    };

} // ui::styling