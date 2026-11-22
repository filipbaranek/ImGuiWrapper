#pragma once

namespace ui::styling
{

    class Styling
    {
    public:
        virtual ~Styling() = default;

        void render()
        {
            pushStyle();
            draw();
            popStyle();
        }

    protected:
        virtual void pushStyle() = 0;

        virtual void popStyle() = 0;

        virtual void draw() = 0;
    };

} // ui::styling