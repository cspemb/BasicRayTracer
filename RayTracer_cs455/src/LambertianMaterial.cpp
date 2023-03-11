#include "LambertianMaterial.h"

glm::vec3 LambertianMaterial::calculateDiffuse(const Scene& scene, glm::vec3 normal) const
{
    const bool isLit = dot(scene.getLightDir(), normal) >= 0;
    return isLit ? diffuseColor * coefDiffuse * scene.getLightColor() * (dot(normal, scene.getLightDir())) : glm::vec3{0,0,0};
}

glm::vec3 LambertianMaterial::calculateSpecular(const Scene& scene, glm::vec3 normal, std::shared_ptr<Ray> r) const
{
    const bool isLit = dot(scene.getLightDir(), normal) >= 0;
    const glm::vec3 reflected = glm::normalize(2.0f * dot(scene.getLightDir(), normal) * normal - scene.getLightDir());
    return isLit ? specularColor * coefSpecular * scene.getLightColor() * pow((dot(reflected, r->getDirection())), glossiness) : glm::vec3{0, 0, 0};
}

glm::vec3 LambertianMaterial::calculateAmbient(const Scene& scene) const
{
    return diffuseColor * coefAmbient * scene.getAmbientLightColor();
}

glm::vec3 LambertianMaterial::getColor(const Scene& scene, glm::vec3 normal, std::shared_ptr<Ray> r)
{
    return calculateDiffuse(scene, normal) + calculateSpecular(scene, normal, r) + calculateAmbient(scene);
}
