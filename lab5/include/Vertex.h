#pragma once

#include <iostream>

class Vertex{
	public:

	Vertex(int x,int y);
	//metoda zwracaja ws1
	int showWS1() const;
	//metoda zwracaja ws2
	int showWS2() const;

	private:
	int ws1;//wspolrzedna reprezentujaca "x"
	int ws2;//wspolrzedna reprezentujaca "y"
};
//operator << wypisujacy na strumien s wierzcholek ver 
std::ostream& operator<<(std::ostream& s,const Vertex ver);