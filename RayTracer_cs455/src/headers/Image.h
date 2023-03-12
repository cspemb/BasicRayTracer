#pragma once
#include <vector>
#include <glm/vec3.hpp>

#include "Pixel.h"

class Image
{
    const int width {};
    const int height {};
    
    std::vector<Pixel> buffer {};
    
public:
    
    Image(int width, int height)
        : width(width),
          height(height)
    {
        buffer = std::vector<Pixel>(static_cast<std::size_t>(width * height));
    }

    [[nodiscard]] int getWidth() const; 

    [[nodiscard]] int getHeight() const;

    [[nodiscard]] Pixel& at(int x, int y);
};
