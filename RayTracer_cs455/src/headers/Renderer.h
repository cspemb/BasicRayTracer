#pragma once
#include "Image.h"
#include "Scene.h"
#include <memory>

class Renderer
{
    static constexpr auto aspectRatio {16.0 / 16.0};
    static constexpr int imWidth {256};
    static constexpr int imHeight {static_cast<int>(imWidth / aspectRatio)};
    
    
    const Scene& scene;
    std::shared_ptr<Image> image;

    void processPixel(int x, int y) const;
    void ray_color(std::shared_ptr<Ray> r, Pixel& pixel) const;
public:
    Renderer(const Scene& scene)
        : scene(scene)
    {
        image = std::make_shared<Image>(imWidth, imHeight, scene.getBgColor());
    }

    std::shared_ptr<Image> render();
};
