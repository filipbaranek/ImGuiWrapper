#pragma once
#include <utility>
#include <Builders/UIConfigBuilder.h>
#include <Styling/Button.h>

class ButtonConfigBuilder : public ConfigBuilder
{
public:
    ButtonConfigBuilder()
        : m_config{}
    { }

    ButtonConfigBuilder& rounding(float rounding)
    {
        m_config.rounding = rounding;
        return *this;
    }

    ButtonConfigBuilder& font(ImFont* font)
    {
        m_config.font = font;
        return *this;
    }

    ButtonConfigBuilder& size(const ImVec2& size)
    {
        m_config.size = size;
        return *this;
    }

    ButtonConfigBuilder& background(const ImVec4& background) override
    {
        m_config.background = background;
        return *this;
    }

    ButtonConfigBuilder& onHoverBackground(const ImVec4& background) override
    {
        m_config.onHoverOverColor = background;
        return *this;
    }

    ButtonConfigBuilder& onActiveBackground(const ImVec4& background) override
    {
        m_config.onClickColor = background;
        return *this;
    }

    ButtonConfigBuilder& framePadding(const ImVec2& padding)
    {
        m_config.framePadding = padding;
        return *this;
    }

    ButtonConfigBuilder& square(bool square)
    {
        m_config.square = square;
        return *this;
    }

    std::shared_ptr<ui::styling::IConfig> build() override
    {
        return std::make_shared<ui::styling::ButtonConfig>(std::move(m_config));
    }

private:
    ui::styling::ButtonConfig m_config;
};