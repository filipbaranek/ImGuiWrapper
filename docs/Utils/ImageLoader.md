# ImageLoader

**Header:** `#include <Utils/ImageLoader.h>`

The `ImageLoader` is a static utility that abstracts the process of loading an image file from the disk and converting it into an OpenGL texture ID that ImGui can render. It relies internally on `stb_image` and `glad`.

*(Note: This is used internally by `ImageButton` and `RadioImageButton`, but can be utilized anywhere an ImGui texture is required).*

## Public Static Methods

* **`static GLuint loadImage(const char* filePath)`**
  Reads the image at the provided file path, generates an OpenGL texture, applies linear filtering, and uploads the image data to the GPU. Returns the OpenGL texture ID (`GLuint`). If the image fails to load, it returns `0`.

## Example Usage

```cpp
#include <Utils/ImageLoader.h>
#include <imgui.h>

// Load the texture
GLuint myTextureId = ImageLoader::loadImage("assets/images/logo.png");

if (myTextureId != 0)
{
    // Render the texture manually using raw ImGui
    ImGui::Image((void*)(intptr_t)myTextureId, ImVec2(200.0f, 200.0f));
}