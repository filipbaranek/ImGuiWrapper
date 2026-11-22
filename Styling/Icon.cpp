#include "Icon.h"
#include "Utils/ImageLoader.h"

namespace ui::styling
{

    SharedIcon::SharedIcon(const std::string& filePath)
        : m_texture{(ImTextureID)(intptr_t)ImageLoader::loadImage(filePath.c_str())}
    { }

    bool SharedIcon::draw(const IconPlacement& placement) const
    {
        return ImGui::ImageButton(placement.name.c_str(), m_texture.id, placement.size);
    }

} // ui::styling
