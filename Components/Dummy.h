#pragma once
#include <imgui.h>
#include "Component.h"

namespace ui::components
{

    class Dummy : public Component
    {
    public:
        Dummy(float x, float y)
            : Component({}, {})
            , m_x(x)
            , m_y(y)
        { }

        void render() override
        {
            ImGui::Dummy(ImVec2{ImGui::GetWindowSize().x * m_x, ImGui::GetWindowSize().y * m_y});
        }

    private:
        float m_x;
        float m_y;
    };

    class RelativeDummy : public Component
    {
    public:
        RelativeDummy(float x, float y)
            : Component({}, {})
            , m_x(x)
            , m_y(y)
        { }

        void render() override
        {
            ImGui::Dummy(ImVec2{m_x, m_y});
        }

    private:
        float m_x;
        float m_y;
    };

} // ui::components
