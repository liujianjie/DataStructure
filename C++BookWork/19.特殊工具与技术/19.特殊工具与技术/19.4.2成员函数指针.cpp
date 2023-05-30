#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Screen.h"
#include "Sales_data.h"
using namespace std;

int main()
{
	int a;
	auto pmf = &Screen::get_cursor;
	char (Screen::*pmf2)(Screen::pos ht, Screen::pos wd) const;
	pmf2 = &Screen::get;

	//pmf2 = &Screen::get;
	//pmf2 = Screen::get;
	
	Screen myScreen("myscreen"), *pScreen = &myScreen;
	char c1 = (pScreen->*pmf)();
	cout << c1 << endl;
	char c2 = (myScreen.*pmf)();
	cout << c2 << endl;

	char c3 = (myScreen.*pmf2)(0,0);
	cout << c3 << endl;

	using action = char (Screen::*)() const;
	action pmf3 = &Screen::get_cursor;

	myScreen.action(myScreen);
	myScreen.action(myScreen, &Screen::get);

	myScreen.move(Screen::HOME);
	myScreen.move(Screen::DOWN);

	cout << "-------练习-------" << endl;
	auto pmf4 = &Screen::get_cursor;
	pmf4 = &Screen::get;
	/*
	练习：
	19.14:
	合法，因为有一个get也是无参const
	19.15:
	指向成员函数的指针是一类具有相同参数的功能，函数指针只能指定一个

	网上：调用的符号，需要考虑类内权限，函数与指针不会自动转换

	6)	和普通指针区别是：成员函数和指向该成员的指针之间不存在自动转换规则，必须显示&

	19.16：
	ok
	*/
	cin >> a;
	return 0;
}
