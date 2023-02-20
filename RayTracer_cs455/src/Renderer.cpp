#include "Renderer.h"

void Renderer::processPixel([[maybe_unused]] int x, [[maybe_unused]] int y)
{
    
}

std::shared_ptr<Image> Renderer::render()
{
    for (int y{0}; y < this->image->getHeight(); y++)
    {
        for (int x{0}; x < this->image->getWidth(); x++)
        {
            processPixel(x, y);
        }
    }

    return this->image;
}
