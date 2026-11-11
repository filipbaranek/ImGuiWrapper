# Styling: CheckBox

**Header:** `#include <Styling/CheckBox.h>`

> **⚠️ INTERNAL API WARNING:** 
> This class is used internally by `ui::components::CheckBox`. **End-users should not instantiate or call these methods directly.** Please use the `CheckBoxConfigBuilder` and `ui::components::CheckBox` instead.

## Overview

The `ui::styling::CheckBox` class handles the transition of a `CheckBoxConfig` into a rendered ImGui checkbox.

### Key Structures
* **`CheckBoxConfig`**: The data struct holding frame colors, checkmark colors, and padding.

### Internal Flow
`CheckBox` derives from [`Styling`](Styling.md), whose `render()` template method runs the following steps:

1. **`pushStyle()`**: Pushes `ImGuiCol_CheckMark`, `ImGuiCol_FrameBg`, etc., onto the ImGui style stack.
2. **`draw()`**: Executes the `ImGui::Checkbox` draw call, passing the internal boolean pointer from the component.
3. **`popStyle()`**: Pops the specific number of styles pushed in `pushStyle()` to ensure the global ImGui state is not corrupted for subsequent UI elements.