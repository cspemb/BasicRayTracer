#include "Scene.h"

void Scene::addObject(const SceneObject& object)
{
    this->objects.push_back(object);
}

[[nodiscard]] const glm::vec3& Scene::getLookAt() const
{
    return this->lookAt;
}

[[nodiscard]] const glm::vec3& Scene::getLookFrom() const
{
    return this->lookFrom;
}

[[nodiscard]] const glm::vec3& Scene::getLookUp() const
{
    return this->lookUp;
}

[[nodiscard]] int Scene::getFov() const
{
    return this->fov;
}

[[nodiscard]] const glm::vec3& Scene::getLightDir() const
{
    return this->lightDir;
}

[[nodiscard]] const glm::vec3& Scene::getLightColor() const
{
    return this->lightColor;
}

[[nodiscard]] const glm::vec3& Scene::getAmbientLightColor() const
{
    return this->ambientLightColor;
}

[[nodiscard]] const glm::vec3& Scene::getBgColor() const
{
    return this->bgColor;
}

[[nodiscard]] const std::vector<SceneObject>& Scene::getObjects() const
{
    return this->objects;
}

[[nodiscard]] const Camera& Scene::getCamera() const
{
    return this->camera;
}