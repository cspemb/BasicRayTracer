#include "Image.h"
#include "World.h"
#include "ImageOutput.h"
#include "Renderer.h"

int main()
{
    for (const auto& [sceneName, scene] : getScenes())
    {
        Renderer renderer {scene};

        const std::shared_ptr<Image> image = renderer.render();

        outputPpmFile(*image, sceneName);
    }
    
    return 0;
}
