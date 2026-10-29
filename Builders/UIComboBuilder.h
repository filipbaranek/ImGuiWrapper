#pragma once

#include <utility>

#include <Styling/Combo.h>

class ComboConfigBuilder
{
public:
    ComboConfigBuilder()
        : m_config{}
    { }

    ComboConfigBuilder& frameBackground(const ImVec4& color)
    {
        m_config.frameBackground = color;
        return *this;
    }

    ComboConfigBuilder& frameBackgroundHovered(const ImVec4& color)
    {
        m_config.frameBackgroundHovered = color;
        return *this;
    }

    ComboConfigBuilder& frameBackgroundActive(const ImVec4& color)
    {
        m_config.frameBackgroundActive = color;
        return *this;
    }

    ComboConfigBuilder& border(const ImVec4& color)
    {
        m_config.border = color;
        return *this;
    }

    ComboConfigBuilder& text(const ImVec4& color)
    {
        m_config.text = color;
        return *this;
    }

    ComboConfigBuilder& popUpBackground(const ImVec4& color)
    {
        m_config.popUpBackground = color;
        return *this;
    }

    ComboConfigBuilder& header(const ImVec4& color)
    {
        m_config.header = color;
        return *this;
    }

    ComboConfigBuilder& headerHovered(const ImVec4& color)
    {
        m_config.headerHovered = color;
        return *this;
    }

    ComboConfigBuilder& headerActive(const ImVec4& color)
    {
        m_config.headerActive = color;
        return *this;
    }

    ComboConfigBuilder& scrollBarBackground(const ImVec4& color)
    {
        m_config.scrollBarBackground = color;
        return *this;
    }

    ComboConfigBuilder& scrollBarGrab(const ImVec4& color)
    {
        m_config.scrollBarGrab = color;
        return *this;
    }

    ComboConfigBuilder& scrollBarGrabHovered(const ImVec4& color)
    {
        m_config.scrollBarGrabHovered = color;
        return *this;
    }

    ComboConfigBuilder& scrollBarGrabActive(const ImVec4& color)
    {
        m_config.scrollBarGrabActive = color;
        return *this;
    }

    ComboConfigBuilder& navCursor(const ImVec4& color)
    {
        m_config.navCursor = color;
        return *this;
    }

    ComboConfigBuilder& framePadding(const ImVec2& padding)
    {
        m_config.framePadding = padding;
        return *this;
    }

    ComboConfigBuilder& frameRounding(float rounding)
    {
        m_config.frameRounding = rounding;
        return *this;
    }

    ComboConfigBuilder& frameBorderSize(float size)
    {
        m_config.frameBorderSize = size;
        return *this;
    }

    ComboConfigBuilder& popUpRounding(float rounding)
    {
        m_config.popUpRounding = rounding;
        return *this;
    }

    ComboConfigBuilder& popUpBorderSize(float size)
    {
        m_config.popUpBorderSize = size;
        return *this;
    }

    ComboConfigBuilder& windowPadding(const ImVec2& padding)
    {
        m_config.windowPadding = padding;
        return *this;
    }

    ComboConfigBuilder& itemSpacing(const ImVec2& spacing)
    {
        m_config.itemSpacing = spacing;
        return *this;
    }

    ComboConfigBuilder& itemInnerSpacing(const ImVec2& spacing)
    {
        m_config.itemInnerSpacing = spacing;
        return *this;
    }

    ComboConfigBuilder& selectableTextAlign(const ImVec2& alignment)
    {
        m_config.selectableTextAlign = alignment;
        return *this;
    }

    ComboConfigBuilder& scrollBarSize(float size)
    {
        m_config.scrollBarSize = size;
        return *this;
    }

    ComboConfigBuilder& scrollBarRounding(float rounding)
    {
        m_config.scrollBarRounding = rounding;
        return *this;
    }

    ComboConfigBuilder& scrollBarPadding(float padding)
    {
        m_config.scrollBarPadding = padding;
        return *this;
    }

    ComboConfigBuilder& alpha(float alpha)
    {
        m_config.alpha = alpha;
        return *this;
    }

    ComboConfigBuilder& disabledAlpha(float alpha)
    {
        m_config.disabledAlpha = alpha;
        return *this;
    }

    std::shared_ptr<ui::styling::ComboConfig> build()
    {
        return std::make_shared<ui::styling::ComboConfig>(std::move(m_config));
    }

private:
    ui::styling::ComboConfig m_config;
};