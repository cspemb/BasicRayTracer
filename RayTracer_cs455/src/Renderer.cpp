#include "Renderer.h"

#include <inttypes.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>

#include "Shader.h"

void Renderer::ray_color(std::shared_ptr<Ray> r, Pixel& pixel) const {
    float closestIntersection{std::numeric_limits<float>::infinity()};
    std::shared_ptr<SceneObject> closestObject{};
    
    for (const auto& object : scene.getObjects())
    {
        const float currIntersection = object -> intersect(r);

        if (currIntersection > 0 && currIntersection < closestIntersection)
        {
            closestIntersection = currIntersection;
            closestObject = object;
        }
    }
    
    if (closestObject)
    {
        shader->shadeObject(pixel, closestObject, r, closestIntersection);
    }
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
