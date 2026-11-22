# Placements

**Headers:**
* `#include <Placements/Placement.h>` (interface)
* `#include <Placements/ViewportPlacement.h>`
* `#include <Placements/CenteredPlacement.h>`
* `#include <Placements/AnchoredPlacement.h>`

A placement decides where a [`Window`](../Components/Window.md) is placed on the screen. Every window creates its own placement by overriding the factory method `createPlacement()`. The base `Window` calls it once, on its first `render()`, and then asks the placement for the position every frame, after the window size has been computed. A window cannot be given a placement from outside and cannot change it later.

## Interface (`ui::placements::Placement`)

* **`void setPosition(ui::styling::WindowPosConfig& pos, const ui::styling::WindowSizeConfig& size) const`**
  Writes the top-left corner of the window in screen coordinates into `pos.rawPos`. `size.rawSize` already holds the window's size in pixels for the current frame. Implementations that depend on the screen read the main viewport themselves via `ImGui::GetMainViewport()`.

## Implementations

| Class | Constructor | Position |
| :--- | :--- | :--- |
| `ViewportPlacement` | `ViewportPlacement(float x, float y)` | `x` and `y` as fractions of the viewport (e.g. `0.025f` = 2.5% from the left edge). |
| `CenteredPlacement` | `CenteredPlacement()` | Centered in the viewport, exactly, for any window size. |
| `AnchoredPlacement` | `AnchoredPlacement(std::function<ImVec2()> anchor)` | Whatever point `anchor` returns, evaluated every frame. Useful for windows that follow another element, e.g. a popup next to a button. Throws `std::logic_error` if `anchor` is empty. |

Your own placement only needs to derive from `Placement` and implement `setPosition()`.

## Example Usage

```cpp
#include <Components/Window.h>
#include <Placements/CenteredPlacement.h>
#include <Placements/AnchoredPlacement.h>

class ConfirmDialog : public ui::components::Window
{
    // ...

protected:
    std::unique_ptr<ui::placements::Placement> createPlacement() override
    {
        return std::make_unique<ui::placements::CenteredPlacement>();
    }
};

class ContextMenu : public ui::components::Window
{
    // ...

protected:
    std::unique_ptr<ui::placements::Placement> createPlacement() override
    {
        return std::make_unique<ui::placements::AnchoredPlacement>([this] {
            return m_anchor;
        });
    }

private:
    ImVec2 m_anchor{};
};
```
