# Icon & IconFactory

**Headers:**
* `#include <Styling/Icon.h>`
* `#include <Styling/IconFactory.h>`

Icons used by `ImageButton` and `RadioImageButton` are shared between buttons. An image file is loaded into an OpenGL texture once, and every button that uses the same file only keeps a pointer to that one icon. This follows the Flyweight pattern.

## State split

* **`IconTexture`** (intrinsic state): the texture loaded from the file. It is the same wherever the icon is used, so it is stored in the icon and shared.
* **`IconPlacement`** (extrinsic state): the ImGui ID (`name`) and the on-screen `size`. These differ for each button, so the icon does not store them. The button passes them in every time it draws the icon.

## Classes

* **`Icon`**: abstract interface with `bool draw(const IconPlacement& placement) const`. Draws the icon as an ImGui image button and returns `true` when it was clicked.
* **`SharedIcon`**: the shared icon. It owns an `IconTexture`. Its constructor is private, so only `IconFactory` can create it.
* **`IconFactory`**: a singleton (`IconFactory::instance()`) that owns all icons. `Icon* getIcon(const std::string& filePath)` returns the icon for that file and loads it only on the first request.
* **Clients**: `ImageButton` and `RadioImageButton` get their icon from the factory in their constructor and build an `IconPlacement` from their name and computed size when drawing.

## Lifetime

The factory keeps every icon and its texture until the program ends. Textures are not deleted when the factory is destroyed, because that happens after the OpenGL context is already gone. The same file at the same path is loaded once per process.

## Example Usage

```cpp
#include <Styling/IconFactory.h>

ui::styling::Icon* icon = ui::styling::IconFactory::instance().getIcon("../images/gui/plus.png");

if (icon->draw(ui::styling::IconPlacement{"AddButton", ImVec2{32.0f, 32.0f}}))
{
    // Clicked
}
```
