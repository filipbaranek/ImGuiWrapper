# RadioGroup

**Header:** `#include <Components/RadioGroup.h>`

The `RadioGroup` coordinates a mutually exclusive set of radio buttons. Buttons never talk to each other directly: each one registers itself with its group when constructed, and asks the group to select it when clicked. The group then deselects the others.

## Usage

Declare the group as a member of your `Window` class and pass it to each radio button. The buttons do not need to be added to it separately.

```cpp
ui::components::RadioGroup m_tools;

emplaceComponent<ui::components::RadioButton>(layout, "Move", m_tools, config, [](ui::components::Button*){});
emplaceComponent<ui::components::RadioButton>(layout, "Rotate", m_tools, config, [](ui::components::Button*){});
```

Buttons with different groups do not affect each other.

The group must exist for as long as its buttons can be clicked. A button does not touch its group when it is destroyed, so a group that is a member of a `Window` subclass is safe, even though it is destroyed before the window's components.

## Public Methods

* **`void add(RadioButton* button)`**
  Registers a button with the group. Called automatically by the `RadioButton` constructor.
* **`void select(RadioButton* button)`**
  Deselects every button in the group, then selects the given one. Called by `RadioButton::select()`.
