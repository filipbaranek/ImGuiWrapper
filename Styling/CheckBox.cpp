#include "CheckBox.h"
#include "Components/CheckBox.h"

namespace ui::styling
{

    CheckBox::CheckBox(ui::components::CheckBox* checkBox)
        : m_checkBox(checkBox)
        , m_config(dynamic_cast<CheckBoxConfig*>(checkBox->config()))
    { }

    void CheckBox::pushStyle()
    {
        ImGui::PushStyleColor(ImGuiCol_CheckMark, m_config->checkMarkColor);
        ImGui::PushStyleColor(ImGuiCol_FrameBg, m_config->background);
        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, m_config->hoveredBackground);
        ImGui::PushStyleColor(ImGuiCol_FrameBgActive, m_config->activeBackground);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, m_config->framePadding);

        m_config->styles.appliedColorStyles += 4;
        ++m_config->styles.appliedVarStyles;
    }

    void CheckBox::popStyle()
    {
        ImGui::PopStyleColor(m_config->styles.appliedColorStyles);
        ImGui::PopStyleVar(m_config->styles.appliedVarStyles);

        m_config->styles.appliedColorStyles = 0;
        m_config->styles.appliedVarStyles = 0;
    }

    void CheckBox::draw()
    {
        std::string checkBoxName = "##" + m_checkBox->name();

        ImGui::Checkbox(checkBoxName.c_str(), m_checkBox->isChecked());
    }

} // ui::styling