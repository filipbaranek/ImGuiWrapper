#pragma once
#include <string>
#include <imgui.h>
#include "Component.h"

namespace ui::components
{
    class Label;
} // ui::components

namespace ui::styling
{

    struct LabelConfig : IConfig
    {
        ImFont* font;
        ImVec4  color;
    };

    class Label
    {
    public:
        Label() = delete;

        static void render(ui::components::Label* label);
    };

} // ui::styling