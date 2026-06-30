#include <iostream>

#include "Color.h"
#include "Vector3.h"
#include "Ray.h"

bool HitSphere(const Point3& center, double raidus, const Ray& r)
{
	Vec3 oc = center - r.Origin();
	double a = Dot(r.Direction(), r.Direction());
	double b = -2.0 * Dot(r.Direction(), oc);
	double c = Dot(oc, oc) - raidus * raidus;
	double discriminate = b * b - 4 * a * c;
	return (discriminate >= 0);
}

Color RayColor(const Ray& r)
{
	if (HitSphere(Point3(0, 0, -1), 0.5, r))
		return Color(1, 0, 0);

	Vec3 unitDirection=UnitVector(r.Direction());
	double a = 0.5 * (unitDirection.Y() + 1.0);
	return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}

int main()
{
	//Image
	double aspectRatio = 16.0 / 9.0;
	int imageWidth = 400;

	//Set the image height so that it is at least 1 after scaling
	int imageHeight = int(imageWidth / aspectRatio);
	imageHeight = (imageHeight < 1) ? 1 : imageHeight;

	//Camera
	double focalLength = 1.0;
	double viewprotHeight = 2.0;
	double viewprotWidht = viewprotHeight * ((double)imageWidth / imageHeight);
	Point3 camreaCenter = Point3(0, 0, 0);

	//Calculating vectors crossing the horizontal and vertical edges of the viewport
	Vec3 viewportU = Vec3(viewprotWidht, 0, 0);
	Vec3 viewportV = Vec3(0, -viewprotHeight, 0);

	//Calculation of horizontal and vertical delta vectors between pixels
	Vec3 pixelDeltaU = viewportU / imageWidth;
	Vec3 pixelDeltaV = viewportV / imageHeight;

	//Calculating the position of the top-left pixel
	Vec3 viewprotUpperLefet = camreaCenter - Vec3(0, 0, focalLength)
		- viewportU / 2 - viewportV / 2;
	Vec3 pixe100Loc = viewprotUpperLefet + 0.5 * (pixelDeltaU + pixelDeltaV);

	//Render
	std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";
	for (int y = 0; y < imageHeight; ++y)
	{
		std::clog << "\rScanlines remining: " << (imageHeight - 1) << " " << (imageWidth - 1) << std::flush;;
		for (int x = 0; x < imageWidth; ++x)
		{
			Vec3 pixelCenter = pixe100Loc + (x * pixelDeltaU) + (y * pixelDeltaV);
			Vec3 rayDirection = pixelCenter - camreaCenter;
			Ray r(camreaCenter, rayDirection);

			Color pixelColor = RayColor(r);
			WriteColor(std::cout, pixelColor);
		}
	}

	std::clog << "\rDone.				\n";
}