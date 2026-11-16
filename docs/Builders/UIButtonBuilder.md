# UIButtonBuilder

**Header:** `#include <Builders/UIButtonBuilder.h>`

The `ButtonConfigBuilder` is used to construct the configuration object required by `Button`, `ImageButton`, `RadioButton`, and `RadioImageButton`.

## Methods

| Method | Description |
| :--- | :--- |
| `square(bool)` | If true, forces the button to be a perfect square based on the smaller dimension. |
| `rounding(float)` | The border rounding radius. |
| `font(ImFont*)` | Pointer to an ImGui font. Text automatically scales to fit the button. |
| `size(const ImVec2&)` | The responsive size relative to the viewport (e.g., `0.04f` = 4%). |
| `background(const ImVec4&)` | The default background color. |
| `onHoverColor(const ImVec4&)` | Background color when the mouse hovers over the button. |
| `onClickColor(const ImVec4&)` | Background color when the button is actively clicked. |
| `framePadding(const ImVec2&)` | Internal padding between the border and the content. |
| **`build()`** | **Returns `std::shared_ptr<ui::styling::ButtonConfig>`** |

## Example Usage

```cpp
#include <Builders/UIButtonBuilder.h>
#include <Styling/Common.h>
#include <Styling/Font.h>

auto btnConfig = ButtonConfigBuilder()
    .rounding(12.0f)
    .background(ui::styling::Color::darkGray)
    .font(ui::styling::Font::regular(0.8f))
    .size(ImVec2{ 0.04f, 0.02f })
    .onHoverColor(ui::styling::Color::hoverOverOrange)
    .onClickColor(ui::styling::Color::onClickOrange)
    .build();