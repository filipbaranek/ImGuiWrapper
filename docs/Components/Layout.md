# Layout

**Header:** `#include <Components/Layout.h>`

The `Layout` class represents a grouping of components within a `Window`. It handles applying optional indentation (margins) and allows you to toggle the visibility of an entire group of components simultaneously.

`Layout` is itself a `Component` that holds other components (the Composite pattern), so a layout can contain other layouts.

## Instantiation

You do not construct top-level Layouts directly. Instead, you call the inherited `emplaceLayout()` method inside a `Window` class's `initComponents()` method.

```cpp
// Creates a layout with 28% horizontal margin and 0% vertical margin
ui::components::Layout* layout = emplaceLayout(ImVec2{ 0.28f, 0.0f });
```

To nest a layout, add it to another layout with `emplaceComponent`:

```cpp
ui::components::Layout* section = emplaceComponent<ui::components::Layout>(layout, ImVec2{ 0.1f, 0.0f });
emplaceComponent<ui::components::Label>(section, "Inside a section", labelConfig);
```

## Hidden Layouts

A hidden top-level layout draws nothing. A hidden nested layout follows the same rule as any other hidden component: its contents are not drawn, and it leaves a one-row placeholder.

## Public Methods

- **`void render()`**  
  Applies the margins and renders each child component. Called automatically by the parent `Window` or `Layout`.

- **`void reserveComponents(int count)`**  
  Pre-allocates memory for the components to avoid dynamic reallocations. Highly recommended for performance.

- **`void setIsVisible(bool isVisible)`**  
  Inherited from `Component`. Toggles the rendering of all components assigned to this layout. This is extremely useful for dialogs where UI sections change dynamically (e.g., swapping between "Mesh Settings" and "Surface Settings").

- **`bool isVisible() const`**  
  Inherited from `Component`. Returns the current visibility state of the layout.

- **`const ImVec2& margin() const`**  
  Returns the responsive margins applied to this layout.

- **`const std::vector<std::unique_ptr<Component>>& components() const`**  
  Returns a reference to the internal list of components.

## Example Usage
```cpp
ui::components::Layout* myLayout = emplaceLayout(ImVec2{ 0.1f, 0.1f });
myLayout->reserveComponents(2);

emplaceComponent<ui::components::Label>(myLayout, "Hidden Info", labelConfig);
emplaceComponent<ui::components::Button>(myLayout, "Action", btnConfig, [](auto*){});

// Hide this entire section of the UI
myLayout->setIsVisible(false);