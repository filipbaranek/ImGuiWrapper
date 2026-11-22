#pragma once
#include <vector>

namespace ui::components
{

    class RadioButton;

    class RadioGroup
    {
    public:
        RadioGroup() = default;

        void add(RadioButton* button);

        void select(RadioButton* button);

    private:
        std::vector<RadioButton*> m_buttons;
    };

} // ui::components
