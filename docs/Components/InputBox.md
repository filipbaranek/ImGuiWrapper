# InputBox

**Headers:** 
* `#include <Components/InputBox.h>`
* `#include <Builders/UIInputBoxBuilder.h>` (for configuration)
* `#include <Bindings/...>` (for the value, see [Bindings](../Bindings/Binding.md))

The `InputBox` is a templated UI component that allows the user to input data via the keyboard. It inherits from `Component`. The edited value is not stored in the component: it is read from and written to the [binding](../Bindings/Binding.md) passed into the constructor.

Supported types are:
* `int`
* `float`
* `double`
* `std::string` (text input limited to 255 characters)

## Configuration (`InputBoxBuilder`)

To style an `InputBox`, generate a `std::shared_ptr<ui::styling::InputBoxConfig>` using the `InputBoxBuilder`.

| Builder Method | Description |
| :--- | :--- |
| `width(float)` | The width of the input box relative to the window's total width (e.g., `0.17f` = 17%). |
| `background(const ImVec4&)` | The background color of the input box frame. |
| **`build()`** | **Returns `std::shared_ptr<ui::styling::InputBoxConfig>` to be passed to the component.** |

## Component Instantiation

### Emplace Arguments for `InputBox<T>`

When calling `emplaceComponent<InputBox<T>>(layout, args...)`, the `args...` map directly to the constructor:

1. **`name`** (`const std::string&`): The unique ImGui ID for the component. 
   *(Note: The library internally prefixes this name with `##` to hide ImGui's default label rendering. If you want a label, instantiate a separate `Label` component alongside this one).*
2. **`value`** (`std::shared_ptr<ui::bindings::Binding<T>>`): The binding holding the value. Mandatory, passing `nullptr` throws `std::logic_error`.
3. **`config`** (`std::shared_ptr<ui::styling::IConfig>`): The configuration object built via `InputBoxBuilder`.

## Example Usage

```cpp
#include <Components/Window.h>
#include <Components/InputBox.h>
#include <Bindings/StoredBinding.h>
#include <Bindings/ReferenceBinding.h>
#include <Builders/UIInputBoxBuilder.h>
#include <Styling/Common.h>

class DataWindow : public ui::components::Window
{
public:
    DataWindow() : ui::components::Window("DATA_LAYER") {}

protected:
    void initWindowConfig() override { /* Omitted */ }

    std::unique_ptr<ui::placements::Placement> createPlacement() override { /* Omitted */ }

    void initComponents() override
    {
        using namespace ui::bindings;

        auto inputBoxConfig = InputBoxBuilder()
            .width(0.17f)
            .background(ui::styling::Color::lightGray)
            .build();

        m_size = std::make_shared<StoredBinding<int>>(1);

        ui::components::Layout* layout = emplaceLayout();
        layout->reserveComponents(2);

        emplaceComponent<ui::components::InputBox<int>>(layout, "SizeInput", m_size, inputBoxConfig);
        emplaceComponent<ui::components::InputBox<std::string>>(layout, "ApiKeyInput", std::make_shared<ReferenceBinding<std::string>>(m_apiKey), inputBoxConfig);
    }

private:
    std::shared_ptr<ui::bindings::StoredBinding<int>> m_size;
    std::string                                       m_apiKey;
};
```
