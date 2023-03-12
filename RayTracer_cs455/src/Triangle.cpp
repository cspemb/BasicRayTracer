#include "Triangle.h"

bool Triangle::isPointInside(glm::vec3 point)
{
    // For each edge
    for (int i = 0; i < 3; i++)
    {
        const glm::vec3 edgeBase = vertices[i];
        const glm::vec3 edgeHead = i == 2 ? vertices[0] : vertices[i + 1];

        const glm::vec3 edge = edgeHead - edgeBase;
        const glm::vec3 query = cross(edge, point - edgeBase);

        const float test = dot(query, getNormal());

        const float EPS = 0.001f;
        if (test < EPS)
        {   
            return false;
        }
    }

    return true;
}

float Triangle::intersect(std::shared_ptr<Ray> r)
{
    const glm::vec3 normal = getNormal(); // contains a, b, c for plane equation
    const float d = -dot(normal, vertices[0]);

    const float denominator = dot(normal, r->getDirection());
    const float EPS = 0.001f;
    if (fabs(denominator) < EPS) // no intersection (parallel)
    {
      return -1.0f;  
    }
    
    if (denominator > 0.0f) // cull plane (pointing away from camera)
    {
        return -1.0f;
    }
    
    const float t = -(dot(normal, r->getOrigin()) + d) / denominator;

    if (t < 0.0f || fabs(t) < EPS) // plane is behind the ray, no intersection
    {
        return -1.0f;
    }

    const glm::vec3 intersectionCoord = r->at(t);

    if (!isPointInside(intersectionCoord))
    {
        return -1.0f;
    }
    
    return t;
}

glm::vec3 Triangle::getNormal([[maybe_unused]]glm::vec3 point)
{
    return getNormal();
}

glm::vec3 Triangle::getNormal()
{
    // assumes counter clockwise ordering
    const glm::vec3 rightEdge = vertices[1] - vertices[0];
    const glm::vec3 leftEdge = vertices[2] - vertices[0];
    
    return normalize(cross(rightEdge, leftEdge));
}
