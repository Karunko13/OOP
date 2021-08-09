#pragma once
#include "Shape2D.h"

class ShapeContainer
{
	public:
	void operator +=(Shape2D* shape);

	private:
	//wektor obiektow klasy Shape2D
	std::vector<Shape2D*> shapes;
};
//operator wypisujacy obiekty
std::ostream& operator<<(std::ostream& s,const ShapeContainer& shapeCont);