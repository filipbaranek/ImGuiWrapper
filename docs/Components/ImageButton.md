# ImageButton

**Headers:** 
* `#include <Components/ImageButton.h>`
* `#include <Builders/UIButtonBuilder.h>` (for configuration)

The `ImageButton` component extends `Button`. Instead of displaying text, it uses the library's `ImageLoader` to render an OpenGL texture (image) loaded from a specified file path.

## Configuration

`ImageButton` shares the exact same styling configuration builder as a standard `Button`. Use `ButtonConfigBuilder` to define its responsive size, background colors, and rounding. 
*(Note: Any text/font settings applied to the builder will be ignored by `ImageButton`).*

## Component Instantiation

### Emplace Arguments for `ImageButton`

When calling `emplaceComponent<ImageButton>(layout, args...)`, the `args...` map to:

1. **`name`** (`const std::string&`): The ImGui ID for the button.
2. **`iconFilePath`** (`const std::string&`): The system file path to the image/icon to be loaded.
3. **`config`** (`std::shared_ptr<ui::styling::IConfig>`): The styling configuration.
4. **`action`** (`std::function<void(Button*)>`): The callback executed when the button is clicked.

### Additional Class Methods (`ui::components::ImageButton`)

* **`const int textureID() const`**
  Returns the generated OpenGL texture ID used by the underlying image loader.

## Example Usage

```cpp
#include <Components/Window.h>
#include <Components/ImageButton.h>
#include <Builders/UIButtonBuilder.h>
#include <Styling/Common.h>

class MediaWindow : public ui::components::Window
{
public:
    MediaWindow() : ui::components::Window("MEDIA_LAYER") {}

protected:
    void initWindowConfig() override { /* Omitted */ }

    void initComponents() override
    {
        auto iconConfig = ButtonConfigBuilder()
            .size(ImVec2{0.03f, 0.03f})
            .background(ui::styling::Color::transparentGray)
            .onHoverColor(ui::styling::Color::hoverOverOrange)
            .build();

        ui::components::Layout* layout = emplaceLayout();

        emplaceComponent<ui::components::ImageButton>(
            layout, 
            "PlayBtn", 
            "assets/icons/play.png", 
            iconConfig, 
            [](ui::components::Button*) {
                // Play logic here
            }
        );
    }
};