#include "Primitive.h"
#include <iostream>

Primitive::Primitive(double index): _index(index) {};

void Primitive::PrintWithValue() const
{
	printThis();
	std::cout<<" ="<<Getter()<<std::endl;
}

double Primitive::Getter() const
{
	return _index;
}

void Primitive::printThis() const
{
	std::cout<<_index;
}
void Primitive::Set(double index)
{
	_index=index;
}