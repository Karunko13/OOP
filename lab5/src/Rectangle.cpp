#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(std::string nazwa): Shape2D(nazwa)
{
	std::cout<<"Mowiac scisle, jestem prostokatem."<<std::endl;
}
int Rectangle::area() const
{
	
	return 9;// to naprawic potem
}