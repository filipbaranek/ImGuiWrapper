# Slider

**Headers:** 
* `#include <Components/Slider.h>`
* `#include <Builders/UISliderBuilder.h>` (for configuration)
* `#include <Bindings/...>` (for the value, see [Bindings](../Bindings/Binding.md))

The `Slider` is a templated component that allows the user to select a numerical value from a predefined range by dragging a graphical handle. It inherits from `Component`. The value is not stored in the component: it is read from and written to the [binding](../Bindings/Binding.md) passed into the constructor.

Supported types are `int` and `float`.

## Configuration (`SliderConfigBuilder<T>`)

To style a `Slider`, generate a `std::shared_ptr<ui::styling::SliderConfig<T>>` using the `SliderConfigBuilder<T>`.

| Builder Method | Description |
| :--- | :--- |
| `min(T)` | The lowest value the slider handle can be dragged to (defaults to 0). |
| `max(T)` | The highest value the slider handle can be dragged to (defaults to 10,000). |
| `width(float)` | The width of the slider relative to the window's total width (e.g., `0.37f` = 37%). |
| `background(const ImVec4&)` | The default background color of the slider track. |
| `onHoverBackground(const ImVec4&)` | The background color of the slider track when hovered. |
| `onActiveBackground(const ImVec4&)` | The background color of the slider track when actively clicked/dragged. |
| `grabBackground(const ImVec4&)` | The default color of the slider grab handle. |
| `onGrabActiveBackground(const ImVec4&)`| The color of the slider grab handle while it is being dragged. |
| **`build()`** | **Returns `std::shared_ptr<ui::styling::SliderConfig<T>>` to be passed to the component.** |

`min`/`max` only limit the slider handle. To enforce a range on the value itself (also when it is typed into a linked `InputBox`), use a `ClampedBinding<T>`.

## Component Instantiation

### Emplace Arguments for `Slider<T>`

When calling `emplaceComponent<Slider<T>>(layout, args...)`, the `args...` map directly to the constructor:

1. **`name`** (`const std::string&`): The ImGui ID. *(Automatically prefixed with `##` internally to hide the default text label).*
2. **`value`** (`std::shared_ptr<ui::bindings::Binding<T>>`): The binding holding the value. Mandatory, passing `nullptr` throws `std::logic_error`.
3. **`config`** (`std::shared_ptr<ui::styling::IConfig>`): The configuration object.

## Linking a Slider and an InputBox

Pass the same binding to both components. Dragging the slider updates the input box, and typing in the input box moves the slider.

### Example Usage

```cpp
#include <Components/Window.h>
#include <Components/InputBox.h>
#include <Components/Slider.h>
#include <Bindings/ClampedBinding.h>
#include <Builders/UIInputBoxBuilder.h>
#include <Builders/UISliderBuilder.h>
#include <Styling/Common.h>

class ControlsWindow : public ui::components::Window
{
public:
    ControlsWindow() : ui::components::Window("CONTROLS_LAYER") {}

protected:
    void initWindowConfig() override { /* Omitted */ }

    void initComponents() override
    {
        auto inputConfig = InputBoxBuilder().width(0.17f).build();
        auto sliderConfig = SliderConfigBuilder<float>()
            .width(0.36f)
            .max(100.0f)
            .grabBackground(ui::styling::Color::titleBarOrange)
            .build();

        m_size = std::make_shared<ui::bindings::ClampedBinding<float>>(50.0f, 0.01f, 100.0f);

        ui::components::Layout* layout = emplaceLayout();
        
        emplaceComponent<ui::components::InputBox<float>>(layout, "SizeInput", m_size, inputConfig);
        emplaceComponent<ui::components::Slider<float>>(layout, "SizeSlider", m_size, sliderConfig);
    }

private:
    std::shared_ptr<ui::bindings::ClampedBinding<float>> m_size;
};
```
