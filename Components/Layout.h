#pragma once
#include <memory>
#include <utility>
#include <vector>
#include <imgui.h>
#include "Components/Component.h"
#include "Styling/Window.h"

namespace ui::components
{

    class Layout : public Component
    {
    public:
        Layout(const ImVec2& margin = {})
            : Component({}, {})
            , m_margin(margin)
        { }

        void render() override
        {
            ui::styling::Window::addToLayout([&]() {
                for (auto& component : m_components)
                {
                    if (component->isVisible())
                    {
                        component->render();
                    }
                    else
                    {
                        ImGui::Dummy(ImVec2{ 0.0f, ImGui::GetFrameHeight() });
                    }
                }
            }, m_margin);
        }

        const ImVec2& margin() const
        {
            return m_margin;
        }

        const std::vector<std::unique_ptr<Component>>& components() const
        {
            return m_components;
        }

        void reserveComponents(int count)
        {
            m_components.reserve(count);
        }

        void asignComponent(std::unique_ptr<Component> component)
        {
            m_components.emplace_back(std::move(component));
        }

    private:
        const ImVec2                            m_margin;
        std::vector<std::unique_ptr<Component>> m_components;
    };

} // ui
