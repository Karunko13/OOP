#pragma once
#include "Primitive.h"
//klasa Ratio dziedziczy publicznie z klasy Primitive
class Ratio : public Primitive{

public:
//konstruktor z lista inicjalizacyjna
Ratio(Primitive &val1,Primitive&val2):_val1(val1), _val2(val2){}
//przeslonieta metoda Getter, w tym przypadku zwraca wynik dzielenia 
double Getter() const override{return (_val1.Getter()) / (_val2.Getter());}
//przeslonieta metoda printThis
void printThis() const override;

private:
//zmienne uzyte do dzielenia
Primitive& _val1;
Primitive& _val2;
};