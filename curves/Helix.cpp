#include "Helix.h"

Point3D Helix::get3DPoint(double t)
{
	return { coord.x + radius * tolerate(cos(t)), coord.y + radius * tolerate(sin(t)) , coord.z + step * t};
}

Point3D Helix::getFirstD(double t)
{
	return { radius * (-tolerate(sin(t))), radius * tolerate(cos(t)) , step };
}

Helix::Helix(Point3D coord, double R, double Step) : Figure({ coord.x, coord.y, 0.0 }, "Helix"), radius(R > 0 ? R : 1), step(Step)
{
}

double Helix::getRadius()
{
	return radius;
}