# Styling: InputBox

**Header:** `#include <Styling/InputBox.h>`

> **⚠️ INTERNAL API WARNING:** 
> This class is used internally by `ui::components::InputBox<T>`. **End-users should not instantiate or call these methods directly.** Please use the `InputBoxBuilder` and `ui::components::InputBox<T>` instead.

## Overview

The `ui::styling::InputBox<T>` class template renders ImGui input fields based on the provided data type.

### Key Structures
* **`InputBoxConfig`**: Holds the width and background color styling for the input frame.

### Internal Flow
`InputBox<T>` derives from [`Styling`](Styling.md), whose `render()` template method runs the following steps:

1. **`pushStyle()`**: Prepares the ImGui state. It calculates the absolute width using `ImGui::SetNextItemWidth` (based on the responsive percentage) and pushes the background color.
2. **`draw()`**: Specialized for `int`, `float`, `double`, and `char`. Depending on the template type, it calls `ImGui::InputInt`, `ImGui::InputFloat`, `ImGui::InputDouble`, or `ImGui::InputText`.
3. **`popStyle()`**: Pops the background color style from the ImGui stack.