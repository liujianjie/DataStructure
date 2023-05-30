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

	const string Screen::*pdata;
	pdata = &Screen::contents;

	// 简单的
	auto pdata2 = &Screen::contents;

	Screen myScreen("myScreen"), *pScreen = &myScreen;
	auto s = myScreen.*pdata;
	cout << "s:" <<s<< endl;
	s = pScreen->*pdata;
	cout << "s:" << s << endl;

	Screen myScreen2("myScreen 2.0","myScreen 3.0");
	const string Screen::*pdata3 = Screen::data();

	auto s12 = myScreen2.*pdata3;
	cout << s12 << endl;

	// 
	cout << "---------练习---------" << endl;
	const Screen::pos Screen::*ppos = &Screen::cursor;
	Screen myScreen3;
	myScreen3.cursor = 10;
	auto val1 = myScreen3.*ppos;
	cout << val1 << endl;

	auto ppos2 = &Screen::cursor;
	cout << (myScreen3.*ppos2) << endl;

	//
	Sales_data sd("12312-12321-s");
	auto bokp = Sales_data::data();
	const string Sales_data::*bokp2 = Sales_data::data();
	cout << sd.*bokp << endl;
	cout << sd.*bokp2 << endl;

	/*
	练习：
	19.11:
	区别在于指向数据成员的指针没有指定对象，调用符号不同，需要考虑访问权限。
	普通的数据指针是固定的一个
	指向数据成员的指针是这个类型所有的对象的这个成员
	19.12：ok

	19.13：ok

	*/
	cin >> a;
	return 0;
}
