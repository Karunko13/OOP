#pragma once

#include "Shape2D.h"

//klasa Rectangle dziedziczy publicznie z klasy Shape2D
class Rectangle : public Shape2D 
{
	public:
	//konstruktor jednoparametrowy
	Rectangle(std::string nazwa);
	//metoda zwracajaca pole obiektu na ktorym została wywołana
	int area() const;
	private:

};