#include "Tree.h"

#include <cstdint>

namespace ui::styling
{

    void Tree::initConfig(TreeConfig* config)
    {
        ImGui::PushStyleColor(ImGuiCol_Header, config->header);
        ImGui::PushStyleColor(ImGuiCol_HeaderHovered, config->headerHovered);
        ImGui::PushStyleColor(ImGuiCol_HeaderActive, config->headerActive);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, config->framePadding);
        ImGui::PushStyleVar(ImGuiStyleVar_IndentSpacing, config->indentSpacing);
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, config->frameRounding);
        ImGui::PushStyleVar(ImGuiStyleVar_TreeLinesSize, config->treeLineSize);
        ImGui::PushStyleVar(ImGuiStyleVar_TreeLinesRounding, config->treeLinesRounding);

        config->styles.appliedColorStyles += 3;
        config->styles.appliedVarStyles += 5;
    }

    void Tree::destroy(TreeConfig* config)
    {
        ImGui::PopStyleColor(config->styles.appliedColorStyles);
        ImGui::PopStyleVar(config->styles.appliedVarStyles);

        config->styles.appliedColorStyles = 0;
        config->styles.appliedVarStyles = 0;
    }

    void Tree::renderNodes(const std::string& name, const std::vector<Node>& nodes, TreeConfig* config)
    {
        ImGui::PushFont(nullptr, config->fontSize);
        initConfig(config);
        ImGui::PushID(name.c_str());

        const auto renderNode = [&](const auto& self, const Node& node) -> void
        {
            ImGuiTreeNodeFlags flags = config->flags;
            if (!node.hasChildren)
            {
                flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
            }
            else
            {
                flags &= ~(ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen);
            }

            const bool expanded = ImGui::TreeNodeEx(
                reinterpret_cast<void*>(static_cast<intptr_t>(node.id)),
                flags,
                "%s",
                node.label.c_str());
            
            if (ImGui::IsItemClicked()) {
                node.onSelect();
            }

            if (expanded && node.hasChildren)
            {
                const auto children = node.loadChildren();
                for (const auto& child : children)
                {
                    self(self, child);
                }
                ImGui::TreePop();
            }

        };

        for (const auto& node : nodes)
        {
            renderNode(renderNode, node);
        }

        ImGui::PopID();
        destroy(config);
        ImGui::PopFont();
    }

} // namespace ui::styling
