# Component

**Header:** `#include <Components/Component.h>`

The `Component` class is the abstract base class for all UI elements in the ImGuiWrapper library. It handles common state properties such as name, visibility, and configuration.

## Class Reference (`ui::components::Component`)

### Constructor
Component(const std::string& name, std::shared_ptr<ui::styling::IConfig> config);
- **name**: The identifier and display text of the component (often used as the ImGui ID).
- **config**: A shared pointer to a styling configuration object inheriting from `ui::styling::IConfig`.

### Virtual Methods

- **`virtual void render() = 0`**  
  Pure virtual method implemented by derived classes to submit the component to the ImGui draw list.

### Public Methods

- **`const std::string& name() const`**  
  Returns the component's name.

- **`bool isVisible() const`**  
  Returns whether the component is currently flagged to be rendered.

- **`ui::styling::IConfig* config()`**  
  Returns a raw pointer to the component's configuration.

- **`void setIsVisible(bool isVisible)`**  
  Sets the visibility state. If `false`, the layout usually renders a blank dummy space in its place to preserve structure.