#pragma once
#include <memory>
#include <stdexcept>
#include <utility>
#include <Styling/ChildWindow.h>

class ChildWindowSizeConfigBuilder
{
public:
    ChildWindowSizeConfigBuilder()
        : m_config{}
    {
        m_config.minWidth = 1.0f;
        m_config.minHeight = 1.0f;
    }

    ChildWindowSizeConfigBuilder& width(float width)
    {
        m_config.width = width;
        return *this;
    }

    ChildWindowSizeConfigBuilder& height(float height)
    {
        m_config.height = height;
        return *this;
    }

    ChildWindowSizeConfigBuilder& minWidth(float minWidth)
    {
        m_config.minWidth = minWidth;
        return *this;
    }

    ChildWindowSizeConfigBuilder& minHeight(float minHeight)
    {
        m_config.minHeight = minHeight;
        return *this;
    }

    ui::styling::ChildWindowSizeConfig&& build()
    {
        return std::move(m_config);
    }

private:
    ui::styling::ChildWindowSizeConfig m_config;
};

class ChildWindowConfigBuilder
{
public:
    ChildWindowConfigBuilder()
        : m_config{}
    { }

    ChildWindowConfigBuilder& name(const std::string& name)
    {
        m_config.name = name;
        return *this;
    }

    ChildWindowConfigBuilder& background(const ImVec4& background)
    {
        m_config.backgroundColor = background;
        return *this;
    }

    ChildWindowConfigBuilder& rounding(float rounding)
    {
        m_config.rounding = rounding;
        return *this;
    }

    ChildWindowConfigBuilder& borderSize(float borderSize)
    {
        m_config.borderSize = borderSize;
        return *this;
    }

    ChildWindowConfigBuilder& padding(const ImVec2& padding)
    {
        m_config.padding = padding;
        return *this;
    }

    ChildWindowConfigBuilder& childFlags(ImGuiChildFlags flags)
    {
        m_config.childFlags = flags;
        return *this;
    }

    ChildWindowConfigBuilder& windowFlags(ImGuiWindowFlags flags)
    {
        m_config.windowFlags = flags;
        return *this;
    }

    ChildWindowConfigBuilder& size(const ui::styling::ChildWindowSizeConfig& size)
    {
        m_config.size = size;
        return *this;
    }

    std::shared_ptr<ui::styling::ChildWindowConfig> build()
    {
        if (m_config.name.empty())
        {
            throw std::logic_error("ChildWindowConfig construction error: name parameter is mandatory");
        }
        return std::make_shared<ui::styling::ChildWindowConfig>(std::move(m_config));
    }

private:
    ui::styling::ChildWindowConfig m_config;
};