#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <string>
using namespace std;


class Screen
{
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht* wd, c) {}
	char get() const;
	string Content() const { return contents; }

	//注：inline函数的引用和定义都必须在头文件中
	inline char get(pos r, pos c) const;
	Screen& move(pos r, pos c);
	void some_where() const;

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	string contents;

	mutable pos index;
};

char Screen::get(pos r, pos c) const
{
	pos row = r * width;

	return contents[row + c];
}

#endif
