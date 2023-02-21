#include "ImageOutput.h"
#include <fstream>

void writePpmImage(Image& image, std::ostream& out)
{
    // output ppm header
    out << "P3\n" << image.getWidth() << ' ' << image.getHeight() << "\n255\n";

    // output pixels

    for (auto y{image.getHeight() - 1}; y >= 0; y-- )
    {
        for (auto x{0}; x < image.getWidth(); x++)
        {
            Pixel& currColor = image.at(x, y);

            out << +currColor.r << ' ' << +currColor.g << ' ' << +currColor.b << '\n';
        }
    }
}

void outputPpmFile(Image& image, std::string_view fileName)
{
    std::ofstream out;

    out.open( "scenes/" + std::string(fileName) + ".ppm", std::ofstream::trunc);

    writePpmImage(image, out);

    out.close();
}