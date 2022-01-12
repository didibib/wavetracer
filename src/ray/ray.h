#pragma once 

namespace Wave
{
	class Ray
	{
	public:
		Ray() = default;
		Ray(const Vec3& origin, const Vec3& direction)
			: mOrigin(origin), mDirection(direction)
		{
		}

		Vec3 Origin() const { return mOrigin; }
		Vec3 Direction() const { return mDirection; }

		Vec3 At(float time)
		{
			return mOrigin + time * mDirection;
		}

	private:
		Vec3 mOrigin;
		Vec3 mDirection;
	};
}