#pragma once
#include "Figure.h"

class Figure_2D : public Figure
{
public:
	Figure_2D() = default;
	Figure_2D(double x, double y) : Figure(x, y) {}
	virtual double perimeter() = 0;
	virtual double area() = 0;

};

