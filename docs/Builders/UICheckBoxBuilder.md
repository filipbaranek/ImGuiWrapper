# UICheckBoxBuilder

**Header:** `#include <Builders/UICheckBoxBuilder.h>`

The `CheckBoxConfigBuilder` is used to construct the configuration object required by the `CheckBox` component. It implements [`ConfigBuilder`](UIConfigBuilder.md), so it can also be used with a [`StyleDirector`](UIStyleDirector.md).

## Methods

| Method | Description |
| :--- | :--- |
| `background(const ImVec4&)` | The default background color of the checkbox frame. |
| `onHoverBackground(const ImVec4&)` | Background color when hovered by the mouse. |
| `onActiveBackground(const ImVec4&)` | Background color when actively clicked. |
| `checkMarkColor(const ImVec4&)` | The color of the checkmark icon when the box is toggled on. |
| `framePadding(const ImVec2&)` | Internal padding applied to the frame. |
| **`build()`** | **Returns `std::shared_ptr<ui::styling::IConfig>` holding a `CheckBoxConfig`** |

## Example Usage

```cpp
#include <Builders/UICheckBoxBuilder.h>
#include <Styling/Common.h>

auto checkBoxConfig = CheckBoxConfigBuilder()
    .checkMarkColor(ui::styling::Color::selectedOrange)
    .background(ui::styling::Color::lightGray)
    .onHoverBackground(ui::styling::Color::hoverOverOrange)
    .onActiveBackground(ui::styling::Color::onClickOrange)
    .build();