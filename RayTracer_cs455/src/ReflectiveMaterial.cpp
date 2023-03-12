#include "ReflectiveMaterial.h"

glm::vec3 ReflectiveMaterial::getReflectedDirection(const std::shared_ptr<Ray>& incidentRay, glm::vec3 normal)
{
    return normalize(incidentRay->getDirection() - 2 * dot(incidentRay->getDirection(), normal) * normal);
}
