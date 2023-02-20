#pragma once
#include "Image.h"
#include "Scene.h"
#include <memory>

class Renderer
{
    static constexpr int imHeight {256};
    static constexpr int imWidth {256};
    
    const Scene& scene;
    std::shared_ptr<Image> image;

    void processPixel(int x, int y);
public:
    Renderer(const Scene& scene)
        : scene(scene)
    {
        image = std::make_shared<Image>(imWidth, imHeight, scene.getBgColor());
    }

    std::shared_ptr<Image> render();
};
