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
	//���г��������á����������������ʱ�����ȳ�ʼ��
	Constructor() = default;
	//�ԣ�����Ƽ��ó�ʼ��������ʹ�ø�ֵ�ķ�ʽ�����ٿ�֧
	Constructor(int i = 3):i(i), b(i), j(i), scr(Screen()) { }
	const int print_j() const { return j; }
};
