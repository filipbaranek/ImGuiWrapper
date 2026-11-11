# Styling: Label

**Header:** `#include <Styling/Label.h>`

> **⚠️ INTERNAL API WARNING:** 
> This class is used internally by `ui::components::Label`. **End-users should not instantiate or call these methods directly.** Please use the `LabelConfigBuilder` and `ui::components::Label` instead.

## Overview

The `ui::styling::Label` class manages the rendering of text, including dynamic scaling to ensure the font size remains responsive to the viewport resolution.

### Key Structures
* **`LabelConfig`**: Holds the target `ImFont` pointer and the `ImVec4` text color.

### Internal Flow
`Label` derives from [`Styling`](Styling.md), whose `render()` template method runs the following steps:

1. **`pushStyle()`**: 
   * Pushes the target font to ImGui.
   * Calculates a responsive font scale factor based on the current `ImGui::GetMainViewport()->Size` compared to standard text dimensions.
   * Calls `ImGui::SetWindowFontScale()` to adjust the text size.
2. **`draw()`**: Calls `ImGui::TextColored()` to render the string.
3. **`popStyle()`**: Resets the window font scale back to `1.0f` and pops the font from the ImGui stack.