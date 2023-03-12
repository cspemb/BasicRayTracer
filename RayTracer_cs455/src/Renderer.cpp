#include "Renderer.h"

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

#include "Shader.h"

bool Renderer::isInShadow(glm::vec3 point) const
{
    glm::vec3 toLight = scene.getLightDir();

    const std::shared_ptr<Ray> shadowRay = std::make_shared<Ray>(point, toLight, true);
        
    for (const auto& object : scene.getObjects())
    {
        const float intersection = object -> intersect(shadowRay);

        if (intersection > 0)
        {
            return true;
        }
    }

    return false;
}

void Renderer::ray_color(std::shared_ptr<Ray> r, Pixel& pixel, const float reflectance, const int reflectionsLeft) const {
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
        // spawn reflection rays and get color sum
        if (reflectionsLeft)
        {
            ray_color(closestObject->getReflectionRay(r, closestIntersection), pixel,
                closestObject->material->reflectance * reflectance, reflectionsLeft - 1);
        }
        
        shader->shadeObject(pixel, closestObject, r, closestIntersection, isInShadow(r->at(closestIntersection)), reflectance);
    }
    else // missed
    {
        shader->shadeMiss(pixel, reflectance, scene.getBgColor());
    }
}

void Renderer::processPixel(int x,  int y) const 
{
    auto u = static_cast<float>(x) / imWidth;
    auto v = static_cast<float>(y) / imHeight;
    const std::shared_ptr<Ray> r = scene.getCamera().getRay(u, v);
    ray_color(r, image->at(x, y), 1.0f,  MAX_REFLECTIONS);
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
