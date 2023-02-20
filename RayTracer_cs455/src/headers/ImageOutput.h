#pragma once
#include <string_view>

#include "Image.h"

void outputPpmFile(const Image& image, std::string_view fileName);
