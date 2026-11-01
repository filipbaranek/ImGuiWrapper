#pragma once
#include <Styling/Drag.h>
#include <memory>
#include <utility>

template<typename T>
class DragConfigBuilder
{
public:
    DragConfigBuilder()
        : m_config{}
    {
        m_config.min = 0;
        m_config.max = 0;
        m_config.speed = 1.0f;
        m_config.width = 0.0f;
        m_config.frameBorderSize = 0.0f;
        m_config.format = "%.3f";
    }

    DragConfigBuilder& min(T min)
    {
        m_config.min = min;
        return *this;
    }

    DragConfigBuilder& max(T max)
    {
        m_config.max = max;
        return *this;
    }

    DragConfigBuilder& speed(float speed)
    {
        m_config.speed = speed;
        return *this;
    }

    DragConfigBuilder& width(float width)
    {
        m_config.width = width;
        return *this;
    }

    DragConfigBuilder& frameBorderSize(float size)
    {
        m_config.frameBorderSize = size;
        return *this;
    }

    DragConfigBuilder& format(const std::string& format)
    {
        m_config.format = format;
        return *this;
    }

    DragConfigBuilder& background(const ImVec4& background)
    {
        m_config.background = background;
        return *this;
    }

    DragConfigBuilder& onHoverBackground(const ImVec4& background)
    {
        m_config.onHoverBackground = background;
        return *this;
    }

    DragConfigBuilder& onActiveBackground(const ImVec4& background)
    {
        m_config.onActiveBackground = background;
        return *this;
    }

    std::shared_ptr<ui::styling::DragConfig<T>> build()
    {
        return std::make_shared<ui::styling::DragConfig<T>>(std::move(m_config));
    }

private:
    ui::styling::DragConfig<T> m_config;
};
