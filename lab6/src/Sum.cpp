#include "Sum.h"
#include <iostream>

void Sum::printThis() const
{
	std::cout<<"(";
	_val1.printThis();
	std::cout<<" + ";
	_val2.printThis();
	std::cout<<")";
	
}