#include "Renderer.h"

void Renderer::processPixel([[maybe_unused]] int x, [[maybe_unused]] int y)
{
    
}

std::shared_ptr<Image> Renderer::render()
{
    for (int y{0}; y < image->getHeight(); y++)
    {
        for (int x{0}; x < image->getWidth(); x++)
        {
            processPixel(x, y);
        }
    }

    return image;
}
