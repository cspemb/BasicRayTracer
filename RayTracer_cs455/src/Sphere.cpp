#include "Sphere.h"
#include <glm/glm.hpp>

float Sphere::intersect(std::shared_ptr<Ray> r)
{
    glm::vec3 oc = r->getOrigin() - center;
    const auto b = 2.0f * dot(oc, r->getDirection());
    const auto c = dot(oc, oc) - (radius * radius);
    auto discriminant = (b * b) - (4 * c);

    auto quadratic {[b, discriminant](bool isInsideSphere)
    {   
        return isInsideSphere ? (-b + glm::sqrt(discriminant)) / 2.0f : (-b - glm::sqrt(discriminant)) / 2.0f;
    }};

    //Miss
    if (discriminant < 0)
    {
        return -1.0;
    }

    const float EPS = 0.001f;
    return quadratic(fabs(discriminant) < EPS); //If discriminant is 0
}

glm::vec3 Sphere::getNormal(glm::vec3 point)
{
    return normalize(point - center);
}


