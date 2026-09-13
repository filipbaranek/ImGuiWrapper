# CheckBox

**Headers:** 
* `#include <Components/CheckBox.h>`
* `#include <Builders/UICheckBoxBuilder.h>` (for configuration)

The `CheckBox` component represents a standard boolean toggle UI element. It displays a small box that can be checked or unchecked, alongside an optional text label.

## Configuration (`CheckBoxConfigBuilder`)

To style a `CheckBox`, you must generate a `std::shared_ptr<ui::styling::CheckBoxConfig>` using the `CheckBoxConfigBuilder`.

> **Styling Helpers:** 
> Use predefined colors from `ui::styling::Color` located in `<Styling/Common.h>`.

| Builder Method | Description |
| :--- | :--- |
| `background(const ImVec4&)` | The default background color of the checkbox frame. |
| `onHoverBackground(const ImVec4&)` | The background color of the frame when hovered by the mouse. |
| `onActiveBackground(const ImVec4&)` | The background color of the frame while actively clicked/pressed. |
| `checkMarkColor(const ImVec4&)` | The color of the checkmark icon when the box is toggled on. |
| `framePadding(const ImVec2&)` | Internal padding applied to the checkbox frame. |
| **`build()`** | **Returns `std::shared_ptr<ui::styling::CheckBoxConfig>` to be passed to the component.** |

## Component Instantiation

### Emplace Arguments for `CheckBox`

When calling `emplaceComponent<CheckBox>(layout, args...)`, the `args...` map directly to the `CheckBox` constructor:

1. **`name`** (`const std::string&`): The text displayed next to the checkbox (also acts as the ImGui ID).
2. **`config`** (`std::shared_ptr<ui::styling::IConfig>`): The configuration object built via `CheckBoxConfigBuilder`.

### Additional Class Methods (`ui::components::CheckBox`)

* **`bool* isChecked()`**
  Returns a pointer to the internal boolean tracking the checkbox's state. You can dereference this pointer to read the current state or explicitly set a default state.

## Example Usage

```cpp
#include <Components/Window.h>
#include <Components/CheckBox.h>
#include <Builders/UICheckBoxBuilder.h>
#include <Styling/Common.h>

class SettingsWindow : public ui::components::Window
{
public:
    SettingsWindow() : ui::components::Window("SETTINGS_LAYER") {}

protected:
    void initWindowConfig() override { /* Omitted */ }

    void initComponents() override
    {
        auto checkBoxConfig = CheckBoxConfigBuilder()
            .checkMarkColor(ui::styling::Color::selectedOrange)
            .background(ui::styling::Color::lightGray)
            .onHoverBackground(ui::styling::Color::lightGray)
            .onActiveBackground(ui::styling::Color::lightGray)
            .build();

        ui::components::Layout* layout = emplaceLayout();
        layout->reserveComponents(1);

        auto* myCheckBox = emplaceComponent<ui::components::CheckBox>(layout, "Enable VSync", checkBoxConfig);

        // Optionally set a default state
        *myCheckBox->isChecked() = true;
    }
};