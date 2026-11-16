# Slider

**Headers:** 
* `#include <Components/Slider.h>`
* `#include <Builders/UISliderBuilder.h>` (for configuration)

The `Slider` is a templated component that allows the user to select a numerical value from a predefined range by dragging a graphical handle. It inherits from `Component` and `Linkable<T>`.

Supported types are `int` and `float`.

## Configuration (`SliderConfigBuilder<T>`)

To style a `Slider`, generate a `std::shared_ptr<ui::styling::SliderConfig<T>>` using the `SliderConfigBuilder<T>`.

| Builder Method | Description |
| :--- | :--- |
| `min(T)` | The minimum allowed value (defaults to 0). |
| `max(T)` | The maximum allowed value (defaults to 10,000). |
| `width(float)` | The width of the slider relative to the window's total width (e.g., `0.37f` = 37%). |
| `background(const ImVec4&)` | The default background color of the slider track. |
| `onHoverBackground(const ImVec4&)` | The background color of the slider track when hovered. |
| `onActiveBackground(const ImVec4&)` | The background color of the slider track when actively clicked/dragged. |
| `grabBackground(const ImVec4&)` | The default color of the slider grab handle. |
| `onGrabActiveBackground(const ImVec4&)`| The color of the slider grab handle while it is being dragged. |
| **`build()`** | **Returns `std::shared_ptr<ui::styling::SliderConfig<T>>` to be passed to the component.** |

## Component Instantiation

### Emplace Arguments for `Slider<T>`

When calling `emplaceComponent<Slider<T>>(layout, args...)`, the `args...` map directly to the constructor:

1. **`name`** (`const std::string&`): The ImGui ID. *(Automatically prefixed with `##` internally to hide the default text label).*
2. **`config`** (`std::shared_ptr<ui::styling::IConfig>`): The configuration object.

### Additional Class Methods (`ui::components::Slider<T>`)

* **`T* inputValue() const`**
  Returns a pointer to the underlying primitive value holding the slider's current state.

## Data Linking (`Linkable<T>`)

Because `Slider` and `InputBox` both inherit from `Linkable<T>`, you can link them together so they share the exact same memory address. Dragging the slider will update the input box, and typing in the input box will move the slider.

### Example Usage (Linked Slider and InputBox)

```cpp
#include <Components/Window.h>
#include <Components/InputBox.h>
#include <Components/Slider.h>
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

        ui::components::Layout* layout = emplaceLayout();
        
        auto* sizeInput = emplaceComponent<ui::components::InputBox<float>>(layout, "SizeInput", inputConfig);
        auto* sizeSlider = emplaceComponent<ui::components::Slider<float>>(layout, "SizeSlider", sliderConfig);

        // Link the slider directly to the input box memory
        sizeSlider->linkWith(sizeInput);

        // Setting a default value updates both components
        *sizeInput->inputValue() = 50.0f;
    }
};