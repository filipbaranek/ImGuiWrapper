#include "Label.h"
#include "Components/Label.h"

namespace ui::styling
{

    Label::Label(ui::components::Label* label)
        : m_label(label)
        , m_config(dynamic_cast<LabelConfig*>(label->config()))
    { }

    void Label::pushStyle()
    {
        const ImVec2 windowSize = ImGui::GetMainViewport()->Size;

        ImGui::PushFont(m_config->font);

        ImVec2 textSize = ImGui::CalcTextSize("Aa");

        float scaleX = ImGui::GetFontSize() * (windowSize.x / textSize.x);
        float scaleY = ImGui::GetFontSize() * (windowSize.y / textSize.y);

        float scale = std::min(scaleX, scaleY);

        ImGui::SetWindowFontScale(scale);
    }

    void Label::popStyle()
    {
        ImGui::SetWindowFontScale(1.0f);
        ImGui::PopFont();
    }

    void Label::draw()
    {
        ImGui::TextColored(m_config->color, "%s", m_label->name().c_str());
    }

} // ui::styling