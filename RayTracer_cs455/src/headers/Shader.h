#pragma once
#include "Pixel.h"
#include "Ray.h"
#include "Scene.h"
#include "SceneObject.h"


class Shader
{
    const Scene& scene;
public:
    explicit Shader(const Scene& scene)
        : scene(scene)
    {}
    
    void shadeObject(Pixel& pixel, std::shared_ptr<SceneObject> object, std::shared_ptr<Ray> r, float intersection) const;
};

