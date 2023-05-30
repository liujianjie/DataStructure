#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
using namespace std;
//int height;
class Screen
{
public:
	Screen();
	~Screen();

	typedef std::string::size_type poss;
	void setHeight(poss);
	poss height = 0; // Òþ²ØÍâ²ã
};
// Error
//Screen::poss verifys(Screen::poss);
//Screen::poss verifys(Screen::poss) {
//	return 1 * 2;
//}

#endif // SCREEN_H