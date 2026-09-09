#pragma once
#include <imgui.h>
#include "Component.h"

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
