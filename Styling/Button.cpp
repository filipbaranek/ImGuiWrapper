#include "Button.h"
#include <iostream>

namespace ui::styling
{

    Button::Button(ui::components::Button* button)
        : m_button(button)
        , m_config(dynamic_cast<ButtonConfig*>(button->config()))
    { }

    void Button::pushStyle()
    {
        auto* radioButton = dynamic_cast<ui::components::RadioButton*>(m_button);
        if (radioButton != nullptr)
        {
            if (radioButton->isSelected())
            {
                ImGui::PushStyleColor(ImGuiCol_Button, ui::styling::Color::selectedOrange);
            }
            else
            {
                ImGui::PushStyleColor(ImGuiCol_Button, ui::styling::Color::black);
            }
        }
        else
        {
            ImGui::PushStyleColor(ImGuiCol_Button, m_config->background);
        }
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, m_config->onHoverOverColor);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, m_config->onClickColor);
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, m_config->rounding);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, m_config->framePadding);

        const ImVec2 windowSize = ImGui::GetMainViewport()->Size;

        float realSizeX = windowSize.x * m_config->size.x;
        float realSizeY = windowSize.y * m_config->size.y;

        if (m_config->square)
        {
            const float squaredSize = std::min(realSizeX, realSizeY);

            realSizeX = squaredSize;
            realSizeY = squaredSize;
        }

        m_config->realSize = ImVec2{realSizeX, realSizeY};

        if (m_config->font != nullptr)
        {
            ImGui::PushFont(m_config->font);

            ImVec2 textSize = ImGui::CalcTextSize("Aa");

            float scaleX = ImGui::GetFontSize() * (m_config->realSize.x / textSize.x);
            float scaleY = ImGui::GetFontSize() * (m_config->realSize.y / textSize.y);
            float scale  = std::min(scaleX, scaleY);

            ImGui::SetWindowFontScale(scale);
        }

        m_config->styles.appliedColorStyles += 3;
        m_config->styles.appliedVarStyles   += 2;
    }

    void Button::popStyle()
    {
        if (m_config->font != nullptr)
        {
            ImGui::SetWindowFontScale(1.0f);
            ImGui::PopFont();
        }

        ImGui::PopStyleColor(m_config->styles.appliedColorStyles);
        ImGui::PopStyleVar(m_config->styles.appliedVarStyles);

        m_config->styles.appliedColorStyles = 0;
        m_config->styles.appliedVarStyles = 0;
    }

    void Button::draw()
    {
        const ImVec2 buttonSize = m_config->realSize;

        if (ImGui::Button(m_button->name().c_str(), buttonSize))
        {
            m_button->execute();
        }
    }

    ImageButton::ImageButton(ui::components::ImageButton* imageButton)
        : Button(imageButton)
        , m_imageButton(imageButton)
    { }

    void ImageButton::draw()
    {
        const ImVec2 buttonSize = m_config->realSize;

        if (ImGui::ImageButton(m_imageButton->name().c_str(), m_imageButton->textureID(), buttonSize))
        {
            m_imageButton->execute();
        }
    }

    RadioButton::RadioButton(ui::components::RadioButton* radioButton)
        : Button(radioButton)
        , m_radioButton(radioButton)
    { }

    void RadioButton::draw()
    {
        const ImVec2 buttonSize = m_config->realSize;

        if (ImGui::Button(m_radioButton->name().c_str(), buttonSize))
        {
            m_radioButton->select();
            m_radioButton->execute();
        }
    }

    RadioImageButton::RadioImageButton(ui::components::RadioImageButton* radioImageButton)
        : Button(radioImageButton)
        , m_radioImageButton(radioImageButton)
    { }

    void RadioImageButton::draw()
    {
        const ImVec2 buttonSize = m_config->realSize;

        if (ImGui::ImageButton(m_radioImageButton->name().c_str(), m_radioImageButton->textureID(), buttonSize))
        {
            m_radioImageButton->select();
            m_radioImageButton->execute();
        }
    }

} // ui::styling