# Styling: Button

**Header:** `#include <Styling/Button.h>`

> **⚠️ INTERNAL API WARNING:** 
> These classes are used internally by the `ui::components::Button` family to interface with the raw Dear ImGui backend. **End-users should not instantiate or call these methods directly.** Please use the `ButtonConfigBuilder` and `ui::components::Button` instead.

## Overview

The `ui::styling::Button` class and its subclasses `ImageButton`, `RadioButton` and `RadioImageButton` contain the raw ImGui rendering logic for the button components of the same names. They bridge the gap between the user-defined `ButtonConfig` and the actual ImGui draw commands.

### Key Structures
* **`ButtonConfig`**: The underlying C++ struct holding all properties (colors, dimensions, fonts). This is populated by the `ButtonConfigBuilder`.

### Internal Flow
`Button` derives from [`Styling`](Styling.md), whose `render()` template method is the entry point called by the component. It runs the following steps:

1. **`pushStyle()`**: Takes the `ButtonConfig` and pushes all required ImGui styles onto the stack (`ImGui::PushStyleColor`, `ImGui::PushStyleVar`). It also calculates the responsive absolute size of the button based on the current viewport.
2. **`draw()`**: Invokes the appropriate ImGui command (e.g., `ImGui::Button`, `ImGui::ImageButton`) and triggers the component's callback if clicked. `ImageButton`, `RadioButton` and `RadioImageButton` override only this step.
3. **`popStyle()`**: Cleans up the ImGui state stack by popping all previously pushed colors and variables.