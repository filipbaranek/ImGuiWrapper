#include "ImageButton.h"
#include "Styling/Button.h"

namespace ui::components
{
    ImageButton::ImageButton(
        const std::string&                    name,
        const std::string&                    iconFilePath,
        std::shared_ptr<ui::styling::IConfig> config,
        std::function<void(Button*)>          action)
        : Button(name, std::move(config), std::move(action))
        , m_textureID((ImTextureID)(intptr_t)ImageLoader::loadImage(iconFilePath.c_str()))
    { }

    void ImageButton::render()
    {
        ui::styling::ImageButton(this).render();
    }

    const int ImageButton::textureID() const
    {
        return m_textureID;
    }

} // ui::components