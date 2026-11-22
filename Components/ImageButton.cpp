#include "ImageButton.h"
#include "Styling/Button.h"
#include "Styling/IconFactory.h"

namespace ui::components
{
    ImageButton::ImageButton(
        const std::string&                    name,
        const std::string&                    iconFilePath,
        std::shared_ptr<ui::styling::IConfig> config,
        std::function<void(Button*)>          action)
        : Button(name, std::move(config), std::move(action))
        , m_icon(ui::styling::IconFactory::instance().getIcon(iconFilePath))
    { }

    void ImageButton::render()
    {
        ui::styling::ImageButton(this).render();
    }

    ui::styling::Icon* ImageButton::icon() const
    {
        return m_icon;
    }

} // ui::components