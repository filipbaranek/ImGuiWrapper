#pragma once

#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <imgui.h>

#include "Component.h"
#include "Layout.h"
#include "Styling/CollapsingHeader.h"

namespace ui::components
{

    class CollapsingHeader : public Component
    {
    public:
        ~CollapsingHeader() override = default;

        void render() override;
        Layout* emplaceLayout(const ImVec2& margin = {});
        CollapsingHeader(const std::string& name, std::shared_ptr<ui::styling::IConfig> config);

        template<typename T, typename... Args>
        T* emplaceComponent(Layout* layout, Args&&... args)
        {
            layout->asignComponent(std::make_unique<T>(std::forward<Args>(args)...));
            return dynamic_cast<T*>(layout->components().back().get());
        }

    protected:
        std::vector<std::unique_ptr<Layout>> m_layouts;
    };

} // namespace ui::components
