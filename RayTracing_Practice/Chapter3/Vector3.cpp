#define VEC_H
#include "Vector3.h"

Vector3::Vector3()
	:E{}
{
	
}

Vector3::Vector3(double e0, double e1, double e2)
	:E{e0,e1,e2}
{
}

double Vector3::X() const
{
	return E[0];
}

double Vector3::Y() const
{
	return E[1];
}

double Vector3::Z() const
{
	return E[2];
}

Vector3& Vector3::operator+=(const Vector3& v)
{
	E[0] += v.E[0];
	E[1] += v.E[1];
	E[2] += v.E[2];
	return *this;
}

Vector3& Vector3::operator*=(double t)
{
	E[0] *= t;
	E[1] *= t;
	E[2] *= t;
	return *this;
}

Vector3& Vector3::operator/=(double t)
{
	return *this *= 1 / t;
}

double Vector3::Length() const
{
	return std::sqrt(LengthSquared());
}

double Vector3::LengthSquared() const
{
	return E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
}
