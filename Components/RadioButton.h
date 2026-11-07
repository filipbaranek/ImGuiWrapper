#pragma once
#include "Button.h"
#include "RadioGroup.h"

namespace ui::components
{

    class RadioButton : public virtual Button
    {
    public:
        RadioButton(
            const std::string&                    name,
            RadioGroup&                           group,
            std::shared_ptr<ui::styling::IConfig> config,
            std::function<void(Button*)>          action);

        virtual ~RadioButton() = default;

        void render() override;

        const bool& isSelected() const;

        void setIsSelected(const bool& isSelected);

        void select();

    private:
        bool        m_isSelected;
        RadioGroup& m_group;
    };

} // ui::components