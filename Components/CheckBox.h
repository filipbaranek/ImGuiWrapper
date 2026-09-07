#pragma once
#include <string>
#include "../Styling/Common.h"
#include "../Components/Component.h"

namespace ui::components
{

    class CheckBox : public Component
    {
    public:
        CheckBox(const std::string& name, std::shared_ptr<ui::styling::IConfig> config);

        void render() override;

        bool* isChecked();

    private:
        bool m_isChecked;
    };

} // ui::components