#pragma once
#include "pch/wavepch.h"

int main()
{
	const int width = 256;
	const int height = 256;
    const int channels = 3;

    int* pixels = new int[width * height * channels];

    int index = 0;
    for (int j = height - 1; j >= 0; --j)
    {
        for (int i = 0; i < width; ++i)
        {
            auto r = double(i) / (width - 1);
            auto g = double(j) / (height - 1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            pixels[index++] = ir;
            pixels[index++] = ig;
            pixels[index++] = ib;
        }
    }

    //stbi_write_png("image.png", width, height, channels, pixels, width * channels);


	return 0;
}