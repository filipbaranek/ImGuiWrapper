# RadioButton

**Headers:** 
* `#include <Components/RadioButton.h>`
* `#include <Builders/UIButtonBuilder.h>` (for configuration)

The `RadioButton` component inherits from `Button`. It is designed to work as part of a mutually exclusive group; when one radio button in the group is clicked, it becomes selected, and all others in the group are automatically deselected.

## Configuration

`RadioButton` uses the standard `ButtonConfigBuilder`. 
*(Note: The active selected state styling is handled internally by the library, which swaps the button's background color to `ui::styling::Color::selectedOrange`).*

## Component Instantiation

### Emplace Arguments for `RadioButton`

When calling `emplaceComponent<RadioButton>(layout, args...)`, the `args...` map to:

1. **`name`** (`const std::string&`): The text displayed on the button (and its ImGui ID).
2. **`group`** (`std::vector<RadioButton*>&`): A reference to a vector tracking all radio buttons in this specific group.
3. **`config`** (`std::shared_ptr<ui::styling::IConfig>`): The styling configuration.
4. **`action`** (`std::function<void(Button*)>`): The callback executed when clicked.

### Additional Class Methods (`ui::components::RadioButton`)

* **`const bool& isSelected() const`**
  Returns true if this radio button is the currently selected one in its group.
* **`void setIsSelected(const bool& isSelected)`**
  Manually overrides the selection state.
* **`std::vector<RadioButton*>& group()`**
  Returns a reference to the group vector this button belongs to.

## Example Usage

```cpp
#include <vector>
#include <Components/Window.h>
#include <Components/RadioButton.h>
#include <Builders/UIButtonBuilder.h>

class OptionsWindow : public ui::components::Window
{
public:
    OptionsWindow() : ui::components::Window("OPTIONS_LAYER") {}

protected:
    void initWindowConfig() override { /* Omitted */ }

    void initComponents() override
    {
        auto config = ButtonConfigBuilder().size(ImVec2{0.04f, 0.02f}).build();
        ui::components::Layout* layout = emplaceLayout();

        // 1. Emplace the components, passing the member vector reference
        auto* r1 = emplaceComponent<ui::components::RadioButton>(layout, "Option A", m_radioGroup, config, [](ui::components::Button*){});
        auto* r2 = emplaceComponent<ui::components::RadioButton>(layout, "Option B", m_radioGroup, config, [](ui::components::Button*){});
        
        // 2. Add them to the group list so they can communicate
        m_radioGroup.push_back(r1);
        m_radioGroup.push_back(r2);
        
        // 3. Set a default selection
        r1->setIsSelected(true);
    }

private:
    std::vector<ui::components::RadioButton*> m_radioGroup;
};