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
    
    Image(int width, int height, const glm::vec3& bgColor)
        : width(width),
          height(height)
    {
        // Initialize each pixel with bgColor filled in
        buffer = std::vector(static_cast<std::size_t>(width * height), Pixel{bgColor});
    }

    [[nodiscard]] int getWidth() const; 

    [[nodiscard]] int getHeight() const;

    [[nodiscard]] const Pixel& at(int x, int y) const;
};
