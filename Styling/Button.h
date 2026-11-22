#pragma once
#include "Common.h"
#include "Styling.h"
#include "Components/Component.h"
#include "Components/RadioImageButton.h"

namespace ui::styling
{

    struct ButtonConfig : IConfig
    {
        bool    square;
        float   rounding;
        ImFont* font;
        ImVec2  size;
        ImVec2  realSize;
        ImVec4  background;
        ImVec4  onHoverOverColor;
        ImVec4  onClickColor;
        ImVec2  framePadding;
    };

    class Button : public Styling
    {
    public:
        Button(ui::components::Button* button);

    protected:
        void pushStyle() override;

        void popStyle() override;

        void draw() override;

    protected:
        ui::components::Button* m_button;
        ButtonConfig*           m_config;
    };

    class ImageButton : public Button
    {
    public:
        ImageButton(ui::components::ImageButton* imageButton);

    protected:
        void draw() override;

    private:
        ui::components::ImageButton* m_imageButton;
    };

    class RadioButton : public Button
    {
    public:
        RadioButton(ui::components::RadioButton* radioButton);

    protected:
        void draw() override;

    private:
        ui::components::RadioButton* m_radioButton;
    };

    class RadioImageButton : public Button
    {
    public:
        RadioImageButton(ui::components::RadioImageButton* radioImageButton);

    protected:
        void draw() override;

    private:
        ui::components::RadioImageButton* m_radioImageButton;
    };

} // ui::styling