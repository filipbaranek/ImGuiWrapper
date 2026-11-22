#pragma once
#include <functional>
#include <stdexcept>
#include "Placement.h"

namespace ui::placements
{

    class AnchoredPlacement : public Placement
    {
    public:
        AnchoredPlacement(std::function<ImVec2()> anchor)
            : m_anchor(std::move(anchor))
        {
            if (!m_anchor)
            {
                throw std::logic_error("AnchoredPlacement construction error: anchor function is mandatory");
            }
        }

        void setPosition(ui::styling::WindowPosConfig& pos, const ui::styling::WindowSizeConfig&) const override
        {
            pos.rawPos = m_anchor();
        }

    private:
        std::function<ImVec2()> m_anchor;
    };

} // ui::placements
