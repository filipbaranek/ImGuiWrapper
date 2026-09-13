# Styling Helpers

**Headers:** 
* `#include <Styling/Common.h>` (for Colors)
* `#include <Styling/Font.h>` (for Fonts)

To make styling components fast and consistent, the library provides pre-defined constants for colors and common font loading utilities. These are typically passed directly into component Builders.

## Colors (`ui::styling::Color`)

Pre-defined ImGui color vectors (`ImVec4`).

* `Color::black`
* `Color::gray`
* `Color::darkGray`
* `Color::lightGray`
* `Color::transparentGray`
* `Color::titleBarOrange`
* `Color::hoverOverOrange`
* `Color::onClickOrange`
* `Color::selectedOrange`

## Fonts (`ui::styling::Font`)

Static helpers to load `.ttf` fonts at a specific size. Note that within responsive components (like Buttons or Labels), the text automatically scales to fit the responsive dimensions of the component based on the viewport.

* `Font::regular(float size)` - Loads `OpenSans-Regular.ttf`
* `Font::bold(float size)` - Loads `OpenSans_Condensed-Bold.ttf`
* `Font::extraBold(float size)` - Loads `OpenSans_Condensed-ExtraBold.ttf`

## Example Usage in a Builder

```cpp
auto btnConfig = ButtonConfigBuilder()
    .background(ui::styling::Color::darkGray)
    .font(ui::styling::Font::regular(0.8f))
    .build();