#pragma once

class X {
private:
	Y* y;

public:
	X() = default;
};

class Y {
private:
	X x;

public:
	Y() = default;
};
