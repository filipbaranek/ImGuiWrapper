#pragma once
#include "Components/Component.h"
#include "Components/Linkable.h"
#include "Styling/Drag.h"

namespace ui::components
{

    template<typename T>
    class Drag : public Component, public Linkable<T>
    {
    public:
        Drag(const std::string& name, std::shared_ptr<ui::styling::IConfig> config)
            : Component("##" + name, std::move(config))
        { }

        void render() override
        {
            ui::styling::Drag::render<T>(m_name, this->m_valPtr, m_config.get());
        }

        T* inputValue() const
        {
            return this->m_valPtr;
        }
    };

} // namespace ui::components
