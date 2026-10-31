#pragma once
#include <string>
#include <imgui.h>
#include <string.h>
#include "Common.h"
#include <stdexcept>

namespace ui::components
{
    template <ui::styling::TextTypes TextType>
    class Label;
} // ui::components

namespace ui::styling
{
    struct LabelConfig : IConfig
    {
        ImFont *font;
        ImVec4 color;
    };

    class Label
    {
    public:
        Label() = delete;

        template <TextTypes TextType>
        static void render(const std::string& text,IConfig* config)
        {
            auto *labelConfig = dynamic_cast<LabelConfig *>(config);
            if (labelConfig == nullptr) {
                throw std::invalid_argument("Label requires a LabelConfig");
            }

            init(labelConfig);
            renderText<TextType>(labelConfig, text);
            destroy(labelConfig);
        }

        template <TextTypes TextType>
        static void renderText(const LabelConfig *config, const std::string &text);

    private:
        static void init(LabelConfig *config);

        static void destroy(LabelConfig *config);
    };

    template <>
    inline void Label::renderText<TextTypes::CLASSIC>(const LabelConfig *config, const std::string &text)
    {
        ImGui::TextColored(config->color, "%s", text.c_str());
    }

    template <>
    inline void Label::renderText<TextTypes::DISABLED>(const LabelConfig *config, const std::string &text)
    {
        ImGui::TextDisabled("%s", text.c_str());
    }

    template <>
    inline void Label::renderText<TextTypes::BULLET>(const LabelConfig *config, const std::string &text)
    {
        ImGui::BulletText("%s", text.c_str());
    }

} // ui::styling