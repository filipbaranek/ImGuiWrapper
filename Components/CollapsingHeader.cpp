#include "CollapsingHeader.h"

namespace ui::components
{

    CollapsingHeader::CollapsingHeader(const std::string& name, std::shared_ptr<ui::styling::IConfig> config)
        : Component(name, std::move(config))
    {
        auto* collapsingHeaderConfig = dynamic_cast<ui::styling::CollapsingHeaderConfig*>(m_config.get());
        if (collapsingHeaderConfig->name.empty())
        {
            collapsingHeaderConfig->name = name;
        }
        if (!collapsingHeaderConfig->name.empty())
        {
            m_name = collapsingHeaderConfig->name;
        }
    }

    void CollapsingHeader::render()
    {
        auto* collapsingHeaderConfig = dynamic_cast<ui::styling::CollapsingHeaderConfig*>(m_config.get());

        if (!collapsingHeaderConfig)
        {
            return;
        }

        const bool isOpen = ui::styling::CollapsingHeader::initConfig(*collapsingHeaderConfig);
        if (!isOpen)
        {
            ui::styling::CollapsingHeader::destroy(*collapsingHeaderConfig);
            return;
        }

        for (auto& layout : m_layouts)
        {
            if (!layout->isVisible())
            {
                continue;
            }

            ui::styling::CollapsingHeader::addToLayout([&]() {
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

        ui::styling::CollapsingHeader::destroy(*collapsingHeaderConfig);
    }

    Layout* CollapsingHeader::emplaceLayout(const ImVec2& margin)
    {
        m_layouts.emplace_back(std::make_unique<Layout>(margin));
        return m_layouts.back().get();
    }

} // namespace ui::components
