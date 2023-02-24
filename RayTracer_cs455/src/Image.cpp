#include "Image.h"


[[nodiscard]] int Image::getWidth() const
{
    return this->width;
}

[[nodiscard]] int Image::getHeight() const
{
    return this->height;
}

Pixel& Image::at(int x, int y)
{
    // the buffer is 1D, so this maps to 2D
    return this->buffer.at(x + (y * this->width));
}