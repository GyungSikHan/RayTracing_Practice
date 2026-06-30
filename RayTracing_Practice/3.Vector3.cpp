#include <iostream>
#include "Vector3.h"
#include "Color.h"

int main()
{
	int ImageWidth = 256;
	int ImageHeight = 256;

	//render
	std::cout << "P3\n" << ImageWidth <<" "<< ImageHeight << "\n255\n";
	for (int y = 0; y < ImageHeight; ++y)
	{
		std::clog << "\rScanlines remaining: " << (ImageHeight - y) << " " << std::flush;
		for (int x = 0; x < ImageWidth; ++x)
		{
			Vec3 pixelColor = Color(double(y) / (ImageWidth - 1), double(x) / (ImageHeight - 1), 0);
			WriteColor(std::cout, pixelColor);
		}
	}
	std::clog << "\rDone.			\n";
}