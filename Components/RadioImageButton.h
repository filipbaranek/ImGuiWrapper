#pragma once
#include "ImageButton.h"
#include "RadioButton.h"

namespace ui::components
{
    
    class RadioImageButton : public ImageButton, public RadioButton
    {
    public:
        RadioImageButton(
            const std::string&                    name,
            const std::string&                    iconFilePath,
            RadioGroup&                           group,
            std::shared_ptr<ui::styling::IConfig> config,
            std::function<void(Button*)>          action);

        void render() override;
    };

} // ui::components