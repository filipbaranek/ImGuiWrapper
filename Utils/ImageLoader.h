#pragma once
#include <glad/gl.h>

class ImageLoader
{
public:
    ImageLoader() = delete;
    
    ~ImageLoader() = delete;

    static GLuint loadImage(const char* filePath);
};