#pragma once
#include <map>
#include <string>
#include <utility>
#include <imgui.h>

namespace ui::styling
{

    class Font
    {
    public:
        Font() = delete;

        static ImFont* regular(float size)
        {
            return get("../fonts/OpenSans-Regular.ttf", size);
        }

        static ImFont* bold(float size)
        {
            return get("../fonts/OpenSans_Condensed-Bold.ttf", size);
        }

        static ImFont* extraBold(float size)
        {
            return get("../fonts/OpenSans_Condensed-ExtraBold.ttf", size);
        }

    private:
        static ImFont* get(const std::string& filePath, float size)
        {
            static std::map<std::pair<std::string, float>, ImFont*> fonts;

            auto [entry, isNew] = fonts.try_emplace(std::pair{filePath, size}, nullptr);
            if (isNew)
            {
                entry->second = ImGui::GetIO().Fonts->AddFontFromFileTTF(filePath.c_str(), size);
            }

            return entry->second;
        }
    };

} // ui::styling
