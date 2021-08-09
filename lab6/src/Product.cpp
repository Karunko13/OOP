#include "Product.h"
#include <iostream>

void Product::printThis() const
{
	std::cout<<"(";
	_val1.printThis();
	std::cout<<" * ";
	_val2.printThis();
	std::cout<<")";
	
}