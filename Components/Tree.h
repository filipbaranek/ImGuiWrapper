#pragma once
#include <functional>
#include <string>
#include <utility>

#include "Components/Component.h"
#include "Styling/Tree.h"

namespace ui::components
{

    template<typename T, typename Iterator>
    class Tree : public Component
    {
    public:
        Tree(
            const std::string& name,
            std::shared_ptr<ui::styling::IConfig> config,
            std::function<std::pair<Iterator, Iterator>()> getRoots,
            std::function<std::pair<Iterator, Iterator>(Iterator)> getChildren,
            std::function<ImGuiID(Iterator)> getId,
            std::function<std::string(Iterator)> getName,
            std::function<void(Iterator)> onSelect)
            : Component("##" + name, std::move(config))
            , m_getRoots(std::move(getRoots))
            , m_getChildren(std::move(getChildren))
            , m_getId(std::move(getId))
            , m_getName(std::move(getName))
            , m_onSelect(std::move(onSelect))
        { }

        void render() override
        {
            const auto [begin,end] = m_getRoots();
            ui::styling::Tree::render(
                m_name,
                begin,
                end,
                m_getChildren,
                m_getId,
                m_getName,
                m_onSelect,
                m_config.get());
        }


    private:
        std::function<std::pair<Iterator, Iterator>()> m_getRoots;
        std::function<std::pair<Iterator, Iterator>(Iterator)> m_getChildren;
        std::function<ImGuiID(Iterator)> m_getId;
        std::function<std::string(Iterator)> m_getName;
        std::function<void(Iterator)> m_onSelect;
    };

} // ui::components