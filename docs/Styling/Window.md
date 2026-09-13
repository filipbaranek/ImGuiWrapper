# Styling: Window

**Header:** `#include <Styling/Window.h>`

> **⚠️ INTERNAL API WARNING:** 
> This class is used internally by the `ui::components::Window` base class. **End-users should not instantiate or call these methods directly.** 

## Overview

The `ui::styling::Window` class acts as the core controller for raw ImGui window contexts. It manages responsive window boundaries, resolution scaling constraints, and layout indentations.

### Key Structures
* **`WindowPosConfig` / `WindowSizeConfig` / `WindowTitleBarConfig` / `WindowConfig`**: The raw data structures holding the window's visual and spatial requirements.

### Internal Flow
1. **Position & Size Setup**:
   * `setPosAndSize()` / `setRelativePosAndSize()` calculations determine the exact screen-space pixels based on viewport percentages. 
   * It also checks the screen resolution against `minWidth` and `minHeight`. If the screen is too small, it hooks into the `VisibilityHandler` to flag the layer as out-of-range, safely hiding it.
2. **`init()`**: Begins the actual `ImGui::Begin()` context, pushing window background, rounding, and title bar colors to the stack.
3. **`addToLayout()`**: Executed per `Layout` group. It calculates responsive margins, utilizes `ImGui::Indent()` and `ImGui::BeginGroup()`, calls a lambda to render all components inside the layout, and then un-indents/ends the group.
4. **`destroy()`**: Calls `ImGui::End()` and cleans up the global style/color stack.