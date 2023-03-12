#include "SceneObject.h"

std::shared_ptr<Ray> SceneObject::getReflectionRay(std::shared_ptr<Ray> incidentRay, float intersection)
{
    glm::vec3 reflectedDir = material->getReflectedDirection(incidentRay, getNormal(incidentRay->at(intersection)));
    
    return std::make_shared<Ray>(incidentRay->at(intersection), reflectedDir, true);
}
