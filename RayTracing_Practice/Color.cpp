#include "Color.h"

void WriteColor(std::ostream& out, const Color& pixelColor)
{
	double r = pixelColor.X();
	double g = pixelColor.Y();
	double b = pixelColor.Z();

	int rByte = int(255.999 * r);
	int gByte = int(255.999 * g);
	int bByte = int(255.999 * b);

	out << rByte << " " << gByte << " " << bByte << std::endl;
}
