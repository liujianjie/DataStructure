#include "Window_mgr.h"

Window_mgr::Window_mgr()
{
}
Window_mgr::~Window_mgr()
{
}

void Window_mgr::clear(ScreenIndex i)
{
	Screens &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screens& s)
{
	screens.push_back(s);
	return screens.size() - 1;
}