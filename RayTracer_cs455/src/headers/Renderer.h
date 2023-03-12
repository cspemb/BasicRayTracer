#pragma once
#include "Image.h"
#include "Scene.h"
#include <memory>

#include "Shader.h"

class Renderer
{
    static constexpr auto aspectRatio {16.0 / 16.0};
    static constexpr int imWidth {700};
    static constexpr int imHeight {static_cast<int>(imWidth / aspectRatio)};
    static constexpr int MAX_REFLECTIONS = 10;
    
    const Scene& scene;
    std::shared_ptr<Image> image;
    std::unique_ptr<Shader> shader;

    void processPixel(int x, int y) const;
    void ray_color(std::shared_ptr<Ray> r, Pixel& pixel, float reflectance, int reflectionsLeft) const;
    bool isInShadow(glm::vec3 point) const;
public:
    Renderer(const Scene& scene)
        : scene(scene)
    {
        image = std::make_shared<Image>(imWidth, imHeight);
        shader = std::make_unique<Shader>(scene);
    }

    std::shared_ptr<Image> render();
};
