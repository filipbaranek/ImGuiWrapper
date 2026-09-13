# ImGuiWrapper

ImGuiWrapper is an object-oriented C++20 static library built on top of [Dear ImGui](https://github.com/ocornut/imgui). It is designed to abstract away the immediate-mode rendering loop into a clean, component-based architecture, making it easier to build complex, responsive, and maintainable user interfaces.

## Key Features

* **Component-Based Architecture:** Build UIs using logical components (`Window`, `Button`, `Slider`, `InputBox`, etc.) instead of raw ImGui function calls.
* **Builder Pattern Styling:** Complete separation of styling and application logic. Configure components cleanly using reusable Builder classes.
* **Responsive Layouts:** Define sizes and positions using percentages of the viewport rather than hardcoded pixels. The library automatically handles dynamic scaling and minimum resolution constraints.
* **Data Linking:** Easily link input fields and sliders to the same underlying memory addresses so they update in tandem.
* **Built-in Utilities:** Includes global visibility state management (`VisibilityHandler`) and OpenGL image loading (`ImageLoader` via `stb_image`).

## Dependencies

The library requires a compiler that supports **C++20** and links against the following libraries:
* `imgui` (Public)
* `glad` (Public - for OpenGL)
* `glm` (Public)
* `stb` (Private - specifically `stb_image`)

## Integration (CMake)

Since `ImGuiWrapper` is set up as a static library, you can easily integrate it into your existing CMake project.

1. Clone this repository into your project (e.g., into a `libs/` or `vendor/` folder).
2. Add it to your `CMakeLists.txt`:

```cmake
add_subdirectory(path/to/ImGuiWrapper)

# Link against your executable
target_link_libraries(YourTargetName PRIVATE ImGuiWrapper)
```
## Quick Start

Creating a UI layer involves inheriting from the `ui::components::Window` base class and implementing two virtual methods:

* `initWindowConfig()` — for styling the window.
* `initComponents()` — for populating it.
```cpp
#include <Components/Window.h>
#include <Components/Button.h>
#include <Builders/UIWindowBuilder.h>
#include <Builders/UIButtonBuilder.h>
#include <Styling/Common.h>
#include <iostream>

class MySettingsWindow : public ui::components::Window
{
public:
    MySettingsWindow() : ui::components::Window("SETTINGS_LAYER") {}

    void onRender()
    {
        // Call this in your main application/ImGui render loop
        this->render(); 
    }

protected:
    void initWindowConfig() override
    {
        auto sizeConfig = WindowSizeConfigBuilder()
            .width(0.2f)
            .height(0.3f)
            .build();

        m_windowConfig = WindowConfigBuilder()
            .name("Settings")
            .background(ui::styling::Color::darkGray)
            .rounding(10.0f)
            .size(sizeConfig)
            .build();
    }

    void initComponents() override
    {
        auto btnConfig = ButtonConfigBuilder()
            .size(ImVec2{0.05f, 0.03f})
            .background(ui::styling::Color::lightGray)
            .onHoverColor(ui::styling::Color::hoverOverOrange)
            .build();

        // Create a layout group
        ui::components::Layout* layout = emplaceLayout();
        layout->reserveComponents(1);

        // Emplace a button component into the layout
        emplaceComponent<ui::components::Button>(layout, "Apply", btnConfig, [](auto* btn) {
            std::cout << "Apply button clicked!" << std::endl;
        });
    }
};
```
## Documentation

For comprehensive documentation on every component, builder, and utility class, please refer to the `docs/` folder.

* [**Read the Documentation**](docs/index.md)
