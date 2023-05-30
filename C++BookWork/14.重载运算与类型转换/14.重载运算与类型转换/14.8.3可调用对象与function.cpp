#include <iostream>
#include "String.h"
#include <map>
#include "Sales_data.h"
#include "StrVec.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Employee.h"
#include <memory>
#include <functional>
#include "NewClass1432.h"
using namespace std;

/*
引出：
与对象一样，可调用的对象也有类型。函数及函数指针的类型由其返回值类型和实参类型决定

问题：两个不同类型的可调用对象可能共享同一种 调用形式。
调用形式：指明返回的类型和实参类型。
一种调用形式对应一个函数类型

二、不同类型可能具有相同的调用形式
定义一个函数表，来存储指向这些课调用对象的 “指针”，但是虽然调用形式一样，但是类型不一样，
add是函数指针，lambda有自己的类类型

三、标准库function类型
// 为解决上述问题，function标准库类型，可以存储同一种调用形式的函数，lambda或者类型

四、重载的函数与function
不能将重载的函数放入function中

int(*fp1)(int, int) = overadds;
binops3.insert({ "+",fp1 });// 可以用函数指针，会指定特定版本

或者使用lambda代替重载的函数

*/
//
int adds(int i, int j) 
{
	return i + j; 
}
struct divide {
	int operator()(int d, int d2) {
		return d / d2;
	}
};
auto mod = [](int i, int j) { return i % j; };

double overadds(double i, double j)
{
	return i + j;
}
int overadds(int i, int j)
{
	return i + j;
}
int main()
{
	int a;

	// 因为调用形式都一样，所以可以使用int(*)(int,int)形式存储
	map<string, int(*)(int, int)> binops;
	binops.insert({ "+",adds });
	binops.insert({ "%",mod });// 本来11会报错的，因为lambda是一个未命名的类型
	//binops.insert({ "%",divide() });// 报错，函数指针不能存储这样的

	// 为解决上述问题，function标准库类型，可以存储同一种调用形式的函数，lambda或者类型
	function<int(int, int)> f1 = adds;
	function<int(int, int)> f2 = divide();
	function<int(int, int)> f3 = [](int i, int j) {return i * j; };
	cout << f1(4, 2) << endl;
	cout << f2(4, 2) << endl;
	cout << f3(4, 2) << endl;

	map <string, function<int(int, int)>> binops2 = {
		{"+",adds},
		{ "-",std::minus<int>() },
		{ "/",divide() },
		{ "*",[](int i, int j) {return i * j; }},
		{ "%",mod }
	};
	cout << binops2["+"](10, 5) << endl;
	binops2["-"](10, 5);
	binops2["/"](10, 5);
	binops2["*"](10, 5);
	binops2["%"](10, 5);

	// 三、
	map <string, function<int(int, int)>> binops3;
	//binops3.insert({"+",overadds});// 报错
	int(*fp1)(int, int) = overadds;
	double(*fp2)(double, double) = overadds;
	binops3.insert({ "+",fp1 });// 可以用函数指针，会指定特定版本

	cout << "----" << endl;
	string ope;
	cout << "输入符号" << endl;
	cin >> ope;
	double v1, v2;
	cout << "输入两个要计算的值" << endl;
	cin >> v1 >> v2;
	cout << binops2[ope](v1, v2) << endl;
	// 练习
	/*
	14.44 ok，没有类，就一个map，没有面向对象，就直接的操作
	*/
	cin >> a;
	return 0;
}