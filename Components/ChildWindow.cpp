#include "ChildWindow.h"
#include "Utils/VisibilityHandler.h"

namespace ui::components
{

    ChildWindow::ChildWindow(const std::string& name, std::shared_ptr<ui::styling::IConfig> config)
        : Component(name, std::move(config))
    { }

    void ChildWindow::render()
    {
        auto* childWindowConfig = dynamic_cast<ui::styling::ChildWindowConfig*>(m_config.get());

        ui::styling::ChildWindow::setSize(*childWindowConfig);
        ui::styling::ChildWindow::init(*childWindowConfig);

        for (auto& layout : m_layouts)
        {
            if (!layout->isVisible())
            {
                continue;
            }

            ui::styling::ChildWindow::addToLayout([&]() {
                for (auto& component : layout->components())
                {
                    if (component->isVisible())
                    {
                        component->render();
                    }
                    else
                    {
                        ImGui::Dummy(ImVec2{0.0f, ImGui::GetFrameHeight()});
                    }
                }
            }, layout->margin());
        }

        ui::styling::ChildWindow::destroy(*childWindowConfig);
    }

    Layout* ChildWindow::emplaceLayout(const ImVec2& margin)
    {
        m_layouts.emplace_back(std::make_unique<Layout>(margin));
        return m_layouts.back().get();
    }

} // namespace ui::components
