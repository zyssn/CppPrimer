#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <string>
#include <iostream>
//#include "Window_mgr.h"

using namespace std;

extern int height;

class Screen
{
	//�ĸ�����Ҫ���õ�ǰ���˽�г�Ա����������Ϊ��Ԫ����
	//friend class Window_mgr;
	//Ҳ���Խ�������������Ϊ��Ԫ����
	//friend void Window_mgr::clear(ScreenIndex i);
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht* wd, c) {}
	char get() const;
	string Content() const { return contents; }

	//ע��inline���������úͶ��嶼������ͷ�ļ���
	inline char get(pos r, pos c) const;
	inline Screen &set(char c);
	//�ȵ��ú����������ڵ��ó�Ա�������������������
	int bigCur() { return width * ::height; }
	int midCur() { return width * height; }
	int smallCur(int height = 10) { return width * height; }
	Screen& move(pos r, pos c);
	void some_where() const;

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 10;
	string contents;

	mutable pos index = 0;
};


#endif
