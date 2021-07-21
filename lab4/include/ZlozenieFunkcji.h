#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

class ZlozenieFunkcji
{

	private:
	//wektor ans przechowujacy wyniki kolejnych złożeń
	std::vector<double> ans;
	// wektor "_zlozenie" przechowujacy szablony funkcji typu double, przyjmujące jeden argument typu double
	std::vector< std::function<double(double)>> _zlozenie;

	public:
	//konstruktor domyślny
	ZlozenieFunkcji()=default;
	//destruktor
	~ZlozenieFunkcji();
	//metoda dokładająca na koniec wektora "_zlozenie" kolejny element, uzywa push_back z std::vector
	void insert(std::function<double(double)> funkcja);
	//operator [] zwraca wyniki zlożeń funkcji
	double operator [](double id) ;
	//
	double wynik(double x);
};