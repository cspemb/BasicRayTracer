#include "Sphere.h"
#include <glm/glm.hpp>

bool Sphere::intersect(std::shared_ptr<Ray> r)
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
        return false;
    }
    
    // return quadratic(false);
    return true;
    
}