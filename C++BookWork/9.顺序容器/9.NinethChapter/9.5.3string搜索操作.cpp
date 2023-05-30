#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <array>
#include "Sales_data.h"
#include "noDefault.h"
#include <string>
using namespace std;

// 每一个都可以指定pos
int main()
{
	int a;
	cout << string::npos << endl;
	string s1("AnnaBelle");
	auto v1 = s1.find("Anna");
	cout << v1 << endl;
	s1 = "annaBelle";
	v1 = s1.find("anna");
	cout << v1 << endl;// npos

	string s2("0123456789"), s3("r2d2"), s4("123214d");
	auto v2 = s3.find_first_of(s2);// 2的下表
	cout << v2 << endl;
	v2 = s4.find_first_not_of(s2);// d的下标
	cout << v2 << endl;

	// 二，制定哪里开始搜索
	string::size_type p1 = 0;
	while ((p1 = s3.find_first_of(s2,p1)) != string::npos) {
		cout << "found number at index:" << p1 << "element is" << s3[p1] << endl;
		++p1;
	}
	// 三。逆向搜索
	string s6("Mississippi");
	auto first_pos1 = s6.find("is");//返回1
	auto las_pos1 = s6.rfind("is");//返回4

	string number("0123456789"), s7("d2324d"),s8("12312d8989d");
	auto v3 = s7.find_last_of(number);
	cout << v3 << endl;
	v3 = s8.find_last_not_of(number);
	cout << v3 << endl;

	cout << "------------" << endl;
	// 练习
	string ps1 = "ab2c3d7R4E6";
	string::size_type ppos = 0;
	while ((ppos = ps1.find_first_of(number, ppos)) != string::npos) {
		cout << "ps1 index:" << ppos << ",elements:" << ps1[ppos] << endl;
		ppos++;
	}
	
	char ac = 'a';
	char Ac = 'A';
	string str_c;
	for (int i = 0; i < 26; ++i) {
		str_c += (ac + i);
		str_c += (Ac+i);
	}

	cout << str_c <<endl;
	ppos = 0;
	while ((ppos = ps1.find_first_of(str_c, ppos)) != string::npos) {
		cout << "ps1 index:" << ppos << ",elements:" << ps1[ppos] << endl;
		ppos++;
	}
	// 练习2
	string pstr2("0123456789");
	string pstr3("r2d2");
	auto pv3 = pstr2.find(pstr3);
	cout << pv3 << endl;
	// static_cast 类型转换
	//int a1 = 99;
	//cout << static_cast<char>(a1) << endl;
	cin >> a;
	return 0;
}