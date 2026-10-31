#pragma once
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <imgui.h>
#include "Component.h"
#include "Layout.h"
#include "Styling/ChildWindow.h"

namespace ui::components
{

    class ChildWindow : public Component
    {
    public:
        ~ChildWindow() override = default;
        void render() override;
        Layout* emplaceLayout(const ImVec2& margin = {});

        template<typename T, typename... Args>
        T* emplaceComponent(Layout* layout, Args&&... args)
        {
            layout->asignComponent(std::make_unique<T>(std::forward<Args>(args)...));
            T* component = dynamic_cast<T*>(layout->components().back().get());
            return component;
        }
    ChildWindow(const std::string& name, std::shared_ptr<ui::styling::IConfig> config);

    protected:
        std::vector<std::unique_ptr<Layout>> m_layouts;
    };

} // namespace ui::components
