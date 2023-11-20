#include "Figure.h"

double Figure::tolerate(double value)
{
	return abs(value) <= tolerateValue ? 0 : value;
}

Figure::Figure(Point3D p, std::string name) : figureName(name) , coord(p)
{
}

std::string Figure::getName()
{
	return figureName;
}

Figure::~Figure()
{
}

double Figure::tolerateValue = DBL_EPSILON;

Point3D::Point3D(int xx, int yy, int zz) : x(xx) , y(yy), z(zz)
{}

Point3D::Point3D(double xx, double yy, double zz) : x(xx), y(yy), z(zz)
{}