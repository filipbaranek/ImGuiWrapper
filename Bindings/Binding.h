#pragma once

namespace ui::bindings
{

    template<typename T>
    class Binding
    {
    public:
        virtual ~Binding() = default;

        virtual T get() const = 0;

        virtual void set(const T& value) = 0;
    };

} // ui::bindings
