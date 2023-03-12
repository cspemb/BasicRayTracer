#include "Shader.h"

#include "LambertianMaterial.h"

static uint8_t fColorTo255(float fColor)
{
    if (fColor > 1.0f)
    {
        fColor = 1.0f;
    }
    
    return static_cast<uint8_t>(fColor * 255);
}

void Shader::shadeObject(Pixel& pixel, std::shared_ptr<SceneObject> object, std::shared_ptr<Ray> r, float intersection, bool isInShadow, const float reflectance) const
{
    const glm::vec3 objectNormal = object->getNormal(r->at(intersection));
    
    const glm::vec3 totalColor = reflectance * clamp(object->material->getColor(scene, objectNormal, r, isInShadow), 0.0f, 1.0f);
    
    pixel.r = fColorTo255(totalColor.x + (static_cast<float>(pixel.r)/255.0f));
    pixel.g = fColorTo255(totalColor.y + (static_cast<float>(pixel.g)/255.0f));
    pixel.b = fColorTo255(totalColor.z + (static_cast<float>(pixel.b)/255.0f));
}

void Shader::shadeMiss(Pixel& pixel, float reflectance, const glm::vec3 bgColor)
{
    const glm::vec3 color = reflectance * clamp( bgColor, 0.0f, 1.0f);
    pixel.r = fColorTo255(color.x + (static_cast<float>(pixel.r)/255.0f));
    pixel.g = fColorTo255(color.y + (static_cast<float>(pixel.g)/255.0f));
    pixel.b = fColorTo255(color.z + (static_cast<float>(pixel.b)/255.0f));
}
