# Styling: Slider

**Header:** `#include <Styling/Slider.h>`

> **⚠️ INTERNAL API WARNING:** 
> This class is used internally by `ui::components::Slider<T>`. **End-users should not instantiate or call these methods directly.** Please use the `SliderConfigBuilder<T>` and `ui::components::Slider<T>` instead.

## Overview

The `ui::styling::Slider<T>` class template contains the logic to render ImGui sliders.

### Key Structures
* **`SliderConfig<T>`**: Holds min/max boundaries, dimensions, and complex track/grab handle coloring properties.

### Internal Flow
`Slider<T>` derives from [`Styling`](Styling.md), whose `render()` template method runs the following steps:

1. **`pushStyle()`**: Pushes up to 5 different color variables (Frame background, hovered frame, active frame, grab color, active grab color). It sets the exact pixel width using `ImGui::SetNextItemWidth`.
2. **`draw()`**: Specialized for `int` and `float` types. Calls `ImGui::SliderInt` or `ImGui::SliderFloat`.
3. **`popStyle()`**: Cleans up all 5 pushed colors from the stack.