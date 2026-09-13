# Styling: CheckBox

**Header:** `#include <Styling/CheckBox.h>`

> **⚠️ INTERNAL API WARNING:** 
> This class is used internally by `ui::components::CheckBox`. **End-users should not instantiate or call these methods directly.** Please use the `CheckBoxConfigBuilder` and `ui::components::CheckBox` instead.

## Overview

The `ui::styling::CheckBox` class handles the transition of a `CheckBoxConfig` into a rendered ImGui checkbox.

### Key Structures
* **`CheckBoxConfig`**: The data struct holding frame colors, checkmark colors, and padding.

### Internal Flow
1. **`init()`**: Pushes `ImGuiCol_CheckMark`, `ImGuiCol_FrameBg`, etc., onto the ImGui style stack. It then executes the `ImGui::Checkbox` draw call, passing the internal boolean pointer from the component.
2. **`destroy()`**: Pops the specific number of styles pushed during the initialization phase to ensure the global ImGui state is not corrupted for subsequent UI elements.