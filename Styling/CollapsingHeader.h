#pragma once

#include <imgui.h>
#include <functional>
#include <string>

#include "Common.h"

namespace ui::styling
{

    struct CollapsingHeaderConfig : IConfig
    {
        ImVec4 header{};
        ImVec4 headerHovered{};
        ImVec4 headerActive{};
        ImVec2 framePadding{};
        float frameRounding{};
        ImGuiTreeNodeFlags flags{ImGuiTreeNodeFlags_SpanAvailWidth};
    };

    class CollapsingHeader
    {
    public:
        CollapsingHeader() = delete;

        static void addToLayout(std::function<void()> assignComponents, const ImVec2& margin = {});

        static bool initConfig(const std::string& name, CollapsingHeaderConfig& config);

        static void destroy(CollapsingHeaderConfig& config);
    };

} // namespace ui::styling