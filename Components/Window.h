#pragma once
#include <utility>
#include <imgui.h>
#include <glm/glm.hpp>
#include "Styling/Window.h"
#include "Layout.h"

namespace ui::components
{

    class Window
    {
    public:
        virtual ~Window() = default;

        bool clickedOnWindow(const glm::vec2& clickPos);

        bool isVisible();

        template<typename T, typename... Args>
        static std::unique_ptr<T> create(Args&&... args)
        {
            auto  window     = std::make_unique<T>(std::forward<Args>(args)...);
            auto* baseWindow = static_cast<Window*>(window.get());

            baseWindow->initWindowConfig();
            baseWindow->initComponents();

            return window;
        }

    protected:
        Window(const std::string& layerName);

        virtual void initWindowConfig() = 0;

        virtual void initComponents() = 0;

        void render();

        Layout* emplaceLayout(const ImVec2& margin = {});

        template<typename T, typename... Args>
        T* emplaceComponent(Layout* layout, Args&&... args)
        {
            layout->asignComponent(std::make_unique<T>(std::forward<Args>(args)...));
            T* component = dynamic_cast<T*>(layout->components().back().get());
            return component;
        }

    protected:
        ui::styling::WindowConfig            m_windowConfig;
        std::vector<std::unique_ptr<Layout>> m_layouts;

    private:
        std::string m_layerName;
    };

} // ui
