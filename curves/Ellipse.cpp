#include "Ellipse.h"

Point3D Ellipse::get3DPoint(double t)
{
	return { coord.x + radiusX * tolerate(cos(t)), coord.y + radiusY * tolerate(sin(t)) , 0.0 };
}

Point3D Ellipse::getFirstD(double t)
{
	return { radiusX * (-tolerate(sin(t))), radiusY * tolerate(cos(t)) , 0.0 };
}

Ellipse::Ellipse(Point3D coord, double Rx, double Ry) : Figure({ coord.x, coord.y, 0.0 }, "Ellipse"), radiusX(Rx > 0 ? Rx : 0), radiusY(Ry > 0 ? Ry : 0)
{
}

double Ellipse::getRadius()
{
	return (radiusX + radiusY) / 2;
}