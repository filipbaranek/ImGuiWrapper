# RadioImageButton

**Headers:** 
* `#include <Components/RadioImageButton.h>`
* `#include <Builders/UIButtonBuilder.h>` (for configuration)

The `RadioImageButton` utilizes multiple inheritance to combine the features of both `ImageButton` (displays an image instead of text) and `RadioButton` (acts as part of a mutually exclusive selection group).

## Configuration

`RadioImageButton` uses the standard `ButtonConfigBuilder`.

## Component Instantiation

### Emplace Arguments for `RadioImageButton`

When calling `emplaceComponent<RadioImageButton>(layout, args...)`, the `args...` map to:

1. **`name`** (`const std::string&`): The ImGui ID for the button.
2. **`iconFilePath`** (`const std::string&`): The system file path to the image/icon.
3. **`group`** (`std::vector<RadioButton*>&`): A reference to a vector tracking the radio button group.
4. **`config`** (`std::shared_ptr<ui::styling::IConfig>`): The styling configuration.
5. **`action`** (`std::function<void(Button*)>`): The callback executed when clicked.

## Example Usage

```cpp
#include <vector>
#include <Components/Window.h>
#include <Components/RadioImageButton.h>
#include <Builders/UIButtonBuilder.h>

class ToolbarWindow : public ui::components::Window
{
public:
    ToolbarWindow() : ui::components::Window("TOOLBAR_LAYER") {}

protected:
    void initWindowConfig() override { /* Omitted */ }

    void initComponents() override
    {
        auto config = ButtonConfigBuilder().size(ImVec2{0.03f, 0.03f}).build();
        ui::components::Layout* layout = emplaceLayout();

        auto* tool1 = emplaceComponent<ui::components::RadioImageButton>(
            layout, "Tool1", "assets/brush.png", m_toolsGroup, config, [](ui::components::Button*){}
        );
        auto* tool2 = emplaceComponent<ui::components::RadioImageButton>(
            layout, "Tool2", "assets/eraser.png", m_toolsGroup, config, [](ui::components::Button*){}
        );
        
        m_toolsGroup.push_back(tool1);
        m_toolsGroup.push_back(tool2);
    }

private:
    std::vector<ui::components::RadioButton*> m_toolsGroup;
};