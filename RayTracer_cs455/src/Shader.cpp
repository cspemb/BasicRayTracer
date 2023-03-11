﻿#include "Shader.h"

#include "LambertianMaterial.h"

static uint8_t fColorTo255(float fColor)
{
    return static_cast<uint8_t>(fColor * 255);
}

void Shader::shadeObject(Pixel& pixel, std::shared_ptr<SceneObject> object, std::shared_ptr<Ray> r, float intersection) const
{
    const glm::vec3 objectNormal = object->getNormal(r->at(intersection));
    
    const glm::vec3 totalColor = object->material->getColor(scene, objectNormal, r);
    
    pixel.r = fColorTo255(totalColor.x);
    pixel.g = fColorTo255(totalColor.y);
    pixel.b = fColorTo255(totalColor.z);
}
