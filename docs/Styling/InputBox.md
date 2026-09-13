# Styling: InputBox

**Header:** `#include <Styling/InputBox.h>`

> **⚠️ INTERNAL API WARNING:** 
> This class is used internally by `ui::components::InputBox<T>`. **End-users should not instantiate or call these methods directly.** Please use the `InputBoxBuilder` and `ui::components::InputBox<T>` instead.

## Overview

The `ui::styling::InputBox` class provides templated static methods to render ImGui input fields based on the provided data type.

### Key Structures
* **`InputBoxConfig`**: Holds the width and background color styling for the input frame.

### Internal Flow
1. **`render<T>()`**: Specialized for `int`, `float`, `double`, and `char`. 
2. **`initConfig()`**: Prepares the ImGui state. It calculates the absolute width using `ImGui::SetNextItemWidth` (based on the responsive percentage) and pushes the background color.
3. **ImGui Call**: Depending on the template type, it calls `ImGui::InputInt`, `ImGui::InputFloat`, `ImGui::InputDouble`, or `ImGui::InputText`.
4. **`destroy()`**: Pops the background color style from the ImGui stack.