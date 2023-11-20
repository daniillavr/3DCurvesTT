#pragma once once

#include "Figure.h"

class EXPORT Helix : public Figure
{
private:
	double	radius,
		step;

public:
	Helix(Point3D, double, double);
	~Helix() = default;

	Point3D get3DPoint(double);
	Point3D	getFirstD(double);
	double getRadius();
};