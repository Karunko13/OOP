#include "Point2D.h"

bool Point2D::operator <(const Point2D& second) const 
{
	return w_distCentre < second.w_distCentre;
}

void Point2D::Print() const
{
	std::cout << "Point coordinates (" << w_x << ", " <<w_y << ") distance from origin: " <<w_distCentre << std::endl;
}

int OrderAscX::operator ()(const Point2D& point1, const Point2D& point2) const
{
	if(point1.showX() < point2.showX())	return 1;
	else return 0;
	
}

int OrderDescY::operator ()(const Point2D& point1, const Point2D& point2) const
{
	if(point1.showY() > point2.showY())	return 1;
	else return 0;
}

bool MaxDistanceAsc(const Point2D& point1, const Point2D& point2)
{
	int a=0,b=0;

	if(point1.showX() > point1.showY()) 
	{
		a = point1.showX();
	}
	else
	{
		a = point1.showY();
	}

	if(point2.showX() > point2.showY()) 
	{
		b = point2.showX();
	}
	else
	{
		b = point2.showY();
	}

	return(a < b);
}

void FunctionPrintX(const Point2D& point1)
{
	std::cout << "Function print x=" << point1.showX() << std::endl;
}

void Point2D::FunctionPrintY(const Point2D& point)
{
	std::cout << "Function print y=" << point.showY() << std::endl;
}

void Point2D::PrintPoint(const Point2D& point)
{
	point.Print();
}