#pragma once
#include "Figure_3D.h"
class ball : public Figure_3D
{
public:
	ball() = default;
	ball(double x, double y, double z) : Figure_3D(x, y, z) {}
	double perimeter() override final {
		double tmp = getX();
		double res = tmp * tmp * PI;
		return res;
	}
	double area() override final {
		return pow(getX(), 3) * PI / 3;
	}
};

