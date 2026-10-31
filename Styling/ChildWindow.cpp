#include "ChildWindow.h"
#include "Utils/VisibilityHandler.h"

namespace ui::styling
{

    namespace
    {
        void initSize(ChildWindowConfig& config)
        {
            auto& sizeConfig = config.size;

            const ImGuiViewport* viewport = ImGui::GetMainViewport();

            const ImVec2 vpSize = viewport->Size;

            sizeConfig.rawSize = ImVec2(sizeConfig.width * vpSize.x, sizeConfig.height * vpSize.y);
        }
    } // namespace

    void ChildWindow::setSize(ChildWindowConfig& config)
    {

        initSize(config);
    }

    void ChildWindow::setRelativeSize(ChildWindowConfig& config)
    {

        initSize(config);
    }

    void ChildWindow::init(ChildWindowConfig& config)
    {
        ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, config.rounding);
        ++config.styles.appliedVarStyles;
        ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, config.borderSize);
        ++config.styles.appliedVarStyles;
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, config.padding);
        ++config.styles.appliedVarStyles;
        ImGui::PushStyleColor(ImGuiCol_ChildBg, config.backgroundColor);
        ++config.styles.appliedColorStyles;
        ImGui::BeginChild(config.name.c_str(), config.size.rawSize, config.childFlags, config.windowFlags);
        
        config.size.realSize = ImGui::GetWindowSize();
    }

    void ChildWindow::destroy(ChildWindowConfig& config)
    {
        ImGui::EndChild();
        ImGui::PopStyleColor(config.styles.appliedColorStyles);
        ImGui::PopStyleVar(config.styles.appliedVarStyles);

        config.styles.appliedColorStyles = 0;
        config.styles.appliedVarStyles = 0;
    }

    void ChildWindow::addToLayout(std::function<void()> asignComponents, const ImVec2& margin)
    {
        const ImVec2 windowSize       = ImGui::GetWindowSize();
        const float responsiveMarginX = windowSize.x * margin.x;
        const float responsiveMarginY = windowSize.y * margin.y;

        if (responsiveMarginX > 0.0f)
        {
            ImGui::Indent(responsiveMarginX);
        }
        ImGui::Dummy(ImVec2{0.0f, responsiveMarginY});
        ImGui::BeginGroup();

        asignComponents();
        
        ImGui::EndGroup();
        ImGui::Dummy(ImVec2{0.0f, responsiveMarginY});
        if (responsiveMarginX > 0.0f)
        {
            ImGui::Unindent(responsiveMarginX);
        }
    }

} // ui::styling