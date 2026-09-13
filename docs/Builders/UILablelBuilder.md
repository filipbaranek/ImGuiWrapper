# UILabelBuilder

**Header:** `#include <Builders/UILabelBuilder.h>`

The `LabelConfigBuilder` is used to construct the configuration object required by the `Label` component.

## Methods

| Method | Description |
| :--- | :--- |
| `font(ImFont*)` | **(Mandatory)** Pointer to an ImGui font. Throws `std::logic_error` if missing on build. |
| `color(const ImVec4&)` | Text color (Defaults to white: `1.0f, 1.0f, 1.0f, 1.0f`). |
| **`build()`** | **Returns `std::shared_ptr<ui::styling::LabelConfig>`** |

## Example Usage

```cpp
#include <Builders/UILabelBuilder.h>
#include <Styling/Common.h>
#include <Styling/Font.h>

auto headlinersConfig = LabelConfigBuilder()
    .font(ui::styling::Font::extraBold(0.025f))
    .color(ui::styling::Color::titleBarOrange)
    .build();