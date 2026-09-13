# Label

**Headers:** 
* `#include <Components/Label.h>`
* `#include <Builders/UILabelBuilder.h>` (for configuration)

The `Label` component displays static text on the screen. It automatically calculates and scales its font size based on the window's resolution to maintain a responsive design layout.

## Configuration (`LabelConfigBuilder`)

To style a `Label`, you must generate a `std::shared_ptr<ui::styling::LabelConfig>` using the `LabelConfigBuilder`.

> **Styling Helpers:** 
> * **Colors:** Use `ui::styling::Color` located in `<Styling/Common.h>`.
> * **Fonts:** Use `ui::styling::Font` located in `<Styling/Font.h>`.

| Builder Method | Description |
| :--- | :--- |
| `font(ImFont*)` | **(Mandatory)** Pointer to an ImGui font. The component will throw a `std::logic_error` if this is not provided during `build()`. |
| `color(const ImVec4&)` | The text color. Defaults to white (`1.0f, 1.0f, 1.0f, 1.0f`) if not explicitly set. |
| **`build()`** | **Returns `std::shared_ptr<ui::styling::LabelConfig>` to be passed to the component.** |

## Component Instantiation

### Emplace Arguments for `Label`

When calling `emplaceComponent<Label>(layout, args...)`, the `args...` map directly to the `Label` constructor:

1. **`text`** (`const std::string&`): The text to be displayed.
2. **`config`** (`std::shared_ptr<ui::styling::IConfig>`): The configuration object built via `LabelConfigBuilder`.

## Example Usage

```cpp
#include <Components/Window.h>
#include <Components/Label.h>
#include <Builders/UILabelBuilder.h>
#include <Styling/Font.h>
#include <Styling/Common.h>

class InfoWindow : public ui::components::Window
{
public:
    InfoWindow() : ui::components::Window("INFO_LAYER") {}

protected:
    void initWindowConfig() override { /* Omitted */ }

    void initComponents() override
    {
        auto headlinerConfig = LabelConfigBuilder()
            .font(ui::styling::Font::extraBold(0.025f))
            .color(ui::styling::Color::titleBarOrange)
            .build();

        auto textConfig = LabelConfigBuilder()
            .font(ui::styling::Font::regular(0.02f))
            .color(ui::styling::Color::lightGray)
            .build();

        ui::components::Layout* layout = emplaceLayout();
        layout->reserveComponents(2);

        emplaceComponent<ui::components::Label>(layout, "Settings", headlinerConfig);
        emplaceComponent<ui::components::Label>(layout, "Configure your application below.", textConfig);
    }
};