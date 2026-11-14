#pragma once
#include <memory>
#include <Styling/Common.h>

class ConfigBuilder
{
public:
    virtual ~ConfigBuilder() = default;

    virtual ConfigBuilder& background(const ImVec4& background) = 0;

    virtual ConfigBuilder& onHoverBackground(const ImVec4& background) = 0;

    virtual ConfigBuilder& onActiveBackground(const ImVec4& background) = 0;

    virtual std::shared_ptr<ui::styling::IConfig> build() = 0;
};
