# UIStyleDirector

**Header:** `#include <Builders/UIStyleDirector.h>`

`StyleDirector` knows the library's recurring color recipes and applies them through any [`ConfigBuilder`](UIConfigBuilder.md). The same recipe therefore produces a `ButtonConfig`, a `CheckBoxConfig` or a `SliderConfig<T>`, depending on the builder it is given.

## Styles

| Style | Background | Hover | Active |
| :--- | :--- | :--- | :--- |
| `StyleDirector::Style::Flat` | given color | given color | given color |
| `StyleDirector::Style::Highlighted` | given color | `Color::hoverOverOrange` | `Color::onClickOrange` |

## Public Methods

* **`StyleDirector(ConfigBuilder& builder)`**
  Creates a director that builds through the given builder. The director does not own the builder.
* **`void construct(Style style, const ImVec4& background)`**
  Runs the recipe of the given style on the builder.

The product is taken from the builder afterwards. Builder steps called after `construct` override the recipe, and builder-specific steps can still be added.

## Example Usage

```cpp
#include <Builders/UICheckBoxBuilder.h>
#include <Builders/UIButtonBuilder.h>
#include <Builders/UIStyleDirector.h>
#include <Styling/Common.h>

CheckBoxConfigBuilder checkBoxBuilder;
StyleDirector(checkBoxBuilder).construct(StyleDirector::Style::Flat, ui::styling::Color::lightGray);
auto checkBoxConfig = checkBoxBuilder
    .checkMarkColor(ui::styling::Color::selectedOrange)
    .build();

ButtonConfigBuilder buttonBuilder;
StyleDirector(buttonBuilder).construct(StyleDirector::Style::Highlighted, ui::styling::Color::darkGray);
auto buttonConfig = buttonBuilder
    .rounding(12.0f)
    .size(ImVec2{ 0.04f, 0.02f })
    .build();
```

The builders can still be used without a director when a component needs a one-off configuration.
