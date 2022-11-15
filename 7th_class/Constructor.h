#pragma once
#include "Screen.h"
using namespace std;

class Constructor
{
private:
	int i;
	int &b;
	const int j;
	Screen scr;

public:
	//错，有常量、引用、引入其他类的名称时必须先初始化
	Constructor() = default;
	//对，类更推荐用初始化而不是使用赋值的方式，减少开支
	Constructor(int i = 3):i(i), b(i), j(i), scr(Screen()) { }
	const int print_j() const { return j; }
};
