#pragma once
#include <memory>
#include <stdexcept>
#include "Bindings/Binding.h"
#include "Components/Component.h"
#include "Styling/Slider.h"

namespace ui::components
{

    template<typename T>
    class Slider : public Component
    {
    public:
        Slider(
            const std::string&                        name,
            std::shared_ptr<ui::bindings::Binding<T>> value,
            std::shared_ptr<ui::styling::IConfig>     config)
            : Component("##" + name, std::move(config))
            , m_value(std::move(value))
        {
            if (m_value == nullptr)
            {
                throw std::logic_error("Slider construction error: value binding is mandatory");
            }
        }

        void render() override
        {
            ui::styling::Slider<T>(m_name, *m_value, m_config.get()).render();
        }

    private:
        std::shared_ptr<ui::bindings::Binding<T>> m_value;
    };

} // ui::components
