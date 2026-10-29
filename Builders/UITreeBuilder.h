#pragma once
#include <utility>
#include <Styling/Tree.h>

class TreeConfigBuilder
{
public:
    TreeConfigBuilder()
        : m_config{}
    {
    }

    TreeConfigBuilder& header(const ImVec4& color)
    {
        m_config.header = color;
        return *this;
    }

    TreeConfigBuilder& headerHovered(const ImVec4& color)
    {
        m_config.headerHovered = color;
        return *this;
    }

    TreeConfigBuilder& headerActive(const ImVec4& color)
    {
        m_config.headerActive = color;
        return *this;
    }

    TreeConfigBuilder& framePadding(const ImVec2& padding)
    {
        m_config.framePadding = padding;
        return *this;
    }

    TreeConfigBuilder& indentSpacing(float spacing)
    {
        m_config.indentSpacing = spacing;
        return *this;
    }

    TreeConfigBuilder& frameRounding(float rounding)
    {
        m_config.frameRounding = rounding;
        return *this;
    }

    TreeConfigBuilder& fontSize(float size)
    {
        m_config.fontSize = size;
        return *this;
    }

    TreeConfigBuilder& flags(ImGuiTreeNodeFlags flags)
    {
        m_config.flags = flags;
        return *this;
    }

    TreeConfigBuilder& treeLinesSize(float size) {
        m_config.treeLineSize = size;
        return *this;
    }

    TreeConfigBuilder& treeLinesRounding(float rounding)
    {
        m_config.treeLinesRounding = rounding;
        return *this;
    }

    std::shared_ptr<ui::styling::TreeConfig> build()
    {
        return std::make_shared<ui::styling::TreeConfig>(std::move(m_config));
    }

private:
    ui::styling::TreeConfig m_config;
};