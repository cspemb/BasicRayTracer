#pragma once
#include <memory>
#include <glm/vec3.hpp>

#include "SceneObject.h"
#include <vector>

#include "Camera.h"

class Scene
{
    //Camera parameters
    const glm::vec3 lookAt{};
    const glm::vec3 lookFrom{};
    const glm::vec3 lookUp{};
    const int fov{};

    //Lighting parameters
    const glm::vec3 lightDir{};
    const glm::vec3 lightColor{};
    const glm::vec3 ambientLightColor{};
    
    const glm::vec3 bgColor{};

    Camera camera;
    std::vector<std::shared_ptr<SceneObject>> objects{};
    
public:
    Scene(const glm::vec3& look_at, const glm::vec3& look_from, const glm::vec3& look_up, const int fov,
        const glm::vec3& light_dir, const glm::vec3& light_color, const glm::vec3& ambient_light_color,
        const glm::vec3& bg_color)
        : lookAt(look_at),
          lookFrom(look_from),
          lookUp(look_up),
          fov(fov),
          lightDir(normalize(light_dir)),
          lightColor(light_color),
          ambientLightColor(ambient_light_color),
          bgColor(bg_color)
    {
        camera = {lookFrom, lookAt, lookUp, fov};
    }

    void addObject(std::shared_ptr<SceneObject> object);

    [[nodiscard]] const glm::vec3& getLookAt() const;
    [[nodiscard]] const glm::vec3& getLookFrom() const;
    [[nodiscard]] const glm::vec3& getLookUp() const;
    [[nodiscard]] int getFov() const;
    [[nodiscard]] const glm::vec3& getLightDir() const;
    [[nodiscard]] const glm::vec3& getLightColor() const;
    [[nodiscard]] const glm::vec3& getAmbientLightColor() const;
    [[nodiscard]] const glm::vec3& getBgColor() const;
    [[nodiscard]] const std::vector<std::shared_ptr<SceneObject>>& getObjects() const;
    [[nodiscard]] const Camera& getCamera() const;
};
