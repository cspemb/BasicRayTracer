#include "Renderer.h"

#include <inttypes.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>

void Renderer::ray_color(std::shared_ptr<Ray> r, Pixel& pixel) const {
    const auto& object {scene.getObjects().at(0)};
    if (object->intersect(r))
    {
        pixel.r = 255;
        pixel.g = 0;
        pixel.b = 0;
        return;
    }
    
    auto unit_direction = normalize(r->getDirection());
    auto t = 0.5f*(unit_direction.y + 1.0f);

    auto getColor{
    [t](float scalar)
    {
        return static_cast<uint8_t>(((1.0f - t) + (t * scalar)) * 255);
    }};
    
    pixel.r = getColor(.5f);
    pixel.g = getColor(.7f);
    pixel.b = getColor(1.0f);
}


void Renderer::processPixel(int x,  int y) const 
{
    auto u = static_cast<float>(x) / imWidth;
    auto v = static_cast<float>(y) / imHeight;
    const std::shared_ptr<Ray> r = scene.getCamera().getRay(u, v);
    ray_color(r, image->at(x, y));
}

std::shared_ptr<Image> Renderer::render()
{
    for (int y{image->getHeight() - 1}; y >= 0; y--)
    {
        for (int x{0}; x < image->getWidth(); x++)
        {
            processPixel(x, y);
        }
    }

    return image;
}
