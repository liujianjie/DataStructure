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

	// �򵥵�
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
	cout << "---------��ϰ---------" << endl;
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
	��ϰ��
	19.11:
	��������ָ�����ݳ�Ա��ָ��û��ָ�����󣬵��÷��Ų�ͬ����Ҫ���Ƿ���Ȩ�ޡ�
	��ͨ������ָ���ǹ̶���һ��
	ָ�����ݳ�Ա��ָ��������������еĶ���������Ա
	19.12��ok

	19.13��ok

	*/
	cin >> a;
	return 0;
}
