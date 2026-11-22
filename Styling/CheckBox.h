#pragma once
#include <string>
#include <imgui.h>
#include "Common.h"
#include "Styling.h"

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

    class CheckBox : public Styling
    {
    public:
        CheckBox(ui::components::CheckBox* checkBox);

    protected:
        void pushStyle() override;

        void popStyle() override;

        void draw() override;

    private:
        ui::components::CheckBox* m_checkBox;
        CheckBoxConfig*           m_config;
    };

} // ui::styling