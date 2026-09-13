# UIWindowBuilder

**Header:** `#include <Builders/UIWindowBuilder.h>`

Configuring a `Window` requires the use of up to four different builders to handle its position, size, title bar, and overarching properties.

## WindowPosConfigBuilder

Handles the responsive positioning of the window.

| Method | Description |
| :--- | :--- |
| `relativePosition(bool)` | If true, treats the position coordinates as absolute offsets. If false, treats them as percentages of the viewport. |
| `posX(float)` | X coordinate relative to viewport (e.g., `0.38f` = 38%). |
| `posY(float)` | Y coordinate relative to viewport. |
| `relativePosX(float)` | Exact X coordinate in pixels (used when `relativePosition` is true). |
| `relativePosY(float)` | Exact Y coordinate in pixels. |
| **`build()`** | **Returns `ui::styling::WindowPosConfig&&`** |

## WindowSizeConfigBuilder

Handles the responsive dimensions and minimum bounds of the window.

| Method | Description |
| :--- | :--- |
| `width(float)` | Width relative to the viewport (e.g., `0.25f` = 25%). |
| `height(float)` | Height relative to the viewport. |
| `minWidth(float)` | Minimum allowed viewport width before the window hides itself to prevent layout corruption. |
| `minHeight(float)` | Minimum allowed viewport height before the window hides itself. |
| **`build()`** | **Returns `ui::styling::WindowSizeConfig&&`** |

## WindowTitleBarBuilder

Handles the styling of the window's title bar.

| Method | Description |
| :--- | :--- |
| `background(const ImVec4&)`| Background color of the title bar. |
| `font(ImFont*)` | Font used for the window's title. |
| **`build()`** | **Returns `ui::styling::WindowTitleBarConfig&&`** |

## WindowConfigBuilder (Main Builder)

Combines the configs from above with general window properties.

| Method | Description |
| :--- | :--- |
| `name(const std::string&)` | The ImGui ID and title text of the window. (Mandatory) |
| `layerName(const std::string&)` | The internal name used by `VisibilityHandler`. Defaults to `name` if not set. |
| `background(const ImVec4&)`| The background color of the main window body. |
| `rounding(float)` | The border rounding radius. |
| `flags(ImGuiWindowFlags)` | Standard ImGui flags (e.g., `ImGuiWindowFlags_NoResize`). |
| `pos(const WindowPosConfig&)`| Takes the result of `WindowPosConfigBuilder::build()`. |
| `size(const WindowSizeConfig&)`| Takes the result of `WindowSizeConfigBuilder::build()`. |
| `titleBar(...)` | Takes the result of `WindowTitleBarBuilder::build()`. |
| **`build()`** | **Returns `ui::styling::WindowConfig&&`** |

## Example Usage

```cpp
void MyLayer::initWindowConfig() override
{
    auto posConfig = WindowPosConfigBuilder().posX(0.38f).posY(0.28f).build();
    auto sizeConfig = WindowSizeConfigBuilder().width(0.25f).height(0.4f).build();
    auto titleConfig = WindowTitleBarBuilder().background(ui::styling::Color::titleBarOrange).build();

    m_windowConfig = WindowConfigBuilder()
        .name("My Window")
        .background(ui::styling::Color::transparentGray)
        .rounding(20.0f)
        .pos(posConfig)
        .size(sizeConfig)
        .titleBar(titleConfig)
        .flags(ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove)
        .build();
}