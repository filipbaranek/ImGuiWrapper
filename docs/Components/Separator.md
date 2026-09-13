# Separator

**Header:** `#include <Components/Separator.h>`

The `Separator` component draws a horizontal line across the layout to visually divide UI sections. The width of the line is responsive, scaling automatically based on the window's total width.

## Configuration

`Separator` requires no styling configuration builders.

## Component Instantiation

### Emplace Arguments for `Separator`

When calling `emplaceComponent<Separator>(layout, args...)`, the `args...` map directly to the constructor:

1. **`length`** (`float`): The length of the line relative to the window's width (e.g., `0.55f` = 55% of the window width).

## Example Usage

```cpp
#include <Components/Window.h>
#include <Components/Separator.h>
#include <Components/Label.h>

// Inside initComponents()...
ui::components::Layout* layout = emplaceLayout();

emplaceComponent<ui::components::Label>(layout, "Section 1", textConfig);

// Draw a line that takes up 55% of the window width
emplaceComponent<ui::components::Separator>(layout, 0.55f);

emplaceComponent<ui::components::Label>(layout, "Section 2", textConfig);