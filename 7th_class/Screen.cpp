#include "Screen.h"

char Screen::get() const
{
    return contents[cursor];
}

Screen& Screen::move(pos r, pos c)
{
    // TODO: �ڴ˴����� return ���
    pos row = r * width;
    cursor = row + c;
    return *this;
}

void Screen::some_where() const
{
    index++;
}


