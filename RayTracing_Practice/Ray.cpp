#include "Ray.h"

Ray::Ray()
	:mOrig(), mDirection()
{
}

Ray::Ray(const Point3& origin, const Vector3& direction)
	: mOrig(origin), mDirection(direction)
{
}

const Point3& Ray::Origin() const
{
	return mOrig;
}

const Vec3& Ray::Direction() const
{
	return mDirection;
}

Point3 Ray::At(double t) const
{
	return mOrig + t * mDirection;
}