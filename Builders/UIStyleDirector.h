#pragma once
#include <Builders/UIConfigBuilder.h>
#include <Styling/Common.h>

class StyleDirector
{
public:
    enum class Style
    {
        Flat,
        Highlighted
    };

    StyleDirector(ConfigBuilder& builder)
        : m_builder(builder)
    { }

    void construct(Style style, const ImVec4& background)
    {
        m_builder.background(background);

        switch (style)
        {
            case Style::Flat:
                m_builder
                    .onHoverBackground(background)
                    .onActiveBackground(background);
                break;

            case Style::Highlighted:
                m_builder
                    .onHoverBackground(ui::styling::Color::hoverOverOrange)
                    .onActiveBackground(ui::styling::Color::onClickOrange);
                break;
        }
    }

private:
    ConfigBuilder& m_builder;
};
