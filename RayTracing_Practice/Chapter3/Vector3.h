#pragma once

#include <iostream>
#include <cmath>

class Vector3
{
public:
	Vector3();
	Vector3(double e0, double e1, double e2);
	double X() const;
	double Y() const;
	double Z() const;
	Vector3& operator+=(const Vector3& v);
	Vector3& operator*=(double t);
	Vector3& operator/=(double t);
	double Length() const;
	double LengthSquared() const;
public:
	double E[3];
};

typedef Vector3 Vec3;
using Point3 = Vector3;

inline std::ostream& operator<<(std::ostream& out, const Vector3& v)
{
	return out << v.E[0] << " " << v.E[1] << " " << v.E[2] << std::endl;
}

inline Vector3 operator+(const Vector3& u, const Vector3& v)
{
	return Vector3(u.E[0] + v.E[0], u.E[1] + v.E[1], u.E[2] + v.E[2]);
}

inline Vector3 operator-(const Vector3& u, const Vector3& v)
{
	return Vector3(u.E[0] - v.E[0], u.E[1] - v.E[1], u.E[2] - v.E[2]);
}

inline Vector3 operator*(const Vector3& u, const Vector3& v)
{
	return Vector3(u.E[0] * v.E[0], u.E[1] * v.E[1], u.E[2] * v.E[2]);
}

inline Vector3 operator*(const double& t, const Vector3& v)
{
	return Vector3(t * v.E[0], t * v.E[1], t * v.E[2]);
}

inline Vector3 operator*(const Vector3& v, double t)
{
	return t * v;
}

inline Vector3 operator/(const Vector3& v, double t)
{
	return (1 / t) * v;
}

inline double Dot(const Vector3& u, const Vector3& v)
{
	return u.E[0] * v.E[0] + u.E[1] * v.E[1] + u.E[2] * v.E[2];
}

inline Vector3 Cross(const Vector3& u, const Vector3& v)
{
	return Vector3(u.E[1]*v.E[2]-u.E[2]*v.E[1], u.E[2]*v.E[0]-u.E[0]*v.E[2],u.E[0]*v.E[1]-u.E[1]*v.E[0]);
}

inline  Vector3 UnitVector(const Vector3& v)
{
	return v / v.Length();
}