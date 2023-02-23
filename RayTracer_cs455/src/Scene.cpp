#include "Scene.h"

void Scene::addObject(std::shared_ptr<SceneObject> object)
{
    objects.push_back(object);
}

[[nodiscard]] const glm::vec3& Scene::getLookAt() const
{
    return lookAt;
}

[[nodiscard]] const glm::vec3& Scene::getLookFrom() const
{
    return lookFrom;
}

[[nodiscard]] const glm::vec3& Scene::getLookUp() const
{
    return lookUp;
}

[[nodiscard]] int Scene::getFov() const
{
    return fov;
}

[[nodiscard]] const glm::vec3& Scene::getLightDir() const
{
    return lightDir;
}

[[nodiscard]] const glm::vec3& Scene::getLightColor() const
{
    return lightColor;
}

[[nodiscard]] const glm::vec3& Scene::getAmbientLightColor() const
{
    return ambientLightColor;
}

[[nodiscard]] const glm::vec3& Scene::getBgColor() const
{
    return bgColor;
}

[[nodiscard]] const std::vector<std::shared_ptr<SceneObject>>& Scene::getObjects() const
{
    return objects;
}

[[nodiscard]] const Camera& Scene::getCamera() const
{
    return camera;
}