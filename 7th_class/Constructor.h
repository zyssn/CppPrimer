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
	//���г��������á����������������ʱ�����ȳ�ʼ��
	Constructor() = default;
	//�ԣ�����Ƽ��ó�ʼ��������ʹ�ø�ֵ�ķ�ʽ�����ٿ�֧
	explicit Constructor(int i = 3) :i(i), b(i), j(i) {}
	const int print_j() const { return j; }
	//ί�й��캯����Ϊ���ⲻ��ʱ�˵����ͱ任��ʹ��explicit�ؼ���
	//explicit�ؼ���һ���������ڶԵ������Ĺ��캯���������Σ���ֹ��������ת��
	//ֻ������ǿת���в���
	void print_t() { cout << t << endl; }
	void add_t() { ++t; }
};


