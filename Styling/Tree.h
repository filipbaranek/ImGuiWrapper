#pragma once

#include <functional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "Common.h"

namespace ui::styling
{

    struct TreeConfig : IConfig
    {
        ImVec4 header{};
        ImVec4 headerHovered{};
        ImVec4 headerActive{};
        ImVec2 framePadding{};
        float indentSpacing{};
        float frameRounding{};
        float fontSize{};
        ImGuiTreeNodeFlags flags{ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_DrawLinesFull};
        float treeLineSize{1.0f};
        float treeLinesRounding{0.0f};
    };

    class Tree
    {
    public:
        Tree() = delete;

        template <typename Iterator, typename GetChildren, typename GetId, typename GetName, typename OnSelect>
        static void render(
            const std::string& name,
            Iterator begin,
            Iterator end,
            GetChildren getChildren,
            GetId getId,
            GetName getName,
            OnSelect onSelect,
            IConfig* config)
        {
            auto* treeConfig = dynamic_cast<TreeConfig*>(config);
            if (treeConfig == nullptr)
            {
                throw std::invalid_argument("Tree requires a TreeConfig");
            }

            auto nodes = collectNodes(begin, end, getChildren, getId, getName, onSelect);
            renderNodes(name, nodes, treeConfig);
        }

    private:

        struct Node
        {
            ImGuiID id;
            std::string label;
            bool hasChildren;
            std::function<std::vector<Node>()> loadChildren;
            std::function<void()> onSelect;
            
        };

        template <typename Iterator, typename GetChildren, typename GetId, typename GetName, typename OnSelect>
        static std::vector<Node> collectNodes(Iterator begin, Iterator end, GetChildren& getChildren, GetId& getId, GetName& getName, OnSelect& onSelect)
        {
            std::vector<Node> nodes;
            for (; begin != end; ++begin)
            {
                auto childRange = getChildren(begin);
                const bool hasChildren = childRange.first != childRange.second;
                nodes.push_back({
                    static_cast<ImGuiID>(getId(begin)),
                    getName(begin),
                    hasChildren,
                    [&getChildren,&getId,&getName, &onSelect ,childBegin = childRange.first, childEnd = childRange.second]()
                    {
                        return collectNodes(childBegin, childEnd, getChildren, getId, getName, onSelect);
                    },
                    [&onSelect, iterator = begin] 
                    {
                        onSelect(iterator);
                    }
                });
            }
            return nodes;
        }

        static void renderNodes(const std::string& name, const std::vector<Node>& nodes, TreeConfig* config);
        static void initConfig(TreeConfig* config);
        static void destroy(TreeConfig* config);
    };

} // namespace ui::styling
