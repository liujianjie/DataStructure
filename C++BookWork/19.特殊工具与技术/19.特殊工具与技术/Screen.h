#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
using namespace std;
//int height;
class Screen
{
public:
	typedef std::string::size_type pos;
	using Action = char (Screen::*)(Screen::pos,Screen::pos) const;

	Screen& action(Screen& sc, Action ac1 = &Screen::get) {
		cout << "action:" << (sc.*ac1)(sc.height,sc.width) << endl;
		return sc;
	}
	Screen();
	Screen(string c):contents(c),cursor(0), height(0), width(0){}
	Screen(string c,string s) :contents(c),contentss(s), cursor(0), height(0), width(0) {}
	~Screen();

	char get_cursor() const { 
		return contents[cursor]; 
	}
	char get()const { return 'b'; }
	char get(pos ht, pos wd)const { return 'a'; }

	static const std::string Screen::*data() {
		return &Screen::contentss;
	}

	// 练习
	using othername1 = char (Screen::*)()const;
public:
	std::string contents;
	pos cursor;
	pos height, width;

private:
	std::string contentss;

public:
	Screen& home() { cout << "hom()" << endl; return *this; 
	}
	Screen& forward() { cout << "forward()" << endl; return *this;
	}
	Screen& back() { cout << "back()" << endl; return *this;
	}
	Screen& up() { cout << "up()" << endl; return *this;
	}
	Screen& down() { cout << "down()" << endl; return *this;
	}
	using Action2 = Screen& (Screen::*)();
	enum Directions { HOME, FORWARD, BACK, UP, DOWN };// 代表0，1,2,2是Menu的下标
	Screen& move(Directions cm) {
		return (this->*Menu[cm])();
	}
private:
	static Action2 Menu[];// 函数表 得放入函数，放入成员
};

#endif // SCREEN_H