#pragma once

#include <functional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "Common.h"

namespace ui::styling
{

    struct ComboConfig : IConfig
    {
        ImVec4 frameBackground{};
        ImVec4 frameBackgroundHovered{};
        ImVec4 frameBackgroundActive{};
        ImVec4 border{};
        ImVec4 text{};
        ImVec4 popUpBackground{};
        ImVec4 header{};
        ImVec4 headerHovered{};
        ImVec4 headerActive{};
        ImVec4 scrollBarBackground{};
        ImVec4 scrollBarGrab{};
        ImVec4 scrollBarGrabHovered{};
        ImVec4 scrollBarGrabActive{};
        ImVec4 navCursor{};
        ImVec2 framePadding{4,3};
        float frameRounding = 0.0f;
        float frameBorderSize = 0.0f;
        float popUpRounding = 0.0f;
        float popUpBorderSize = 1.0f;
        ImVec2 windowPadding{8,8};
        ImVec2 itemSpacing{8,4};
        ImVec2 itemInnerSpacing{4,4};
        ImVec2 selectableTextAlign{0.0f,0.0f};
        float scrollBarSize = 14.0f;
        float scrollBarRounding = 9.0f;
        float scrollBarPadding = 2.0f;
        float alpha = 1.0f;
        float disabledAlpha = 0.60f;

    };

    class Combo
    {
        public:
        Combo() = delete;

        template <typename Iterator, typename GetId, typename GetName,typename IsSelected ,typename OnSelect>
        static void render(
            const std::string& name,
            const std::string& preview,
            Iterator begin,
            Iterator end,
            GetId getId,
            GetName getName,
            IsSelected isSelected,
            OnSelect onSelect,
            IConfig* config)
        {
            auto* comboConfig = dynamic_cast<ComboConfig*>(config);
            if (comboConfig == nullptr)
            {
                throw std::invalid_argument("Combo requires a ComboConfig");
            }
            auto items = collectItems(begin, end, getId, getName, isSelected, onSelect);
            renderItems(items, name, preview, comboConfig);
        }

    private:

        struct Item
        {
            ImGuiID id;
            std::string label;
            bool isSelected;
            std::function<void()> onSelect;
        };

        template <typename Iterator, typename GetId, typename GetName,typename IsSelected ,typename OnSelect>
        static std::vector<Item> collectItems(
            Iterator begin,
            Iterator end,
            GetId& getId,
            GetName& getName,
            IsSelected& isSelected,
            OnSelect& onSelect)
        {
            std::vector<Item> items;
            for (; begin != end; ++begin)
            {
                items.push_back({
                    static_cast<ImGuiID>(getId(begin)),
                    getName(begin),
                    isSelected(begin),
                    [&onSelect, iterator = begin]
                    {
                        onSelect(iterator);
                    }
                });
            }
            return items;
        }
        static void renderItems(
            const std::vector<Item>& items,
            const std::string& name,
            const std::string& preview,
            ComboConfig* config)
        {
            initConfig(config);
            if (ImGui::BeginCombo(name.c_str(), preview.c_str()))
            {
                for (const auto& item : items)
                {
                    ImGui::PushID(static_cast<int>(item.id));
                    if (ImGui::Selectable(item.label.c_str(), item.isSelected))
                    {
                        item.onSelect();
                    }

                    if (item.isSelected)
                    {
                        ImGui::SetItemDefaultFocus();
                    }
                    ImGui::PopID();
                }
                ImGui::EndCombo();
            }

            destroy(config);
        }
        static void initConfig(ComboConfig* config);
        static void destroy(ComboConfig* config);
    };
};