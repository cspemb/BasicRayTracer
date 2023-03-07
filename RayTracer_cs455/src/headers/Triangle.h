#pragma once
#include "SceneObject.h"

struct Triangle : SceneObject
{
    const glm::vec3 vertices[3];
    
    Triangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3, float coef_diffuse, float coef_specular,
        float coef_ambient, const glm::vec3& diffuse_color, const glm::vec3& specular_color, float glossiness)
        : SceneObject(coef_diffuse, coef_specular, coef_ambient, diffuse_color, specular_color, glossiness),
            vertices(vertex1, vertex2, vertex3)
    {}

    float intersect(std::shared_ptr<Ray> r) override;
    glm::vec3 getNormal(glm::vec3 point) override;
};
