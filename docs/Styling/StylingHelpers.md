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

Static helpers to get `.ttf` fonts at a specific size. Note that within responsive components (like Buttons or Labels), the text automatically scales to fit the responsive dimensions of the component based on the viewport.

* `Font::regular(float size)` - Returns `OpenSans-Regular.ttf`
* `Font::bold(float size)` - Returns `OpenSans_Condensed-Bold.ttf`
* `Font::extraBold(float size)` - Returns `OpenSans_Condensed-ExtraBold.ttf`

A font is loaded the first time a file and size are requested. Later calls with the same file and size return the same `ImFont*`, so components can share a font without reading the file again. Colour, scale and position are not part of the font, so components sharing one can still differ in them.

The returned pointers belong to the ImGui context, so they are only valid while it exists. The fonts are remembered for the whole process, so create one ImGui context per process: do not call these helpers after destroying a context and creating a new one.

## Example Usage in a Builder

```cpp
auto btnConfig = ButtonConfigBuilder()
    .background(ui::styling::Color::darkGray)
    .font(ui::styling::Font::regular(0.8f))
    .build();