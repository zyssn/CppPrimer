#include "Screen.h"

char Screen::get() const
{
    return contents[cursor];
}

Screen& Screen::move(pos r, pos c)
{
    // TODO: 在此处插入 return 语句
    pos row = r * width;
    cursor = row + c;
    return *this;
}

void Screen::some_where() const
{
    index++;
}


char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	
	return contents[row + c];
}

Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

int height = 100;

