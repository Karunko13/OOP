#pragma once
#include <iostream>

//Primitive jest klasą bazową 
class Primitive{

public:
//konstuktor jednoargumentyowy,wartos domyślna to 0
Primitive(double index=0);
//metoda wypisujaca na ekran
virtual void PrintWithValue() const;
//metoda wirtualna zwracajaca zmienna _index
virtual double Getter() const;
//metoda wypisujaca na ekran
virtual void printThis() const;
//metoda ustawiajaca zadana wartosc zmiennej _index
void Set(double index);

private:

double _index;
};