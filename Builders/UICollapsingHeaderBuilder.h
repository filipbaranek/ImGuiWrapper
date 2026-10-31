#pragma once

#include <utility>

#include <Styling/CollapsingHeader.h>

class CollapsingHeaderConfigBuilder
{
public:
    CollapsingHeaderConfigBuilder()
        : m_config{}
    { }

    CollapsingHeaderConfigBuilder& header(const ImVec4& color)
    {
        m_config.header = color;
        return *this;
    }

    CollapsingHeaderConfigBuilder& headerHovered(const ImVec4& color)
    {
        m_config.headerHovered = color;
        return *this;
    }

    CollapsingHeaderConfigBuilder& headerActive(const ImVec4& color)
    {
        m_config.headerActive = color;
        return *this;
    }

    CollapsingHeaderConfigBuilder& framePadding(const ImVec2& padding)
    {
        m_config.framePadding = padding;
        return *this;
    }

    CollapsingHeaderConfigBuilder& frameRounding(float rounding)
    {
        m_config.frameRounding = rounding;
        return *this;
    }

    CollapsingHeaderConfigBuilder& flags(ImGuiTreeNodeFlags flags)
    {
        m_config.flags = flags;
        return *this;
    }

    std::shared_ptr<ui::styling::CollapsingHeaderConfig> build()
    {
        return std::make_shared<ui::styling::CollapsingHeaderConfig>(std::move(m_config));
    }

private:
    ui::styling::CollapsingHeaderConfig m_config;
};