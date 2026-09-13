# Styling: Button

**Header:** `#include <Styling/Button.h>`

> **⚠️ INTERNAL API WARNING:** 
> This class is used internally by the `ui::components::Button` family to interface with the raw Dear ImGui backend. **End-users should not instantiate or call these methods directly.** Please use the `ButtonConfigBuilder` and `ui::components::Button` instead.

## Overview

The `ui::styling::Button` class contains the raw ImGui rendering logic for all button types (`DEFAULT`, `IMAGE`, `RADIO`, `RADIO_IMAGE`). It bridges the gap between the user-defined `ButtonConfig` and the actual ImGui draw commands.

### Key Structures
* **`ButtonConfig`**: The underlying C++ struct holding all properties (colors, dimensions, fonts). This is populated by the `ButtonConfigBuilder`.

### Internal Flow
1. **`render<T>()`**: The main entry point called by the component. It delegates to the following steps:
2. **`init()`**: Takes the `ButtonConfig` and pushes all required ImGui styles onto the stack (`ImGui::PushStyleColor`, `ImGui::PushStyleVar`). It also calculates the responsive absolute size of the button based on the current viewport.
3. **`draw<T>()`**: A templated method specialized for each button type. It invokes the appropriate ImGui command (e.g., `ImGui::Button`, `ImGui::ImageButton`) and triggers the component's callback if clicked.
4. **`destroy()`**: Cleans up the ImGui state stack by popping all previously pushed colors and variables.