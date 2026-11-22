#pragma once
#include "Placement.h"

namespace ui::placements
{

    class ViewportPlacement : public Placement
    {
    public:
        ViewportPlacement(float x, float y)
            : m_x(x)
            , m_y(y)
        { }

        void setPosition(ui::styling::WindowPosConfig& pos, const ui::styling::WindowSizeConfig&) const override
        {
            const ImGuiViewport* viewport = ImGui::GetMainViewport();

            pos.rawPos = ImVec2{
                viewport->Pos.x + m_x * viewport->Size.x,
                viewport->Pos.y + m_y * viewport->Size.y
            };
        }

    private:
        float m_x;
        float m_y;
    };

} // ui::placements
