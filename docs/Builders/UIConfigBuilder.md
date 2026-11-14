# UIConfigBuilder

**Header:** `#include <Builders/UIConfigBuilder.h>`

`ConfigBuilder` is the abstract builder shared by the configuration builders of interactive components. It declares the steps that every one of them supports, so a `StyleDirector` can run the same construction recipe on any of them and each builder produces its own configuration.

Implemented by:

* `ButtonConfigBuilder` (produces `ButtonConfig`)
* `CheckBoxConfigBuilder` (produces `CheckBoxConfig`)
* `SliderConfigBuilder<T>` (produces `SliderConfig<T>`)

`LabelConfigBuilder`, `InputBoxBuilder` and the window builders do not implement it, because their components have no hover or active state.

## Methods

| Method | Description |
| :--- | :--- |
| `background(const ImVec4&)` | The default background color. |
| `onHoverBackground(const ImVec4&)` | Background color when hovered by the mouse. |
| `onActiveBackground(const ImVec4&)` | Background color while actively clicked or dragged. |
| **`build()`** | **Returns `std::shared_ptr<ui::styling::IConfig>`, ready to be passed to the component.** |

Each concrete builder overrides the steps with its own return type, so a chain can continue with builder-specific steps:

```cpp
auto config = ButtonConfigBuilder()
    .background(ui::styling::Color::black)
    .square(true)
    .build();
```
