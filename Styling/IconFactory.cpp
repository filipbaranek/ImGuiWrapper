#include "IconFactory.h"

namespace ui::styling
{

    IconFactory& IconFactory::instance()
    {
        static IconFactory s_instance;
        return s_instance;
    }

    Icon* IconFactory::getIcon(const std::string& filePath)
    {
        auto [entry, isNew] = m_icons.try_emplace(filePath, nullptr);
        if (isNew)
        {
            entry->second.reset(new SharedIcon(filePath));
        }

        return entry->second.get();
    }

} // ui::styling
