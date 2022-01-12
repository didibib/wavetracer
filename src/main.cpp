#pragma once
#include "pch/wavepch.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

const int width = 256;
const int height = 256;
const int channels = 3;

using namespace Wave;

byte pixels[width * height * channels];

int main()
{
    Log::Init();

    int index = 0;
    for (int j = height - 1; j >= 0; --j)
    {
        for (int i = 0; i < width; ++i)
        {
            auto r = double(i) / (width - 1);
            auto g = double(j) / (height - 1);
            auto b = 0.25;

            byte ir = static_cast<byte>(255.999 * r);
            byte ig = static_cast<byte>(255.999 * g);
            byte ib = static_cast<byte>(255.999 * b);

            pixels[index++] = ir;
            pixels[index++] = ig;
            pixels[index++] = ib;
        }
    }

    stbi_write_png("image.png", width, height, channels, pixels, 0);

    Log::Shutdown();
	return 0;
}