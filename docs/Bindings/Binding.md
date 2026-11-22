# Bindings

**Headers:**
* `#include <Bindings/Binding.h>` (interface)
* `#include <Bindings/StoredBinding.h>`
* `#include <Bindings/ClampedBinding.h>`
* `#include <Bindings/ReferenceBinding.h>`

A binding is the place where the value of a data-entry component (`InputBox<T>`, `Slider<T>`) lives. The components do not own their value. Each one receives a `std::shared_ptr<Binding<T>>` in its constructor and only ever calls `get()` and `set()` on it. The code that creates the component (typically a window's `initComponents()`) decides which concrete binding to pass in.

## Interface (`ui::bindings::Binding<T>`)

* **`T get() const`**
  Returns the current value.
* **`void set(const T& value)`**
  Stores a new value. Called by the component only when the user actually changed the value.

## Implementations

| Class | Constructor | Behaviour |
| :--- | :--- | :--- |
| `StoredBinding<T>` | `StoredBinding(const T& value = T{})` | Keeps the value inside the binding. |
| `ClampedBinding<T>` | `ClampedBinding(const T& value, const T& min, const T& max)` | Keeps the value inside the binding and always clamps it to `[min, max]`, no matter which component writes it. Throws `std::logic_error` if `min > max`. |
| `ReferenceBinding<T>` | `ReferenceBinding(T& target)` | Reads and writes a variable owned by the application. The variable must outlive the binding. |

Your own binding (for example one that calls a setter on a model object) only needs to derive from `Binding<T>` and implement `get()` and `set()`.

## Sharing one value between components

Passing the same binding to several components makes them show and edit the same value. Dragging the slider updates the input box and typing into the input box moves the slider.

## Example Usage

```cpp
#include <Components/Window.h>
#include <Components/InputBox.h>
#include <Components/Slider.h>
#include <Bindings/ClampedBinding.h>
#include <Bindings/ReferenceBinding.h>
#include <Builders/UIInputBoxBuilder.h>
#include <Builders/UISliderBuilder.h>

class MeshWindow : public ui::components::Window
{
public:
    MeshWindow() : ui::components::Window("MESH_LAYER") {}

protected:
    void initWindowConfig() override { /* Omitted */ }

    std::unique_ptr<ui::placements::Placement> createPlacement() override { /* Omitted */ }

    void initComponents() override
    {
        using namespace ui::components;
        using namespace ui::bindings;

        auto inputConfig  = InputBoxBuilder().width(0.17f).build();
        auto sliderConfig = SliderConfigBuilder<int>().width(0.37f).max(100).build();

        m_subdivision = std::make_shared<ClampedBinding<int>>(1, 1, 100);

        Layout* layout = emplaceLayout();

        emplaceComponent<InputBox<int>>(layout, "SubdivisionInput", m_subdivision, inputConfig);
        emplaceComponent<Slider<int>>(layout, "SubdivisionSlider", m_subdivision, sliderConfig);
        emplaceComponent<InputBox<float>>(layout, "PosX", std::make_shared<ReferenceBinding<float>>(m_position.x), inputConfig);
    }

private:
    std::shared_ptr<ui::bindings::ClampedBinding<int>> m_subdivision;
    glm::vec3                                          m_position{};
};
```
