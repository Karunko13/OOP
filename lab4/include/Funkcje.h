#pragma once
#include <iostream>
#include <cmath>

class Sinus
{
	private:

	double a;
	double b;

	public:
	//konstruktor 
	Sinus(double _a,double _b);
	//Sinus( const Sinus&org): a(org.a), b(org.b) {}
	double operator () (double ) const;
};

class PierwiastekKwadratowy
{
	private:

	public:
	//konstruktor domyslny
	PierwiastekKwadratowy()=default;

	double operator () (double ) const;
};

class Liniowa
{
	private:
	
	double a;
	double b;

	public:
		//konstruktor
	Liniowa(double _a,double _b);
	//Liniowa(const Liniowa&org): a(org.a), b(org.b) {}	
	double operator () (double ) const;
};
