#pragma once
#include "LambertianMaterial.h"
#include "Pixel.h"
#include "Ray.h"
#include "Scene.h"
#include "SceneObject.h"


class Shader
{
    const Scene& scene;

    glm::vec3 calculateDiffuse(LambertianMaterial material, glm::vec3 normal) const;
    glm::vec3 calculateSpecular(LambertianMaterial material, glm::vec3 normal, std::shared_ptr<Ray> r) const;
    glm::vec3 calculateAmbient(LambertianMaterial material) const;

    glm::vec3 calcColor(Material material, glm::vec3 normal, std::shared_ptr<Ray> r) const;
    glm::vec3 calcColor(LambertianMaterial material, glm::vec3 normal, std::shared_ptr<Ray> r) const;
public:
    explicit Shader(const Scene& scene)
        : scene(scene)
    {}
    
    void shadeObject(Pixel& pixel, std::shared_ptr<SceneObject> object, std::shared_ptr<Ray> r, float intersection) const;
};

