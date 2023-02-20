#include "Image.h"
#include "World.h"
#include "ImageOutput.h"

int main()
{
    constexpr int imHeight {256};
    constexpr int imWidth {256};
    
    for (const auto& [sceneName, scene] : getScenes())
    {
        //Render
        const Image image {imWidth, imHeight, scene.getBgColor()};

        outputPpmFile(image, sceneName);
    }
    
    return 0;
}
