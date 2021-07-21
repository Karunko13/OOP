#include "Funkcje.h"

Sinus::Sinus(double _a,double _b)
{
	a = _a;
	b = _b;
}

Liniowa::Liniowa(double _a,double _b)
{
	a = _a;
	b = _b;
}
double Liniowa::operator () (double x) const
{
	return a*x+b;
}
double Sinus::operator () (double x) const
{
	
	return sin(a*x+b);
}
double PierwiastekKwadratowy::operator () (double x) const
{
	return sqrt(x);
}