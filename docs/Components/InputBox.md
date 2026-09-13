# InputBox

**Headers:** 
* `#include <Components/InputBox.h>`
* `#include <Builders/UIInputBoxBuilder.h>` (for configuration)

The `InputBox` is a templated UI component that allows the user to input data via the keyboard. It inherits from `Component` and `Linkable<T>`.

Supported types are:
* `int`
* `float`
* `double`
* `char` (Specialized template representing a 256-character text buffer)

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
2. **`config`** (`std::shared_ptr<ui::styling::IConfig>`): The configuration object built via `InputBoxBuilder`.

### Additional Class Methods (`ui::components::InputBox<T>`)

* **`T* inputValue() const`** (For `int`, `float`, `double`)
  Returns a pointer to the underlying primitive value holding the user's input. Dereference to read or write default values.
* **`char* inputValue()`** (For `char` specialization)
  Returns a pointer to the internal character buffer.

## Example Usage

```cpp
#include <Components/Window.h>
#include <Components/InputBox.h>
#include <Builders/UIInputBoxBuilder.h>
#include <Styling/Common.h>

class DataWindow : public ui::components::Window
{
public:
    DataWindow() : ui::components::Window("DATA_LAYER") {}

protected:
    void initWindowConfig() override { /* Omitted */ }

    void initComponents() override
    {
        auto inputBoxConfig = InputBoxBuilder()
            .width(0.17f)
            .background(ui::styling::Color::lightGray)
            .build();

        ui::components::Layout* layout = emplaceLayout();
        layout->reserveComponents(2);

        // 1. Integer Input
        auto* sizeInput = emplaceComponent<ui::components::InputBox<int>>(layout, "SizeInput", inputBoxConfig);
        *sizeInput->inputValue() = 1; // Set default value

        // 2. Text Input
        auto* apiKeyInput = emplaceComponent<ui::components::InputBox<char>>(layout, "ApiKeyInput", inputBoxConfig);
    }
};