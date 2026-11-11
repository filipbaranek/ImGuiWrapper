#pragma once
#include <string>
#include <imgui.h>
#include "Common.h"
#include "Styling.h"

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

    class Label : public Styling
    {
    public:
        Label(ui::components::Label* label);

    protected:
        void pushStyle() override;

        void popStyle() override;

        void draw() override;

    private:
        ui::components::Label* m_label;
        LabelConfig*           m_config;
    };

} // ui::styling