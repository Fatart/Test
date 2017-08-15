#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <string>
#include <vector>
#include "screen.h"

class Window_mgr{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
private:
	std::vector<Screen> screens;
};

inline void Window_mgr::clear(ScreenIndex i)   //it is mandatory to define inline out of class definition
{
	if (i >= screens.size()) return;    //judge for out_of_range
	Screen &s = screens[i];
	//s.contents = std::string(s.height * s.width,' ');
	s.contents;
}




#endif // !WINDOW_MGR_H
#pragma once
