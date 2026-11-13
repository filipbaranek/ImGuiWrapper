#pragma once
#include <string>
#include <imgui.h>

namespace ui::styling
{

    struct IconTexture
    {
        ImTextureID id;
    };

    struct IconPlacement
    {
        std::string name;
        ImVec2      size;
    };

    class Icon
    {
    public:
        virtual ~Icon() = default;

        virtual bool draw(const IconPlacement& placement) const = 0;
    };

    class SharedIcon : public Icon
    {
    public:
        bool draw(const IconPlacement& placement) const override;

    private:
        friend class IconFactory;

        SharedIcon(const std::string& filePath);

    private:
        IconTexture m_texture;
    };

} // ui::styling
