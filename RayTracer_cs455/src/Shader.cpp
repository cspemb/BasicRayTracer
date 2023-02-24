#include "Shader.h"

static uint8_t fColorTo255(float fColor)
{
    return static_cast<uint8_t>(fColor * 255);
}


// Using Lambertian diffusion
glm::vec3 Shader::calculateDiffuse(std::shared_ptr<SceneObject> object, glm::vec3 normal) const
{
    const bool isLit = dot(scene.getLightDir(), normal) >= 0;
    return isLit ? object->diffuseColor * object->coefDiffuse * scene.getLightColor() * (dot(normal, scene.getLightDir())) : glm::vec3{0,0,0};
}

glm::vec3 Shader::calculateSpecular(std::shared_ptr<SceneObject> object, glm::vec3 normal, std::shared_ptr<Ray> r) const
{
    const bool isLit = dot(scene.getLightDir(), normal) >= 0;
    const glm::vec3 reflected = glm::normalize(2.0f * dot(scene.getLightDir(), normal) * normal - scene.getLightDir());
    return isLit ? object->specularColor * object->coefSpecular * scene.getLightColor() * pow((dot(reflected, r->getDirection())), object->glossiness) : glm::vec3{0, 0, 0};
}

glm::vec3 Shader::calculateAmbient(std::shared_ptr<SceneObject> object) const
{
    return object->diffuseColor * object->coefAmbient * scene.getAmbientLightColor();
}

void Shader::shadeObject(Pixel& pixel, std::shared_ptr<SceneObject> object, std::shared_ptr<Ray> r, float intersection) const
{
    const glm::vec3 objectNormal = object->getNormal(r->at(intersection));

    const glm::vec3 diffuseColor = calculateDiffuse(object, objectNormal);
    const glm::vec3 specularColor = calculateSpecular(object, objectNormal, r);
    const glm::vec3 ambientColor = calculateAmbient(object);

    const glm::vec3 totalColor = diffuseColor + specularColor + ambientColor;

    // const glm::vec3 totalColor = diffuseColor;
    pixel.r = fColorTo255(totalColor.x);
    pixel.g = fColorTo255(totalColor.y);
    pixel.b = fColorTo255(totalColor.z);
}
