#pragma once
#include <cstdint>
#include <glm/vec3.hpp>


struct Pixel
{
    uint8_t r{};
    uint8_t g{};
    uint8_t b{};
    const uint8_t a{255};

    Pixel(uint8_t r, uint8_t g, uint8_t b)
        : r(r),
          g(g),
          b(b)
    {}

    Pixel(const glm::vec3& vec)
    {
        auto to255{[](float color)
        {
            return static_cast<uint8_t>(color * static_cast<uint8_t>(255));
        }};
        
        r = {to255(vec.x)};
        g = {to255(vec.y)};
        b = {to255(vec.z)};
    }
};
