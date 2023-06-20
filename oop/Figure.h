#pragma once
#include "../11th_associative_container/include.h"

using namespace std;

class Figure
{
public:
	Figure() = default;
	Figure(double x, double y) : xSize(x), ySize(y) {}
	virtual double perimeter() = 0;
	virtual double area() = 0;
	double getX() { return xSize; }
	double getY() { return ySize; }

private:
	double xSize = 0;
	double ySize = 0;
};

