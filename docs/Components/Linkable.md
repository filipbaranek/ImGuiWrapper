# Linkable

**Header:** `#include <Components/Linkable.h>`

`Linkable<T>` is a templated base class utilized by specific data-entry components (like `Slider` and `InputBox`). It allows two entirely separate UI components to share the exact same underlying memory address for their data.

When two components are linked, interacting with one (e.g., dragging a slider) will instantly and automatically update the other (e.g., the text inside an input box).

## Class Reference (`ui::components::Linkable<T>`)

### Public Methods

* **`void linkWith(Linkable* other)`**
  Points this component's internal data pointer to the same memory address as the `other` component's data pointer.

## Example Usage

```cpp
#include <Components/InputBox.h>
#include <Components/Slider.h>

// Inside a Window's initComponents()...

// 1. Emplace both components
auto* myInputBox = emplaceComponent<ui::components::InputBox<float>>(layout, "Input", inputConfig);
auto* mySlider = emplaceComponent<ui::components::Slider<float>>(layout, "Slider", sliderConfig);

// 2. Link them together
mySlider->linkWith(myInputBox);

// 3. Set a default value using either pointer
*myInputBox->inputValue() = 50.0f;