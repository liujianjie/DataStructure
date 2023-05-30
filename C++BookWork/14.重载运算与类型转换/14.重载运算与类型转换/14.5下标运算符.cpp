#include <iostream>
#include "String.h"
#include "Sales_data.h"
#include "StrVec.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Employee.h"
#include <memory>
using namespace std;

/*
必须是成员函数

与原始定义兼容，通常返回所访问元素的引用，好处：能让下标可以出现在左右两侧
定义常量与非常量版本




*/
int main()
{
	// 练习一道ok
	int a;
	StrVec sv1;
	sv1.push_back("pbcl");
	const StrVec sv2 = sv1;
	//if (sv1.size() && sv1[0].empty()) {
		sv1[0] = "zer";
		//sv2[0] = "zip";
	//}
	sv1.printStrVec();

	String st1("sring a not");
	st1[1] = 'c';
	cout << st1.c_str() << endl;

	cout << "----------------" << endl;

	StrBlob sb1;
	sb1.push_back("sdfasd");
	sb1.push_back("zvzcx");
	sb1[1] = "aaa";
	cout << sb1.back() << endl;

	StrBloPtr sbp1(sb1);
	sbp1[0] = "zzzz";
	cout << sbp1[0] << endl;
	cout << sb1[0] << endl;
	cin >> a;
	return 0;
}