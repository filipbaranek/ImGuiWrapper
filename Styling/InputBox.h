#pragma once
#include <string>
#include <stdexcept>
#include "Common.h"
#include "Styling.h"
#include "Bindings/Binding.h"

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
        InputBox(const std::string& name, ui::bindings::Binding<T>& value, IConfig* config)
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
        const std::string&        m_name;
        ui::bindings::Binding<T>& m_value;
        InputBoxConfig*           m_config;
    };

    template<typename T>
    inline void InputBox<T>::draw()
    {
        throw std::logic_error("Unsupported type for input box");
    }

    template<>
    inline void InputBox<int>::draw()
    {
        int value = m_value.get();
        if (ImGui::InputInt(m_name.c_str(), &value, 0))
        {
            m_value.set(value);
        }
    }

    template<>
    inline void InputBox<float>::draw()
    {
        float value = m_value.get();
        if (ImGui::InputFloat(m_name.c_str(), &value, 0.0f))
        {
            m_value.set(value);
        }
    }

    template<>
    inline void InputBox<double>::draw()
    {
        double value = m_value.get();
        if (ImGui::InputDouble(m_name.c_str(), &value, 0.0))
        {
            m_value.set(value);
        }
    }

    template<>
    inline void InputBox<std::string>::draw()
    {
        static constexpr int bufferSize = 256;

        char buffer[bufferSize]{};
        m_value.get().copy(buffer, bufferSize - 1);

        if (ImGui::InputText(m_name.c_str(), buffer, bufferSize))
        {
            m_value.set(buffer);
        }
    }

} // ui::styling
