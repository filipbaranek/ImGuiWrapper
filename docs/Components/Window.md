# Window

**Headers:** 
* `#include <Components/Window.h>`
* `#include <Builders/UIWindowBuilder.h>` (for configuration)

The `Window` class is the central structural component of the ImGuiWrapper library. It acts as the base class for all your custom UI layers. It manages its own ImGui window context, handles responsive positioning and sizing, and serves as the container for `Layout` objects and their UI components.

## Configuration (`WindowConfigBuilder`)

Configuring a window involves up to four builders, usually combined inside the `initWindowConfig()` method:
1. `WindowPosConfigBuilder` - Sets responsive relative positioning.
2. `WindowSizeConfigBuilder` - Sets responsive dimensions and minimum constraints.
3. `WindowTitleBarBuilder` - Styles the title bar.
4. `WindowConfigBuilder` - The main builder that brings the others together along with rounding, background color, and ImGui flags.

*(See `docs/Builders/UIWindowBuilder.md` for a full breakdown of these builders).*

## Class Reference (`ui::components::Window`)

To create a new UI window, you must inherit from `ui::components::Window` and implement two protected virtual methods.

### Protected Virtual Methods

* **`virtual void initWindowConfig() = 0`**
  Used to define the window's visual properties, position, size, and flags. Must populate the protected `m_windowConfig` variable.
* **`virtual void initComponents() = 0`**
  Used to create layouts and populate them with components (Buttons, InputBoxes, etc.).

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
  A factory method used to safely instantiate your custom window class, ensuring `initWindowConfig()` and `initComponents()` are called automatically upon creation.

## Example Usage

```cpp
#include <Components/Window.h>
#include <Components/Button.h>
#include <Builders/UIWindowBuilder.h>
#include <Builders/UIButtonBuilder.h>
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