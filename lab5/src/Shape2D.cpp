#include "Shape2D.h"
#include <iostream>

Shape2D::Shape2D(std::string nazwa): _nazwa(nazwa)
{
	std::cout<<"Jestem nowa figura "<<_nazwa<<std::endl;
}
Shape2D& Shape2D::addVertex(Vertex ver)
{
	return *this +=ver;
}

Shape2D& Shape2D::operator +=(Vertex ver)
{
	tabVer.push_back(ver);
	return *this;
}

std::string Shape2D::name() const
{
	return _nazwa;
}

int Shape2D::operator==(const Shape2D& s2) const
{//tu trzeba naprawic

		if(tabVer.size() != s2.tabVer.size()) 
		{
				return 0;
		}		


		return 1;
	
}

std::ostream& operator<<(std::ostream& s,const Shape2D& shape)
{
	s<<"Figura "<<shape.name()<<":\n";
	//tutaj dopisac petle
	return s;
}