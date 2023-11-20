#include "Circle.h"

Point3D Circle::get3DPoint(double t)
{
	return {coord.x + radius* tolerate(cos(t)), coord.y + radius * tolerate(sin(t)) , 0.0};
}

Point3D Circle::getFirstD(double t)
{
	return { radius * (-tolerate(sin(t))), radius * tolerate(cos(t)) , 0.0 };
}

Circle::Circle(Point3D coord, double R) : Figure({coord.x, coord.y, 0.0}, "Circle"), radius(R > 0 ? R : 1)
{
}

double Circle::getRadius()
{
	return radius;
}