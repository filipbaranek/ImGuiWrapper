#pragma once
#include "Placement.h"

namespace ui::placements
{

    class CenteredPlacement : public Placement
    {
    public:
        void setPosition(ui::styling::WindowPosConfig& pos, const ui::styling::WindowSizeConfig& size) const override
        {
            const ImGuiViewport* viewport = ImGui::GetMainViewport();

            pos.rawPos = ImVec2{
                viewport->Pos.x + (viewport->Size.x - size.rawSize.x) * 0.5f,
                viewport->Pos.y + (viewport->Size.y - size.rawSize.y) * 0.5f
            };
        }
    };

} // ui::placements
