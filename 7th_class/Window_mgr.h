#ifndef __WINDOW_MGR_H__
#define __WINDOW_MGR_H__
#include "Screen.h"
#include <iostream>
#include <vector>
using namespace std;

class Window_mgr {
	
private:
	vector<Screen> screens;

public:
	using ScreenIndex = vector<Screen>::size_type;
	inline void clear(ScreenIndex i);
	Window_mgr() { screens.push_back(Screen(24, 80, '*')); };
	inline void print(ScreenIndex i);
};

void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s = Screen(s.getHeight(), s.getWidth(), ' ');
}

void Window_mgr::print(ScreenIndex i) {
	screens[i].Content();
}


#endif