#pragma once
#include "Styling/Window.h"

namespace ui::placements
{

    class Placement
    {
    public:
        virtual ~Placement() = default;

        virtual void setPosition(ui::styling::WindowPosConfig& pos, const ui::styling::WindowSizeConfig& size) const = 0;
    };

} // ui::placements
