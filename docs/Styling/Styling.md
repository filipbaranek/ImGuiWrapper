# Styling: Styling (base class)

**Header:** `#include <Styling/Styling.h>`

> **⚠️ INTERNAL API WARNING:** 
> This class is used internally by the component classes. **End-users should not derive from it or call it directly.**

## Overview

`ui::styling::Styling` is the abstract base class of every component styling class (`Button`, `CheckBox`, `InputBox<T>`, `Label`, `Slider<T>`). It implements the **Template Method** pattern: `render()` fixes the order of the rendering steps, and each derived class supplies the steps.

A styling object is short-lived. A component creates one on the stack in its own `render()` and renders through it:

```cpp
void Label::render()
{
    ui::styling::Label(this).render();
}
```

The constructor of each derived class stores what the steps need (the component or its name and value, and the config cast to its concrete type), so the steps take no arguments.

## Class Reference (`ui::styling::Styling`)

### Public Methods

* **`void render()`**
  The template method. Non-virtual. Calls `pushStyle()`, then `draw()`, then `popStyle()`.

### Protected Virtual Methods

* **`virtual void pushStyle() = 0`**
  Pushes the colors, style variables and fonts of the component onto the ImGui stack.
* **`virtual void popStyle() = 0`**
  Reverts everything pushed in `pushStyle()`, so the global ImGui state is not corrupted for subsequent UI elements.
* **`virtual void draw() = 0`**
  Submits the ImGui widget.
