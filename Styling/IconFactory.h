#pragma once
#include <map>
#include <memory>
#include <string>
#include "Icon.h"

namespace ui::styling
{

    class IconFactory
    {
    public:
        IconFactory(const IconFactory&) = delete;

        IconFactory& operator=(const IconFactory&) = delete;

        static IconFactory& instance();

        Icon* getIcon(const std::string& filePath);

    private:
        IconFactory() = default;

        ~IconFactory() = default;

    private:
        std::map<std::string, std::unique_ptr<SharedIcon>> m_icons;
    };

} // ui::styling
