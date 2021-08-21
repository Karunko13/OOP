#pragma once
#include <cmath>
#include <iostream>

class Point2D{

	private:

	//współrzędna x
	int w_x;

	//współrzędna y
	int w_y;

	//odleglosc pkt od środka układu współrzędnych,liczona z tw Pitagorasa
	double w_distCentre;

	public:
	//konstruktor domyślny
	Point2D()=default;

	//konstruktor dwuparametrowy z listą inicjalizacyjną
	Point2D(int x, int y): w_x(x), w_y(y), w_distCentre(sqrt(x*x+y*y)) 
	{}

	//przeciążony operator "<" potrzebny do porównania dwóch punktów na podstawie ich odległości od środka układu współrzędnych
	bool operator <(const Point2D& second) const;

	//metoda do wypisywania na ekran
	void Print() const;

	//getter dla zmiennej w_x
	int showX() const;

	//getter dla zmiennej w_y
	int showY() const;

	//statyczna metoda wypisujaca na ekran informacje o obiekcie point, wywoluje po prostu metodę Print() na obiekcie point
	static void PrintPoint(const Point2D& point);

	//statyczna metoda wypisujaca na ekran współrzędną Y punktu
	static void FunctionPrintY(const Point2D& point);

	};


inline int Point2D::showX() const
{
	return w_x;
}

inline int Point2D::showY() const
{
	return w_y;
}

//funkcja zwraca prawdę, jeżeli większa ze współrzędnych pierwszego punktu(point1) jest mniejsza od większej współrzędnej drugiego punktu(point2)
bool MaxDistanceAsc(const Point2D& point1, const Point2D& point2);

//funckja wypisujaca na ekran wspołrzędną w_x
void FunctionPrintX(const Point2D& point1);

//klasa funktor
class OrderAscX{
	public:
	//przeciążony operator (), porównuje dwa punkty na podstawie tylko współrzędnej X
	int operator ()(const Point2D& point1, const Point2D& point2) const;
};

//klasa funktor
class OrderDescY{
	public:
	//przeciążony operator (), porównuje dwa punkty tylko na podstawie współrzędnej Y
	int operator ()(const Point2D& point1, const Point2D& point2) const;
};

