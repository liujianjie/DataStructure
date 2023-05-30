#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include "Screens.h"
#include <iostream>
#include <vector>

class Window_mgr
{
public:
	Window_mgr();
	~Window_mgr();

	using ScreenIndex = std::vector<Screens>::size_type;

	void clear(ScreenIndex);

	// 7.4 类的作用域
	ScreenIndex addScreen(const Screens&);
private:
	std::vector<Screens> screens{ Screens(24, 80, ' ') };// 互相引用 先注释
};

#endif // WINDOW_MGR_H