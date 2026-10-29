#pragma once

#include <functional>
#include <string>
#include <utility>

#include "Components/Component.h"
#include "Styling/Combo.h"

namespace ui::components
{

    template<typename Iterator>
    class Combo : public Component
    {
    public:
        Combo(
            const std::string& name,
            std::shared_ptr<ui::styling::IConfig> config,
            std::function<std::pair<Iterator, Iterator>()> getItems,
            std::function<std::string()> getPreview,
            std::function<ImGuiID(Iterator)> getId,
            std::function<std::string(Iterator)> getName,
            std::function<bool(Iterator)> isSelected,
            std::function<void(Iterator)> onSelect)
            : Component("##" + name, std::move(config))
            , m_getItems(std::move(getItems))
            , m_getPreview(std::move(getPreview))
            , m_getId(std::move(getId))
            , m_getName(std::move(getName))
            , m_isSelected(std::move(isSelected))
            , m_onSelect(std::move(onSelect))
        { }

        void render() override
        {
            const auto [begin, end] = m_getItems();
            if (begin == end)
            {
                return;
            }

            ui::styling::Combo::render(
                m_name,
                m_getPreview(),
                begin,
                end,
                m_getId,
                m_getName,
                m_isSelected,
                m_onSelect,
                m_config.get());
        }

    private:
        std::function<std::pair<Iterator, Iterator>()> m_getItems;
        std::function<std::string()> m_getPreview;
        std::function<ImGuiID(Iterator)> m_getId;
        std::function<std::string(Iterator)> m_getName;
        std::function<bool(Iterator)> m_isSelected;
        std::function<void(Iterator)> m_onSelect;
    };

} // namespace ui::components