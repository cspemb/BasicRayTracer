#pragma once
#include "SceneObject.h"

class Triangle : public SceneObject
{
    glm::vec3 getNormal();
    bool isPointInside(glm::vec3 point);

public: 
    const glm::vec3 vertices[3];
    
    Triangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3, std::shared_ptr<Material> triangleMaterial)
        : SceneObject(triangleMaterial),
            vertices{vertex1, vertex2, vertex3}
    {}

    float intersect(std::shared_ptr<Ray> r) override;
    glm::vec3 getNormal(glm::vec3 point) override;
};
