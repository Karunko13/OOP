#pragma once

#include "Vertex.h"
#include <string>
#include <vector>

class Shape2D{

public:
//konstruktor jednoparametrowy
Shape2D(std::string nazwa);
//metoda która dodaje wierzcholek "ver" do zbioru
Shape2D& addVertex(Vertex ver);
////metoda która dodaje wierzcholek "ver" do zbioru
Shape2D& operator +=(Vertex ver);
//metoda zwracajaca parametr _nazwa
std::string name() const;
//operator porownujacy czy dwie figury sa takie same
int operator==(const Shape2D& s2) const;

private:
//nazwa
std::string _nazwa;
//wektor wierzcholkow
std::vector<Vertex> tabVer;

};

std::ostream& operator<<(std::ostream& s,const Shape2D& shape);