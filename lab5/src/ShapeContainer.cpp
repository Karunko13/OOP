#include "ShapeContainer.h"

void ShapeContainer::operator +=(Shape2D* shape)
{
	shapes.push_back(shape);
}

std::ostream& operator<<(std::ostream& s,const ShapeContainer& shapeCont)
{	//tu dokonczyc wypisanie
	return s;
}