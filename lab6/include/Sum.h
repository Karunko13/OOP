#pragma once
#include "Primitive.h"
//klasa Sum dziedziczy publicznie z klasy Primitive
class Sum : public Primitive{

public:
//konstrukotr z lista inicjalizacyjna
Sum(Primitive& val1,Primitive& val2): _val1(val1), _val2(val2){}
//przeslonieta metoda Getter, w tym przypadku zwraca wynik dodawania dwoch wartosi
double Getter() const override{return (_val1.Getter()) + (_val2.Getter());}
//przeslonieta metoda printThis
void printThis() const override;

private:
//wartosci uzyte do operacji dodawania
Primitive& _val1;
Primitive& _val2;
};