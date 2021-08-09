#pragma once
#include "Primitive.h"
//klasa product dziedziczy publicznie z klasy Primitive
class Product : public Primitive{

public:
//konstruktor z lista inicjalizacyjna
Product(Primitive& val1,Primitive& val2): _val1(val1), _val2(val2){}
//przeslonieta metoda Getter
double Getter() const override{return (_val1.Getter()) * (_val2.Getter());}
//przeslonieta metoda printThis
void printThis() const override;

private:
//zmienne uzyte do mnozenia
Primitive& _val1;
Primitive& _val2;

};