# Styling: Slider

**Header:** `#include <Styling/Slider.h>`

> **⚠️ INTERNAL API WARNING:** 
> This class is used internally by `ui::components::Slider<T>`. **End-users should not instantiate or call these methods directly.** Please use the `SliderConfigBuilder<T>` and `ui::components::Slider<T>` instead.

## Overview

The `ui::styling::Slider` class contains templated logic to render ImGui sliders.

### Key Structures
* **`SliderConfig<T>`**: Holds min/max boundaries, dimensions, and complex track/grab handle coloring properties.

### Internal Flow
1. **`render<T>()`**: Specialized for `int` and `float` types.
2. **`initConfig()`**: Pushes up to 5 different color variables (Frame background, hovered frame, active frame, grab color, active grab color). It sets the exact pixel width using `ImGui::SetNextItemWidth`.
3. **ImGui Call**: Calls `ImGui::SliderInt` or `ImGui::SliderFloat`.
4. **`destroy()`**: Cleans up all 5 pushed colors from the stack.