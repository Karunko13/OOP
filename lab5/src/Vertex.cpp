#include "Vertex.h"

Vertex::Vertex(int x,int y): ws1(x),ws2(y)
{}

int Vertex::showWS1() const
{
	return ws1;
}

int Vertex::showWS2() const
{
	return ws2;
}


std::ostream& operator<<(std::ostream & s,const Vertex ver)
{
	return s<<" ["<<ver.showWS1()<<", "<<ver.showWS2()<<"]";
}