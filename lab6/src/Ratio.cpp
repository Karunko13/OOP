#include "Ratio.h"
#include <iostream>

void Ratio::printThis() const
{
	std::cout<<"(";
	_val1.printThis();
	std::cout<<"/";
	_val2.printThis();
	std::cout<<")";
	
	
}