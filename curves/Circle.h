#pragma once

#include "Figure.h"

class EXPORT Circle : public Figure
{
	private:
		double radius;

	public:
		Circle(Point3D, double);
		~Circle() = default;

		Point3D get3DPoint(double);
		Point3D	getFirstD(double);
		double getRadius();
};