#pragma once
#define _USE_MATH_DEFINES

#include <cmath>
#include <cfloat>
#include <string>

#if defined(USER_DLL_MAKE_DLL)
#  define EXPORT __declspec(dllexport)
#elif defined(USER_DLL_COMPILE_PROGRAM)
#  define EXPORT __declspec(dllimport)
#else
#  define EXPORT 
#endif

struct EXPORT Point3D
{
	double	x,
		y,
		z;

	Point3D(double, double, double);
	Point3D(int, int, int);
};

class EXPORT Figure
{
	private:
		static double tolerateValue ;
		std::string figureName;
	protected:
		Point3D coord;

		Figure(Point3D, std::string);
		virtual ~Figure() = 0;

		double tolerate(double);
	public:
		virtual Point3D	get3DPoint(double)	= 0;
		virtual Point3D	getFirstD(double)	= 0;
		virtual	double	getRadius()		= 0;
		std::string getName();
};