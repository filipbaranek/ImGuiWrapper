#pragma once
#include <string>
#include <functional>
#include "Components/Component.h"

namespace ui
{
  
    enum class ButtonType
    {
        DEFAULT,
        IMAGE,
        RADIO,
        RADIO_IMAGE
    };

} // ui

namespace ui::components
{

    class Button : public Component
    {
    public:
        Button(const std::string& name, std::shared_ptr<ui::styling::IConfig> config, std::function<void(Button*)> action);

        virtual ~Button() = default;

        void render() override;

        void setAction(std::function<void(Button*)> action);

        void execute();

    private:
        std::function<void(Button*)> m_action;
    };

} // ui::components