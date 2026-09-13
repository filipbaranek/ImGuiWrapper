# ImGuiWrapper Documentation

Welcome to the ImGuiWrapper library documentation. This library provides an object-oriented, highly customizable wrapper around Dear ImGui. It is designed to streamline the creation of complex user interfaces through a component-based architecture and a builder pattern for styling.

## Table of Contents

### 1. Core Structure
* [Window](Components/Window.md)
* [Layout](Components/Layout.md)
* [Component](Components/Component.md)
* [Linkable](Components/Linkable.md)

### 2. UI Components
* [Button](Components/Button.md)
* [CheckBox](Components/CheckBox.md)
* [Dummy & RelativeDummy](Components/Dummy.md)
* [ImageButton](Components/ImageButton.md)
* [InputBox](Components/InputBox.md)
* [Label](Components/Label.md)
* [RadioButton](Components/RadioButton.md)
* [RadioImageButton](Components/RadioImageButton.md)
* [Spacing Helpers (SameLine & Separator)](Components/SpacingHelpers.md)
* [Slider](Components/Slider.md)

### 3. Builders
* [UIWindowBuilder](Builders/UIWindowBuilder.md)
* [UIButtonBuilder](Builders/UIButtonBuilder.md)
* [UICheckBoxBuilder](Builders/UICheckBoxBuilder.md)
* [UIInputBoxBuilder](Builders/UIInputBoxBuilder.md)
* [UILabelBuilder](Builders/UILabelBuilder.md)
* [UISliderBuilder](Builders/UISliderBuilder.md)

### 4. Utilities
* [VisibilityHandler](Utils/VisibilityHandler.md)
* [ImageLoader](Utils/ImageLoader.md)
* [Styling Helpers (Colors & Fonts)](Styling/StylingHelpers.md)

### 5. Internal Styling API (Advanced)
*Note: These files outline internal implementation details and interface directly with raw ImGui. They are not intended for direct use.*
* [Styling: Window](Styling/Window.md)
* [Styling: Button](Styling/Button.md)
* [Styling: CheckBox](Styling/CheckBox.md)
* [Styling: InputBox](Styling/InputBox.md)
* [Styling: Label](Styling/Label.md)
* [Styling: Slider](Styling/Slider.md)

---

## Architecture Overview

The library operates on a strict `Window` -> `Layout` -> `Component` hierarchy:

1. **Windows** dictate the main ImGui context. You create a custom layer by inheriting from `ui::components::Window`.
2. Inside your custom Window's `initWindowConfig()` method, you define its size, position, and colors using the `WindowConfigBuilder`.
3. Inside the `initComponents()` method, you create **Layouts** using `emplaceLayout()`.
4. You populate these Layouts with **Components** (like buttons, sliders, etc.) using `emplaceComponent<T>()`. 
5. Component styling is handled entirely via dedicated **Builders** (e.g., `ButtonConfigBuilder`) to cleanly separate rendering logic from state logic.