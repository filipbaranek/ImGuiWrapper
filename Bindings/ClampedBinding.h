#pragma once
#include <algorithm>
#include <stdexcept>
#include "Binding.h"

namespace ui::bindings
{

    template<typename T>
    class ClampedBinding : public Binding<T>
    {
    public:
        ClampedBinding(const T& value, const T& min, const T& max)
            : m_min(min)
            , m_max(max)
            , m_value{}
        {
            if (m_max < m_min)
            {
                throw std::logic_error("ClampedBinding construction error: min must not be greater than max");
            }

            m_value = std::clamp(value, m_min, m_max);
        }

        T get() const override
        {
            return m_value;
        }

        void set(const T& value) override
        {
            m_value = std::clamp(value, m_min, m_max);
        }

    private:
        T m_min;
        T m_max;
        T m_value;
    };

} // ui::bindings
