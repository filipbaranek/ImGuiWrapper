#include "RadioGroup.h"
#include "RadioButton.h"

namespace ui::components
{

    void RadioGroup::add(RadioButton* button)
    {
        m_buttons.push_back(button);
    }

    void RadioGroup::select(RadioButton* button)
    {
        for (auto* groupButton : m_buttons)
        {
            groupButton->setIsSelected(false);
        }
        button->setIsSelected(true);
    }

} // ui::components
