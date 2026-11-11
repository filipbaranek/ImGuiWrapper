#pragma once
#include <string>
#include "Common.h"
#include "Styling.h"

namespace ui::styling
{

    template<typename T>
    struct SliderConfig : IConfig
    {
        T      min;
        T      max;
        float  width;
        ImVec4 background;
        ImVec4 onHoverBackground;
        ImVec4 onActiveBackground;
        ImVec4 grabBackground;
        ImVec4 onGrabActiveBackground;
    };

    template<typename T>
    class Slider : public Styling
    {
    public:
        Slider(const std::string& name, T* value, IConfig* config)
            : m_name(name)
            , m_value(value)
            , m_config(dynamic_cast<SliderConfig<T>*>(config))
        { }

    protected:
        void pushStyle() override
        {
            ImGui::PushStyleColor(ImGuiCol_FrameBg, m_config->background);
            ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, m_config->onHoverBackground);
            ImGui::PushStyleColor(ImGuiCol_FrameBgActive, m_config->onActiveBackground);
            ImGui::PushStyleColor(ImGuiCol_SliderGrab, m_config->grabBackground);
            ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, m_config->onGrabActiveBackground);
            ImGui::SetNextItemWidth(m_config->width * ImGui::GetWindowSize().x);

            m_config->styles.appliedColorStyles += 5;
        }

        void popStyle() override
        {
            ImGui::PopStyleColor(m_config->styles.appliedColorStyles);

            m_config->styles.appliedColorStyles = 0;
        }

        void draw() override;

    private:
        const std::string& m_name;
        T*                 m_value;
        SliderConfig<T>*   m_config;
    };

    template<typename T>
    inline void Slider<T>::draw()
    {
        throw std::logic_error("Unsupported type for slider");
    }

    template<>
    inline void Slider<int>::draw()
    {
        ImGui::SliderInt(m_name.c_str(), m_value, m_config->min, m_config->max);
    }

    template<>
    inline void Slider<float>::draw()
    {
        ImGui::SliderFloat(m_name.c_str(), m_value, m_config->min, m_config->max);
    }

} // ui::comopnents