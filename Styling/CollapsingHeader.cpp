#include "CollapsingHeader.h"

namespace ui::styling
{

    bool CollapsingHeader::initConfig(const std::string& name, CollapsingHeaderConfig& config)
    {
        ImGui::PushStyleColor(ImGuiCol_Header, config.header);
        ImGui::PushStyleColor(ImGuiCol_HeaderHovered, config.headerHovered);
        ImGui::PushStyleColor(ImGuiCol_HeaderActive, config.headerActive);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, config.framePadding);
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, config.frameRounding);

        config.styles.appliedColorStyles += 3;
        config.styles.appliedVarStyles += 2;
        return ImGui::CollapsingHeader(name.c_str(), config.flags);
    }

    void CollapsingHeader::destroy(CollapsingHeaderConfig& config)
    {
        ImGui::PopStyleColor(config.styles.appliedColorStyles);
        ImGui::PopStyleVar(config.styles.appliedVarStyles);

        config.styles.appliedColorStyles = 0;
        config.styles.appliedVarStyles = 0;
    }

    void CollapsingHeader::addToLayout(std::function<void()> assignComponents, const ImVec2& margin)
    {
        const ImVec2 windowSize = ImGui::GetWindowSize();
        const float marginX = windowSize.x * margin.x;
        const float marginY = windowSize.y * margin.y;

        if (marginX > 0.0f)
        {
            ImGui::Indent(marginX);
        }
        ImGui::Dummy(ImVec2{0.0f, marginY});
        ImGui::BeginGroup();
        assignComponents();
        ImGui::EndGroup();
        ImGui::Dummy(ImVec2{0.0f, marginY});
        if (marginX > 0.0f)
        {
            ImGui::Unindent(marginX);
        }
    }

} // namespace ui::styling
