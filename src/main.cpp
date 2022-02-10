#pragma once

#include "pch/wavepch.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace Wave;

// Image
const int mChannels = 3;
const float mAspectRatio = 16.f / 9.f;
const int mImageWidth = 400;
const int mImageHeight = static_cast<int>(mImageWidth / mAspectRatio);

byte* mPixels = new byte[mImageWidth * mImageHeight * mChannels];

// Camera
const float mViewportHeight = 2.f;
const float mViewportWidth = mViewportHeight * mAspectRatio;
float mFocalLength = 1.f;

Vec3 mOrigin(0, 0, 0);
auto mHorizontal = Vec3(mViewportWidth, 0, 0);
auto mVertical = Vec3(0, mViewportHeight, 0);
auto mLowerLeftCorner = mOrigin - mHorizontal * 0.5f - mVertical * 0.5f - Vec3(0, 0, mFocalLength);

void Init()
{
    Log::Init();
}

void Shutdown()
{
    Log::Shutdown();
}

int main()
{
    Init();

    int index = 0;
    for (int j = mImageHeight - 1; j >= 0; --j)
    {
        for (int i = 0; i < mImageWidth; ++i)
        {
            auto u = float(i) / (mImageWidth - 1);
            auto v = float(j) / (mImageHeight - 1);

            Ray r(mOrigin, mLowerLeftCorner + u * mHorizontal + v * mVertical - mOrigin);
            Color color = r.GetColor();

            mPixels[index++] = static_cast<int>(255.999 * color.r);
            mPixels[index++] = static_cast<int>(255.999 * color.g);
            mPixels[index++] = static_cast<int>(255.999 * color.b);
        }
    }

    stbi_write_png("image.png", mImageWidth, mImageHeight, mChannels, mPixels, 0);

    Shutdown();
	return 0;
}