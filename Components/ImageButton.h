#pragma once
#include "Button.h"
#include "Styling/Icon.h"

namespace ui::components
{

    class ImageButton : public virtual Button
    {
    public:
        ImageButton(
            const std::string&                    name,
            const std::string&                    iconFilePath,
            std::shared_ptr<ui::styling::IConfig> config,
            std::function<void(Button*)>          action);

        virtual ~ImageButton() = default;

        void render() override;

        ui::styling::Icon* icon() const;

    private:
        ui::styling::Icon* m_icon;
    };

} // ui::components