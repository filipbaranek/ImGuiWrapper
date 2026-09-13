# Dummy & RelativeDummy

**Header:** `#include <Components/Dummy.h>`

These components render an invisible, non-interactable blank space. They are primarily used for structural layout spacing (margins/padding) within a `Window`.

## Configuration

Neither component requires a styling configuration builder.

## Component Instantiation

### `Dummy` (Responsive)
Creates spacing relative to the total size of the current ImGui window.

**Emplace Arguments:**
1. **`x`** (`float`): Percentage of the window's width (e.g., `0.13f` = 13%).
2. **`y`** (`float`): Percentage of the window's height.

```cpp
// Adds responsive horizontal spacing
emplaceComponent<ui::components::Dummy>(layout, 0.13f, 0.0f);
```
### RelativeDummy (Absolute)

Creates spacing based on exact, fixed pixel dimensions.

**Emplace Arguments:**

1. **x** (`float`): Absolute width in pixels.
2. **y** (`float`): Absolute height in pixels.

**Example:**

```cpp
// Adds exactly 10 pixels of vertical spacing
emplaceComponent<ui::components::RelativeDummy>(layout, 0.0f, 10.0f);
```

## Example Usage (Indentation)

You can combine `Dummy` with `SameLine` to push elements to the right.

```cpp
#include <Components/Window.h>
#include <Components/Dummy.h>
#include <Components/SameLine.h>
#include <Components/Label.h>

// Inside initComponents()...
emplaceComponent<ui::components::Dummy>(layout, 0.13f, 0.0f);
emplaceComponent<ui::components::SameLine>(layout);
emplaceComponent<ui::components::Label>(layout, "Indented Text", textConfig);
```
