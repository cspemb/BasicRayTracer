#include "Image.h"
#include "World.h"
#include "ImageOutput.h"

int main()
{
    Scene scene1 {getScene1()};

    constexpr int imHeight = 256;
    constexpr int imWidth = 256;

    //Render
    Image image1 {imWidth, imHeight, scene1.getBgColor()};

    outputPpmFile(image1, "scene1");
    
    return 0;
}
