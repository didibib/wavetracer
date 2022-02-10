#pragma once 

namespace Wave
{
	class Camera
	{
	public:
		void Init(float viewportHeight, float aspectRatio, float focalLength, Vec3 origin = { 0.f, 0.f, 0.f });

		float GetVpHeight() { return mViewportHeight; }
		float GetVpWidth() { return mViewportWidth; }
		float GetFocalLength() { return mFocalLength; }

	private:
		float mViewportHeight;
		float mViewportWidth;
		float mFocalLength;

		Vec3 mOrigin;
		Vec3 mLowerLeftCorner;
	};
}