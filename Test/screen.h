#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <vector>
#include "Window_mgr.h"



//----------------------------------------------------------------------------------------------
class Screen {
	
	using ScreenIndex = std::vector<Screen>::size_type;
	using pos = std::string::size_type;
	//friend void Window_mgr::clear(ScreenIndex);
	friend class Window_mgr;
public:
	// default constructor
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ') {}
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}

	//member function
	char get() const { return contents[cursor]; }
	char get(pos r, pos c) const { return contents[r*width + c]; }
	inline Screen &move(pos r, pos c);
	inline Screen &set(char);
	inline Screen &set(pos, pos, char);

	const Screen &display(std::ostream &os) const { do_display(os); return *this; }
	Screen& display(std::ostream &os) { do_display(os); return *this; }

private:
	void do_display(std::ostream &os) const { os << contents; }

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

inline Screen & Screen::move(pos r, pos c)
{
	cursor = r*width + c;
	return *this;
}

//member function
inline Screen & Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
inline Screen & Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}




#endif // !SCREEN_H