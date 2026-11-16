# Button

**Headers:** 
* `#include <Components/Button.h>`
* `#include <Builders/UIButtonBuilder.h>` (for configuration)

The `Button` component represents a standard clickable UI button. When clicked, it triggers a custom action defined via a `std::function`. 

*(Note: Specialized buttons like `ImageButton`, `RadioButton`, and `RadioImageButton` are documented in their respective files.)*

## Configuration (`ButtonConfigBuilder`)

To style a `Button`, you must generate a `std::shared_ptr<ui::styling::ButtonConfig>` using the `ButtonConfigBuilder`.

> **Styling Helpers:** 
> Instead of manually creating ImGui fonts and color vectors, you can easily use the library's predefined styling utilities:
> * **Colors:** Use `ui::styling::Color` (e.g., `ui::styling::Color::darkGray`, `ui::styling::Color::hoverOverOrange`) located in `<Styling/Common.h>`.
> * **Fonts:** Use `ui::styling::Font` (e.g., `ui::styling::Font::regular(0.8f)`) located in `<Styling/Font.h>`.

| Builder Method | Description |
| :--- | :--- |
| `square(bool)` | If true, forces the button to be a perfect square (uses the smaller dimension of its relative size). |
| `rounding(float)` | The border rounding radius. |
| `font(ImFont*)` | Pointer to an ImGui font. Easily obtained via `ui::styling::Font`. Text automatically scales to fit the button. |
| `size(const ImVec2&)` | The responsive size of the button relative to the viewport size (e.g., `0.04f` = 4%). |
| `background(const ImVec4&)` | The default background color. Easily obtained via `ui::styling::Color`. |
| `onHoverColor(const ImVec4&)` | The background color when hovered by the mouse. |
| `onClickColor(const ImVec4&)` | The background color while actively clicked/pressed. |
| `framePadding(const ImVec2&)` | Internal padding between the button border and its text. |
| **`build()`** | **Returns `std::shared_ptr<ui::styling::ButtonConfig>` to be passed to the component.** |

## Component Instantiation

In this library, components are typically instantiated inside a `Window` class via `emplaceComponent<T>()` on a layout, rather than being created manually.

### Emplace Arguments for `Button`

When calling `emplaceComponent<Button>(layout, args...)`, the `args...` map directly to the `Button` constructor:

1. **`name`** (`const std::string&`): The text displayed on the button (also acts as the ImGui ID).
2. **`config`** (`std::shared_ptr<ui::styling::IConfig>`): The configuration object built via `ButtonConfigBuilder`.
3. **`action`** (`std::function<void(Button*)>`): The callback executed when the button is clicked.

### Additional Class Methods (`ui::components::Button`)

* **`void setAction(std::function<void(Button*)> action)`**
  Dynamically updates the action triggered by the button click.
* **`void execute()`**
  Manually triggers the assigned action. Automatically called by the render loop when clicked.

## Example Usage

This example demonstrates how to configure and emplace `Button` components within a custom `Window` class layer.

```cpp
#include <Components/Window.h>
#include <Components/Button.h>
#include <Builders/UIButtonBuilder.h>
#include <Styling/Font.h>
#include <Styling/Common.h>
#include <iostream>

class ToolbarWindow : public ui::components::Window
{
public:
    ToolbarWindow() : ui::components::Window("TOOLBAR_LAYER") {}

protected:
    void initWindowConfig() override
    {
        // Window configuration omitted for brevity
    }

    void initComponents() override
    {
        // 1. Build the shared configuration for our buttons
        auto defaultBtnConfig = ButtonConfigBuilder()
            .rounding(12.0f)
            .background(ui::styling::Color::darkGray)
            .font(ui::styling::Font::regular(0.8f))
            .size(ImVec2{ 0.04f, 0.02f })
            .onHoverColor(ui::styling::Color::hoverOverOrange)
            .onClickColor(ui::styling::Color::onClickOrange)
            .build();

        // 2. Create a layout and reserve space
        ui::components::Layout* layout = emplaceLayout();
        layout->reserveComponents(2);

        // 3. Emplace the Button components into the layout
        emplaceComponent<ui::components::Button>(layout, "Save", defaultBtnConfig, [](ui::components::Button*) {
            std::cout << "Save button clicked!" << std::endl;
        });

        emplaceComponent<ui::components::Button>(layout, "Cancel", defaultBtnConfig, [](ui::components::Button*) {
            std::cout << "Cancel button clicked!" << std::endl;
        });
    }
};