#pragma once
#include "Figure.h"

class Figure_3D : public Figure
{
public:
	Figure_3D() = default;
	Figure_3D(double x, double y, double z) : Figure(x, y), zSize(z) {}
	virtual double perimeter() = 0;
	virtual double area() = 0;
	double getZ() { return zSize; }

private:
	double zSize;

protected:
	const double PI = 3.14;
};

