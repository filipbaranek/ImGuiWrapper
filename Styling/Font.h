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
        Font(const Font&) = delete;

        Font& operator=(const Font&) = delete;

        static ImFont* regular(float size)
        {
            return instance().get("../fonts/OpenSans-Regular.ttf", size);
        }

        static ImFont* bold(float size)
        {
            return instance().get("../fonts/OpenSans_Condensed-Bold.ttf", size);
        }

        static ImFont* extraBold(float size)
        {
            return instance().get("../fonts/OpenSans_Condensed-ExtraBold.ttf", size);
        }

    private:
        Font() = default;

        ~Font() = default;

        static Font& instance()
        {
            static Font s_instance;
            return s_instance;
        }

        ImFont* get(const std::string& filePath, float size)
        {
            auto [entry, isNew] = m_fonts.try_emplace(std::pair{filePath, size}, nullptr);
            if (isNew)
            {
                entry->second = ImGui::GetIO().Fonts->AddFontFromFileTTF(filePath.c_str(), size);
            }

            return entry->second;
        }

    private:
        std::map<std::pair<std::string, float>, ImFont*> m_fonts;
    };

} // ui::styling
