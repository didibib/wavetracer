#include "pch/wavepch.h"
#include "ray.h"

namespace Wave
{
	Color Ray::GetColor()
	{
		Vec3 unitDirection = glm::normalize(mDirection);
		float t = 0.5f * (unitDirection.y + 1.0f);
		return (1.0f - t) * Color(1.0f, 1.0f, 1.0f) + t * Color(0.5f, 0.7f, 1.0f);
	}
}