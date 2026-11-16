#pragma once
#include "Binding.h"

namespace ui::bindings
{

    template<typename T>
    class ReferenceBinding : public Binding<T>
    {
    public:
        ReferenceBinding(T& target)
            : m_target(target)
        { }

        T get() const override
        {
            return m_target;
        }

        void set(const T& value) override
        {
            m_target = value;
        }

    private:
        T& m_target;
    };

} // ui::bindings
