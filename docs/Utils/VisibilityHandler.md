# VisibilityHandler

**Header:** `#include <Utils/VisibilityHandler.h>`

The `VisibilityHandler` is a static global utility class used to manage the visibility state of entire `Window` layers. It operates using string-based layer names. 

It handles two separate boolean checks for a window:
1. **User Visibility:** Whether the application logic wants the window to be shown (`show()` / `hide()`).
2. **Resolution Range:** Automatically set by the internal Window renderer. If a user resizes the application window below the minimum bounds defined in `WindowSizeConfig`, the layer is flagged as "out of range" and safely hidden to prevent layout corruption.

## Public Static Methods

* **`static void init(const std::string& layer)`**
  Initializes a layer to be hidden and in-range by default.
* **`static bool isVisible(const std::string& layer)`**
  Returns `true` only if the layer is both manually set to visible AND currently in-range based on screen resolution.
* **`static void show(const std::string& layer)`**
  Flags the layer to be visible.
* **`static void hide(const std::string& layer)`**
  Flags the layer to be hidden.
* **`static void setOutOfRange(const std::string& layer)`**
  (Internal/Advanced) Flags the layer as being outside safe resolution bounds.
* **`static void setInRange(const std::string& layer)`**
  (Internal/Advanced) Flags the layer as being within safe resolution bounds.

## Example Usage

```cpp
#include <Utils/VisibilityHandler.h>

// Show a window layer
VisibilityHandler::show("ADDITION_LAYER");

// Hide a window layer
VisibilityHandler::hide("TOOLBAR_LAYER");

// Check if a layer is currently rendering
if (VisibilityHandler::isVisible("SETTINGS_LAYER"))
{
    // Do something
}