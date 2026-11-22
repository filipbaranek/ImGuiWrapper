# Window

**Headers:** 
* `#include <Components/Window.h>`
* `#include <Builders/UIWindowBuilder.h>` (for configuration)
* `#include <Placements/...>` (for the position, see [Placements](../Placements/Placement.md))

The `Window` class is the central structural component of the ImGuiWrapper library. It acts as the base class for all your custom UI layers. It manages its own ImGui window context, handles responsive positioning and sizing, and serves as the container for `Layout` objects and their UI components.

## Configuration (`WindowConfigBuilder`)

Configuring a window involves up to three builders, usually combined inside the `initWindowConfig()` method:
1. `WindowSizeConfigBuilder` - Sets responsive dimensions and minimum constraints.
2. `WindowTitleBarBuilder` - Styles the title bar.
3. `WindowConfigBuilder` - The main builder that brings the others together along with rounding, background color, and ImGui flags.

*(See `docs/Builders/UIWindowBuilder.md` for a full breakdown of these builders).*

The position of the window is not part of the configuration. It is decided by the [placement](../Placements/Placement.md) the window creates in `createPlacement()`.

## Class Reference (`ui::components::Window`)

To create a new UI window, you must inherit from `ui::components::Window` and implement three protected virtual methods.

### Protected Virtual Methods

* **`virtual void initWindowConfig() = 0`**
  Used to define the window's visual properties, size, and flags. Must populate the protected `m_windowConfig` variable.
* **`virtual void initComponents() = 0`**
  Used to create layouts and populate them with components (Buttons, InputBoxes, etc.).
* **`virtual std::unique_ptr<ui::placements::Placement> createPlacement() = 0`**
  Factory method that decides where the window is placed on the screen, by returning one of the [placements](../Placements/Placement.md) (`ViewportPlacement`, `CenteredPlacement`, `AnchoredPlacement`) or your own. The window calls it once, on its first `render()`, and asks the placement for the position every frame. Returning `nullptr` throws `std::logic_error`.

### Layout and Component Emplacement (Protected)

Inside `initComponents()`, use these methods to build your UI:

* **`Layout* emplaceLayout(const ImVec2& margin = {})`**
  Creates a new layout group inside the window. You can specify responsive margins (e.g., `ImVec2(0.2f, 0.05f)`).
* **`template<typename T, typename... Args> T* emplaceComponent(Layout* layout, Args&&... args)`**
  Instantiates a component of type `T` and assigns it to the specified layout.

### Public Methods

* **`bool isVisible()`**
  Checks the global `VisibilityHandler` to see if this window's layer is currently active and within resolution bounds.
* **`bool clickedOnWindow(const glm::vec2& clickPos)`**
  Takes a screen-space coordinate and returns true if the click falls within this window's bounding box.
* **`template<typename T, typename... Args> static std::unique_ptr<T> create(Args&&... args)`**
  Static helper used to safely instantiate your custom window class, ensuring `initWindowConfig()` and `initComponents()` are called automatically upon creation.

## Example Usage

```cpp
#include <Components/Window.h>
#include <Components/Button.h>
#include <Builders/UIWindowBuilder.h>
#include <Builders/UIButtonBuilder.h>
#include <Placements/CenteredPlacement.h>
#include <Styling/Common.h>

class MyCustomLayer : public ui::components::Window
{
public:
    MyCustomLayer() : ui::components::Window("MY_LAYER") {}

    // Public render method to be called in your application's main loop
    void onImGuiRender()
    {
        this->render(); // Calls the base Window render loop
    }

protected:
    void initWindowConfig() override
    {
        auto sizeConfig = WindowSizeConfigBuilder()
            .width(0.25f)
            .height(0.4f)
            .build();

        m_windowConfig = WindowConfigBuilder()
            .name("My Custom Window")
            .layerName("MY_LAYER")
            .background(ui::styling::Color::gray)
            .rounding(15.0f)
            .size(sizeConfig)
            .build();
    }

    std::unique_ptr<ui::placements::Placement> createPlacement() override
    {
        return std::make_unique<ui::placements::CenteredPlacement>();
    }

    void initComponents() override
    {
        auto btnConfig = ButtonConfigBuilder().size(ImVec2{0.05f, 0.03f}).build();

        ui::components::Layout* layout = emplaceLayout();
        layout->reserveComponents(1);

        emplaceComponent<ui::components::Button>(layout, "Click Me", btnConfig, [](ui::components::Button*) {
            // Action logic
        });
    }
};
```
