#pragma once
#include "Pixel.h"
#include "Ray.h"
#include "Scene.h"
#include "SceneObject.h"


class Shader
{
    const Scene& scene;

    glm::vec3 calculateDiffuse(std::shared_ptr<SceneObject> object, glm::vec3 normal) const;
    glm::vec3 calculateSpecular(std::shared_ptr<SceneObject> object, glm::vec3 normal, std::shared_ptr<Ray> r) const;
    glm::vec3 calculateAmbient(std::shared_ptr<SceneObject> object) const;
public:
    explicit Shader(const Scene& scene)
        : scene(scene)
    {}

    void shadeObject(Pixel& pixel, std::shared_ptr<SceneObject> object, std::shared_ptr<Ray> r, float intersection) const;
};

