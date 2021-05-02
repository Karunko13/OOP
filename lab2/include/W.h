#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class W{
	private:
	//rozmiar wektora(ilosc elementow)
	 int _size;
	//wskaznik na początek
	 int *tab;
	
	public:
	
	//konstruktor domyslny
	W();
	
	//konstruktor jednoparametrowy, używam explicit aby zakazać niejawnej konwersji "5" na tymczasowy obiekt, a następnie wywołania konstruktora przenoszącego (W strange = 5)
	explicit W(int size);
	
	//konstruktor kopiujacy
	W(const W&org );

	//metoda at,zwraca adres tab[part]
	int &at(int part) const;

	//metoda wypisujaca wektor
	void print(const string &name) const;
	
	//metoda zwracajaca double(iloczyn skalarny dwóch wektorów), jako argumenty przyjmuje referencje do dwoch wektorow
	static double dot(const W& vec1,const W& vec2);
	
	//operator konwersji na double, zwraca (double)norme wektora, dziala jak metoda norm()
	operator double() const;
	
	//metoda zwracajaca double(norme wektora),działa tak jak operator double
	double norm() const;
	
	//przeciążenie operatora +=, przyjmuje jako argument const obiekt klasy W, nic nie zwraca=void
	void operator +=(const W org);
	
	//przeciążenie operatora +=, przyjmuje jako arugment const int, zwraca obiekt klasy W
	W operator +=(const int plus);
};