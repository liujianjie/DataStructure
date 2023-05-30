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

	cout << "-------��ϰ-------" << endl;
	auto pmf4 = &Screen::get_cursor;
	pmf4 = &Screen::get;
	/*
	��ϰ��
	19.14:
	�Ϸ�����Ϊ��һ��getҲ���޲�const
	19.15:
	ָ���Ա������ָ����һ�������ͬ�����Ĺ��ܣ�����ָ��ֻ��ָ��һ��

	���ϣ����õķ��ţ���Ҫ��������Ȩ�ޣ�������ָ�벻���Զ�ת��

	6)	����ָͨ�������ǣ���Ա������ָ��ó�Ա��ָ��֮�䲻�����Զ�ת�����򣬱�����ʾ&

	19.16��
	ok
	*/
	cin >> a;
	return 0;
}
