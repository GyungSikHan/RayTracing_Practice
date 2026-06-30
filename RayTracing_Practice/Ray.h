#pragma once
#include "Vector3.h"

class Ray
{
public:
	Ray();
	Ray(const Point3& origin, const Vector3& direction);
	const Point3& Origin()const;
	const Vec3& Direction()const;
	Point3 At(double t)const;

private:
	Point3 mOrig;
	Vec3 mDirection;
};


