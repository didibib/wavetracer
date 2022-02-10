#include "pch/wavepch.h"

namespace Wave
{
	void Camera::Init(float viewportHeight, float aspectRatio, float focalLength, Vec3 origin)
	{
		mViewportHeight = viewportHeight;
		mViewportWidth = mViewportHeight * aspectRatio;
		mFocalLength = focalLength;
		mOrigin = origin;
		mLowerLeftCorner = mOrigin - mHorizontal * 0.5f - mVertical * 0.5f - Vec3(0, 0, mFocalLength);
		
	}
}