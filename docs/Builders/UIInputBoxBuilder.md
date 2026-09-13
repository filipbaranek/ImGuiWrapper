# UIInputBoxBuilder

**Header:** `#include <Builders/UIInputBoxBuilder.h>`

The `InputBoxBuilder` is used to construct the configuration object required by the `InputBox<T>` component.

## Methods

| Method | Description |
| :--- | :--- |
| `width(float)` | The width of the input box relative to the window's total width (e.g., `0.17f` = 17%). |
| `background(const ImVec4&)` | The background color of the input box frame. |
| **`build()`** | **Returns `std::shared_ptr<ui::styling::InputBoxConfig>`** |

## Example Usage

```cpp
#include <Builders/UIInputBoxBuilder.h>
#include <Styling/Common.h>

auto inputBoxConfig = InputBoxBuilder()
    .width(0.17f)
    .background(ui::styling::Color::lightGray)
    .build();