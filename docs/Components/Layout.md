# Layout

**Header:** `#include <Components/Layout.h>`

The `Layout` class represents a grouping of components within a `Window`. It handles applying optional indentation (margins) and allows you to toggle the visibility of an entire group of components simultaneously.

## Instantiation

You do not construct Layouts directly. Instead, you call the inherited `emplaceLayout()` method inside a `Window` class's `initComponents()` method.

```cpp
// Creates a layout with 28% horizontal margin and 0% vertical margin
ui::components::Layout* layout = emplaceLayout(ImVec2{ 0.28f, 0.0f });
```
## Public Methods

- **`void reserveComponents(int count)`**  
  Pre-allocates memory for the components to avoid dynamic reallocations. Highly recommended for performance.

- **`void setIsVisible(bool isVisible)`**  
  Toggles the rendering of all components assigned to this layout. This is extremely useful for dialogs where UI sections change dynamically (e.g., swapping between "Mesh Settings" and "Surface Settings").

- **`const bool isVisible() const`**  
  Returns the current visibility state of the layout.

- **`const ImVec2& margin() const`**  
  Returns the responsive margins applied to this layout.

- **`const std::vector<std::unique_ptr<Component>>& components() const`**  
  Returns a reference to the internal list of components. (Used primarily by the internal rendering loop).

## Example Usage
```cpp
ui::components::Layout* myLayout = emplaceLayout(ImVec2{ 0.1f, 0.1f });
myLayout->reserveComponents(2);

emplaceComponent<ui::components::Label>(myLayout, "Hidden Info", labelConfig);
emplaceComponent<ui::components::Button>(myLayout, "Action", btnConfig, [](auto*){});

// Hide this entire section of the UI
myLayout->setIsVisible(false);