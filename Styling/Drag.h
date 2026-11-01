#pragma once
#include <string>
#include <stdexcept>
#include "Common.h"

namespace ui::styling
{

    template <typename T>
    struct DragConfig : IConfig
    {
        T min;
        T max;
        float speed;
        float width;
        float frameBorderSize;
        std::string format;
        ImVec4 background;
        ImVec4 onHoverBackground;
        ImVec4 onActiveBackground;
    };

    class Drag
    {
    public:
        Drag() = delete;

        template <typename T>
        static void render(std::string &name, T *value, IConfig *config);

    private:
        template <typename T>
        static void initConfig(DragConfig<T> *config)
        {
            ImGui::PushStyleColor(ImGuiCol_FrameBg, config->background);
            ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, config->onHoverBackground);
            ImGui::PushStyleColor(ImGuiCol_FrameBgActive, config->onActiveBackground);
            ImGui::SetNextItemWidth(config->width * ImGui::GetWindowSize().x);
            ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, config->frameBorderSize);

            config->styles.appliedColorStyles += 3;
            config->styles.appliedVarStyles += 1;
        }

        template <typename T>
        static void destroy(DragConfig<T> *config)
        {
            ImGui::PopStyleColor(config->styles.appliedColorStyles);
            ImGui::PopStyleVar(config->styles.appliedVarStyles);

            config->styles.appliedColorStyles = 0;
            config->styles.appliedVarStyles = 0;
        }
    };

    template <typename T>
    inline void Drag::render(std::string &, T *, IConfig *)
    {
        throw std::logic_error("Unsupported type for drag");
    }

    template <>
    inline void Drag::render<float>(std::string &name, float *value, IConfig *config)
    {
        auto *dragConfig = dynamic_cast<DragConfig<float> *>(config);
        if (dragConfig == nullptr) {
            throw std::invalid_argument("Drag requires a DragConfig");
        }
        initConfig(dragConfig);

        ImGui::DragFloat(
            name.c_str(),
            value,
            dragConfig->speed,
            dragConfig->min,
            dragConfig->max,
            dragConfig->format.c_str());

        destroy(dragConfig);
    }

} // namespace ui::styling
