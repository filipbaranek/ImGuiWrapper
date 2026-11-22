# UIWindowBuilder

**Header:** `#include <Builders/UIWindowBuilder.h>`

Configuring a `Window` requires the use of up to three different builders to handle its size, title bar, and overarching properties. The position of the window is not configured here; it is decided by the window's [placement](../Placements/Placement.md).

## WindowSizeConfigBuilder

Handles the responsive dimensions and minimum bounds of the window.

| Method | Description |
| :--- | :--- |
| `width(float)` | Width relative to the viewport (e.g., `0.25f` = 25%). |
| `height(float)` | Height relative to the viewport. |
| `minWidth(float)` | Minimum allowed viewport width before the window hides itself to prevent layout corruption. |
| `minHeight(float)` | Minimum allowed viewport height before the window hides itself. |
| **`build()`** | **Returns `ui::styling::WindowSizeConfig`** |

## WindowTitleBarBuilder

Handles the styling of the window's title bar.

| Method | Description |
| :--- | :--- |
| `background(const ImVec4&)`| Background color of the title bar. |
| `font(ImFont*)` | Font used for the window's title. |
| **`build()`** | **Returns `ui::styling::WindowTitleBarConfig`** |

## WindowConfigBuilder (Main Builder)

Combines the configs from above with general window properties.

| Method | Description |
| :--- | :--- |
| `name(const std::string&)` | The ImGui ID and title text of the window. (Mandatory) |
| `layerName(const std::string&)` | The internal name used by `VisibilityHandler`. Defaults to `name` if not set. |
| `background(const ImVec4&)`| The background color of the main window body. |
| `rounding(float)` | The border rounding radius. |
| `flags(ImGuiWindowFlags)` | Standard ImGui flags (e.g., `ImGuiWindowFlags_NoResize`). |
| `size(const WindowSizeConfig&)`| Takes the result of `WindowSizeConfigBuilder::build()`. |
| `titleBar(...)` | Takes the result of `WindowTitleBarBuilder::build()`. |
| **`build()`** | **Returns `ui::styling::WindowConfig`** |

## Example Usage

```cpp
void MyLayer::initWindowConfig() override
{
    auto sizeConfig = WindowSizeConfigBuilder().width(0.25f).height(0.4f).build();
    auto titleConfig = WindowTitleBarBuilder().background(ui::styling::Color::titleBarOrange).build();

    m_windowConfig = WindowConfigBuilder()
        .name("My Window")
        .background(ui::styling::Color::transparentGray)
        .rounding(20.0f)
        .size(sizeConfig)
        .titleBar(titleConfig)
        .flags(ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove)
        .build();
}