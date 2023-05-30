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
并不要求必须是类的成员，但改变的正好是所操作对象的状态，建议为成员函数
既有前后版本，应该同时定义

一、定义前置递增、递减运算符
前置：
与内置版本一致，应该返回递增或递减后对象的引用

二、区分前置与后置
就是使用一个参数，不被使用的 一个额外的
后置：
返回的是对象的原值，递增或递减之前的值，非引用

三、显示地调用后置运算符


*/
int main()
{
	int a;
	StrBlob a1;
	StrBloPtr p1(a1);
	//p1.operator++(0);//必不可少
	//p1.operator++();

	StrBlob a2,a3;
	a2.push_back("you");
	a2.push_back("and");
	a2.push_back("lov2e");
	a3.push_back("me");
	a3.push_back("love");
	StrBloPtr p2(a2),p3(a2);
	p2 = p2 + 2;
	cout << p2.deref() << endl;
	p2 -= 1;
	cout << p2.deref() << endl;
	//p2 -= 3;
	//cout << (p2 + 3).deref() << endl;
	/*
	练习
	14.27:ok
	14.28：
	14.29：因为会改变自身呀
	*/

	cin >> a;
	return 0;
}