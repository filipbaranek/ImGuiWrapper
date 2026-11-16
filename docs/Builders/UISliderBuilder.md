# UISliderBuilder

**Header:** `#include <Builders/UISliderBuilder.h>`

The `SliderConfigBuilder<T>` is a templated builder used to construct the configuration object required by the `Slider<T>` component. You must specify the type (`int` or `float`) when instantiating the builder.

## Methods

| Method | Description |
| :--- | :--- |
| `min(T)` | The minimum allowed value of the slider. |
| `max(T)` | The maximum allowed value of the slider. |
| `width(float)` | Width relative to the window's total width (e.g., `0.37f` = 37%). |
| `background(const ImVec4&)` | Default background color of the slider track. |
| `onHoverBackground(...)` | Track color when hovered. |
| `onActiveBackground(...)` | Track color when actively clicked/dragged. |
| `grabBackground(...)` | Default color of the grab handle itself. |
| `onGrabActiveBackground(...)`| Color of the grab handle while it is being dragged. |
| **`build()`** | **Returns `std::shared_ptr<ui::styling::SliderConfig<T>>`** |

## Example Usage

```cpp
#include <Builders/UISliderBuilder.h>
#include <Styling/Common.h>

// Example for an integer slider
auto intSliderConfig = SliderConfigBuilder<int>()
    .width(0.37f)
    .min(1)
    .max(100)
    .background(ui::styling::Color::lightGray)
    .grabBackground(ui::styling::Color::titleBarOrange)
    .build();

// Example for a float slider
auto floatSliderConfig = SliderConfigBuilder<float>()
    .width(0.36f)
    .min(0.0f)
    .max(100.0f)
    .background(ui::styling::Color::lightGray)
    .grabBackground(ui::styling::Color::titleBarOrange)
    .build();