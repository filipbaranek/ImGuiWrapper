#pragma once
#include <imgui.h>
#include "Common.h"

namespace ui::components
{

    class SameLine : public Component
    {
    public:
        SameLine()
            : Component({}, {})
        { }

        void render() override
        {
            ImGui::SameLine();
        }
    };

} // ui::components
