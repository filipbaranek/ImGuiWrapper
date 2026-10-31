#pragma once
#include <string>
#include "Styling/Common.h"
#include "Components/Component.h"
#include "Styling/Label.h"

namespace ui::components
{

    template <ui::styling::TextTypes TextType>
    class Label : public Component
    {
    public:
        Label(const std::string &text, std::shared_ptr<ui::styling::IConfig> config)
            : Component(text, std::move(config))
        {
        }

        void render() override
        {
            ui::styling::Label::render<TextType>(m_name,m_config.get());
        }
    };

} // ui::components