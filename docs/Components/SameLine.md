# SameLine

**Header:** `#include <Components/SameLine.h>`

By default, ImGui places every newly rendered item on a new line. The `SameLine` component is a structural helper that forces the *next* component in the layout to be drawn on the same horizontal line as the *previous* one.

## Configuration

`SameLine` requires no styling configuration builders.

## Component Instantiation

### Emplace Arguments for `SameLine`

`SameLine` takes no arguments other than the layout pointer.

## Example Usage

```cpp
#include <Components/Window.h>
#include <Components/Button.h>
#include <Components/SameLine.h>

// Inside initComponents()...
ui::components::Layout* layout = emplaceLayout();

emplaceComponent<ui::components::Button>(layout, "Cancel", btnConfig, [](auto*){});

// Force the next button to be on the same horizontal line
emplaceComponent<ui::components::SameLine>(layout);

emplaceComponent<ui::components::Button>(layout, "Submit", btnConfig, [](auto*){});