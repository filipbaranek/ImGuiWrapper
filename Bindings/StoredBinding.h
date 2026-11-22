#pragma once
#include "Binding.h"

namespace ui::bindings
{

    template<typename T>
    class StoredBinding : public Binding<T>
    {
    public:
        StoredBinding(const T& value = T{})
            : m_value(value)
        { }

        T get() const override
        {
            return m_value;
        }

        void set(const T& value) override
        {
            m_value = value;
        }

    private:
        T m_value;
    };

} // ui::bindings
