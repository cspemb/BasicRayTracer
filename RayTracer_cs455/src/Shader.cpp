#include "Shader.h"

#include "LambertianMaterial.h"

static uint8_t fColorTo255(float fColor)
{
    return static_cast<uint8_t>(fColor * 255);
}

// Using Lambertian diffusion
glm::vec3 Shader::calculateDiffuse(LambertianMaterial material, glm::vec3 normal) const
{
    const bool isLit = dot(scene.getLightDir(), normal) >= 0;
    return isLit ? material.diffuseColor * material.coefDiffuse * scene.getLightColor() * (dot(normal, scene.getLightDir())) : glm::vec3{0,0,0};
}

glm::vec3 Shader::calculateSpecular(LambertianMaterial material, glm::vec3 normal, std::shared_ptr<Ray> r) const
{
    const bool isLit = dot(scene.getLightDir(), normal) >= 0;
    const glm::vec3 reflected = glm::normalize(2.0f * dot(scene.getLightDir(), normal) * normal - scene.getLightDir());
    return isLit ? material.specularColor * material.coefSpecular * scene.getLightColor() * pow((dot(reflected, r->getDirection())), material.glossiness) : glm::vec3{0, 0, 0};
}

glm::vec3 Shader::calculateAmbient(LambertianMaterial material) const
{
    return material.diffuseColor * material.coefAmbient * scene.getAmbientLightColor();
}

void Shader::shadeObject(Pixel& pixel, std::shared_ptr<SceneObject> object, std::shared_ptr<Ray> r, float intersection) const
{
    const glm::vec3 objectNormal = object->getNormal(r->at(intersection));
    
    const glm::vec3 totalColor = calcColor(object->material, objectNormal, r);

    // const glm::vec3 totalColor = diffuseColor;
    pixel.r = fColorTo255(totalColor.x);
    pixel.g = fColorTo255(totalColor.y);
    pixel.b = fColorTo255(totalColor.z);
}

glm::vec3 Shader::calcColor([[maybe_unused]] Material material, [[maybe_unused]]glm::vec3 normal, std::shared_ptr<Ray> r) const
{
    return {};
}

glm::vec3 Shader::calcColor(LambertianMaterial material, glm::vec3 normal, std::shared_ptr<Ray> r) const
{
    const glm::vec3 diffuseColor = calculateDiffuse(material, normal);
    const glm::vec3 specularColor = calculateSpecular(material, normal, r);
    const glm::vec3 ambientColor = calculateAmbient(material);

    return diffuseColor + specularColor + ambientColor;
}
