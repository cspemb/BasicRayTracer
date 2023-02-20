#include "ImageOutput.h"
#include <fstream>

void writePpmImage(const Image& image, std::ostream& out)
{
    // output ppm header
    out << "P3\n" << image.getWidth() << ' ' << image.getHeight() << "\n255\n";

    // output pixels

    auto to255{[](float color)
    {
        return static_cast<int>(color * 255);
    }};

    for (auto y{0}; y < image.getHeight(); y++ )
    {
        for (auto x{0}; x < image.getWidth(); x++)
        {
            const glm::vec3& currColor = image.at(x, y);

            out << to255(currColor[0]) << ' ' << to255(currColor[1]) << ' ' << to255(currColor[2]) << '\n';
        }
    }
}

void outputPpmFile(const Image& image, std::string_view fileName)
{
    std::ofstream out;

    out.open( "scenes/" + std::string(fileName) + ".ppm", std::ofstream::trunc);

    writePpmImage(image, out);

    out.close();
}