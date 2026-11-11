#pragma once
#include <string>
#include <stdexcept>
#include "Common.h"
#include "Styling.h"

namespace ui::styling
{

    struct InputBoxConfig : IConfig
    {
        float  width;
        ImVec4 background;
    };

    template<typename T>
    class InputBox : public Styling
    {
    public:
        InputBox(const std::string& name, T* value, IConfig* config)
            : m_name(name)
            , m_value(value)
            , m_config(dynamic_cast<InputBoxConfig*>(config))
        { }

    protected:
        void pushStyle() override
        {
            ImGui::PushStyleColor(ImGuiCol_FrameBg, m_config->background);
            ImGui::SetNextItemWidth(m_config->width * ImGui::GetWindowSize().x);

            ++m_config->styles.appliedColorStyles;
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
        InputBoxConfig*    m_config;
    };

    template<typename T>
    inline void InputBox<T>::draw()
    {
        throw std::logic_error("Unsupported type for input box");
    }

    template<>
    inline void InputBox<int>::draw()
    {
        ImGui::InputInt(m_name.c_str(), m_value, 0);
    }

    template<>
    inline void InputBox<float>::draw()
    {
        ImGui::InputFloat(m_name.c_str(), m_value, 0.0f);
    }

    template<>
    inline void InputBox<double>::draw()
    {
        ImGui::InputDouble(m_name.c_str(), m_value, 0.0);
    }

    template<>
    inline void InputBox<char>::draw()
    {
        static constexpr int bufferSize = 256;

        ImGui::InputText(m_name.c_str(), m_value, bufferSize, 0);
    }

} // ui::styling
