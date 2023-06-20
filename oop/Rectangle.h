#pragma once
#include "Figure_2D.h"
class Rectangle : public Figure_2D
{
public:
	Rectangle() = default;
	Rectangle(double x, double y) : Figure_2D(x, y) {}
	inline double perimeter() override final {
		return 2 * (getX() + getY());
	}
	inline double area() override final {
		return getX() * getY();
	}
};

