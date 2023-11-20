#pragma once

#include "Figure.h"


class EXPORT Ellipse : public Figure
{
private:
	double	radiusX,
		radiusY;

public:
	Ellipse(Point3D, double, double);
	~Ellipse() = default;

	Point3D get3DPoint(double);
	Point3D	getFirstD(double);
	double getRadius();
};