#pragma once
//#include "Screen.h"
#include<iostream>
using namespace std;

class Constructor
{
private:
	int i;
	int &b;
	const int j;
	//Screen scr;
	static int t;

public:
	//错，有常量、引用、引入其他类的名称时必须先初始化
	Constructor() = default;
	//对，类更推荐用初始化而不是使用赋值的方式，减少开支
	explicit Constructor(int i = 3) :i(i), b(i), j(i) {}
	const int print_j() const { return j; }
	//委托构造函数，为避免不合时宜的类型变换，使用explicit关键字
	//explicit关键字一般用于类内对单参数的构造函数进行修饰，防止隐性类型转换
	//只能主动强转进行操作
	void print_t() { cout << t << endl; }
	void add_t() { ++t; }
};


