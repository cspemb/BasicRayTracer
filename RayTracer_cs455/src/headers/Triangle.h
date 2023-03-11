#pragma once
#include "SceneObject.h"

struct Triangle : SceneObject
{
    const glm::vec3 vertices[3];
    
    Triangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3, Material triangleMaterial)
        : SceneObject(triangleMaterial),
            vertices{vertex1, vertex2, vertex3}
    {}

    float intersect(std::shared_ptr<Ray> r) override;
    glm::vec3 getNormal(glm::vec3 point) override;
};
