#include "curves/Figure.h"
#include "curves/Circle.h"
#include "curves/Helix.h"
#include "curves/Ellipse.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

Figure* getRandomCurve(Point3D p , double Rx , double Ry , double step)
{
	int curve = rand() % 3;

	if (!curve) // Circle
		return new Circle(p , Rx);
	else if (curve == 1) // Helix 
		return new Helix(p, Rx, step);
	else // Ellipse 
		return new Ellipse(p, Rx, Ry);
}

int main(char** argc, int argv)
{
	srand(time(0));

	std::vector<Figure*> figs;
	std::vector<Figure*> circles;
	double quaterOfPI = M_PI / 4;

	for (int i = 0; i < 10; ++i)
	{
		figs.push_back(getRandomCurve(
			{
				rand() % 100 ,
				rand() % 100 ,
				rand() % 100 
			} ,
			rand() % 10,
			rand() % 10,
			rand() % 10
		));
	}


	for (int i = 0; i < figs.size(); ++i)
	{
		Point3D p = figs[i]->get3DPoint(quaterOfPI),
			d = figs[i]->getFirstD(quaterOfPI);
		std::cout << std::setw(8) << std::left << figs[i]->getName() << "> " << "\n\t3D Point: (" << p.x << ", " << p.y << ", " << p.z << std::setw(10) << std::left << ");\n\tFirst derivative(at " << quaterOfPI << ") : (" << d.x << ", " << d.y << ", " << d.z << ")\n";
	}

	for (int i = 0; i < figs.size(); ++i)
	{
		if (figs[i]->getName() == "Circle")
			circles.push_back(figs[i]);
	}

	std::sort(circles.begin(), circles.end(), [](Figure* f1, Figure* f2) -> bool
		{
			return f1->getRadius() < f2->getRadius();
		});

	std::cout << std::setw(60) << std::setfill('-') << "-" << std::setw(0) << std::setfill(' ') << '\n';

	for (int i = 0; i < circles.size(); ++i)
	{
		Point3D p = circles[i]->get3DPoint(quaterOfPI),
			d = circles[i]->getFirstD(quaterOfPI);
		std::cout << std::setw(8) << std::left << circles[i]->getName() << "> " << "\n\t3D Point: (" << p.x << ", " << p.y << ", " << p.z << std::setw(10) << std::left << ");\n\tFirst derivative(at " << quaterOfPI << ") : (" << d.x << ", " << d.y << ", " << d.z << ");\n\tRadius: " << circles[i]->getRadius() << "\n";
	}
	double sumRadius = 0.0;

	std::for_each(circles.begin(), circles.end(), [&sumRadius](Figure* f) -> void {
		sumRadius += f->getRadius();
		});
	std::cout << std::setw(60) << std::setfill('-') << "-" << std::setw(0) << std::setfill(' ') << '\n' << "Sum of radiuses: " << sumRadius << '\n';


	return 0;
}