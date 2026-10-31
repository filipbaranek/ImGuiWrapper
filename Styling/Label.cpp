#include "Label.h"
#include "Components/Label.h"

namespace ui::styling
{

    void Label::init(LabelConfig *config)
    {
        const ImVec2 windowSize = ImGui::GetMainViewport()->Size;

        ImGui::PushFont(config->font);

        ImVec2 textSize = ImGui::CalcTextSize("Aa");

        float scaleX = ImGui::GetFontSize() * (windowSize.x / textSize.x);
        float scaleY = ImGui::GetFontSize() * (windowSize.y / textSize.y);

        float scale = std::min(scaleX, scaleY);

        ImGui::SetWindowFontScale(scale);

    }

    void Label::destroy(LabelConfig *config)
    {
        ImGui::SetWindowFontScale(1.0f);
        ImGui::PopFont();
    }
} // ui::styling