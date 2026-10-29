#include "Combo.h"

namespace ui::styling
{

    void Combo::initConfig(ComboConfig* config)
    {
        ImGui::PushStyleColor(ImGuiCol_FrameBg, config->frameBackground);
        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, config->frameBackgroundHovered);
        ImGui::PushStyleColor(ImGuiCol_FrameBgActive, config->frameBackgroundActive);
        if (config->frameBorderSize > 0.0f || config->popUpBorderSize > 0.0f)
        {
            ImGui::PushStyleColor(ImGuiCol_Border, config->border);
            ++config->styles.appliedColorStyles;
        }
        ImGui::PushStyleColor(ImGuiCol_Text, config->text);
        ImGui::PushStyleColor(ImGuiCol_PopupBg, config->popUpBackground);
        ImGui::PushStyleColor(ImGuiCol_Header, config->header);
        ImGui::PushStyleColor(ImGuiCol_HeaderHovered, config->headerHovered);
        ImGui::PushStyleColor(ImGuiCol_HeaderActive, config->headerActive);
        ImGui::PushStyleColor(ImGuiCol_ScrollbarBg, config->scrollBarBackground);
        ImGui::PushStyleColor(ImGuiCol_ScrollbarGrab, config->scrollBarGrab);
        ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabHovered, config->scrollBarGrabHovered);
        ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabActive, config->scrollBarGrabActive);
        ImGui::PushStyleColor(ImGuiCol_NavCursor, config->navCursor);

        config->styles.appliedColorStyles += 13;

        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, config->framePadding);
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, config->frameRounding);
        ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, config->frameBorderSize);
        ImGui::PushStyleVar(ImGuiStyleVar_PopupRounding, config->popUpRounding);
        ImGui::PushStyleVar(ImGuiStyleVar_PopupBorderSize, config->popUpBorderSize);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, config->windowPadding);
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, config->itemSpacing);
        ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, config->itemInnerSpacing);
        ImGui::PushStyleVar(ImGuiStyleVar_SelectableTextAlign, config->selectableTextAlign);
        ImGui::PushStyleVar(ImGuiStyleVar_ScrollbarSize, config->scrollBarSize);
        ImGui::PushStyleVar(ImGuiStyleVar_ScrollbarRounding, config->scrollBarRounding);
        ImGui::PushStyleVar(ImGuiStyleVar_ScrollbarPadding, config->scrollBarPadding);
        ImGui::PushStyleVar(ImGuiStyleVar_Alpha, config->alpha);
        ImGui::PushStyleVar(ImGuiStyleVar_DisabledAlpha, config->disabledAlpha);

        config->styles.appliedVarStyles += 14;
    }

    void Combo::destroy(ComboConfig* config)
    {
        ImGui::PopStyleColor(config->styles.appliedColorStyles);
        ImGui::PopStyleVar(config->styles.appliedVarStyles);

        config->styles.appliedColorStyles = 0;
        config->styles.appliedVarStyles = 0;
    }

} // namespace ui::styling
