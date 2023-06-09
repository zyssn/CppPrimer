#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <string>
#include <iostream>
//#include "Window_mgr.h"

using namespace std;

extern int height;

class Screen
{
	//哪个类需要引用当前类的私有成员，则将其设置为友元函数
	//friend class Window_mgr;
	//也可以将单个函数引用为友元函数
	//friend void Window_mgr::clear(ScreenIndex i);
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht* wd, c) {}
	char get() const;
	string Content() const { return contents; }

	//注：inline函数的引用和定义都必须在头文件中
	inline char get(pos r, pos c) const;
	inline Screen &set(char c);
	//先调用函数参数、在调用成员变量，最后调用类外变量，执行顺序3 2 1
	int bigCur() { return width * ::height; }					// 1
	int midCur() { return width * height; }						// 2
	int smallCur(int height = 10) { return width * height; }	// 3
	Screen& move(pos r, pos c);
	void some_where() const;
	pos getHeight() const { return height; }
	pos getWidth() const { return width; }

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 10;
	string contents;

	mutable pos index = 0;
};


#endif
