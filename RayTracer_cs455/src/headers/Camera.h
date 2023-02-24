#pragma once
#include <memory>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>

#include "Ray.h"


class Camera
{
    glm::vec3 position{};
    glm::vec3 horizontal{};
    glm::vec3 vertical{};

    glm::vec3 minPlane{};
    
public:
    Camera() = default; 
    Camera(const glm::vec3& lookFrom, const glm::vec3& lookAt, const glm::vec3& lookUp, int fov)
    {
        const float offset = glm::tan(glm::radians(static_cast<float>(fov) / 2.0f));

        const auto w{normalize(lookFrom - lookAt)};
        const auto u{normalize(cross(lookUp, w))};
        const auto v{cross(w, u)};

        position = lookFrom;
        horizontal = (2.0f * offset) * u;
        vertical = (2.0f * offset) * v;
        minPlane = position - (horizontal / 2.0f) - (vertical / 2.0f) - w;
    }

    std::shared_ptr<Ray> getRay(float i, float j) const;

    [[nodiscard]] const glm::vec3& getPosition() const;

    [[nodiscard]] const glm::vec3& getHorizontal() const;

    [[nodiscard]] const glm::vec3& getVertical() const;

    [[nodiscard]] const glm::vec3& getMinPlane() const;
};
