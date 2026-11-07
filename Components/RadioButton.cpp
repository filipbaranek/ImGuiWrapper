#include "RadioButton.h"
#include "Styling/Button.h"

namespace ui::components
{

    RadioButton::RadioButton(
        const std::string& name,
        RadioGroup&                           group,
        std::shared_ptr<ui::styling::IConfig> config,
        std::function<void(Button*)> action)
        : Button(name, std::move(config), std::move(action))
        , m_isSelected{}
        , m_group(group)
    {
        m_group.add(this);
    }

    void RadioButton::render()
    {
        ui::styling::Button::render<ui::ButtonType::RADIO>(this);
    }

    const bool& RadioButton::isSelected() const
    {
        return m_isSelected;
    }

    void RadioButton::setIsSelected(const bool& isSelected)
    {
        m_isSelected = isSelected;
    }

    void RadioButton::select()
    {
        m_group.select(this);
    }

} // ui::components