#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"

using namespace std;

/*
引出：无
1.通常定义一个虚析构函数，即使该函数不执行任何操作

二、成员函数与继承
1.派生类需要对其重新定义。提供新定义也称为覆盖从基类继承而来的旧定义
2.基类成员函数分两种：
1.希望派生类进行覆盖的函数。即是虚函数
2.希望派生类直接继承的函数。即是成员函数
3.需要指针或者引用才会动态绑定。
4.任何构造函数之外的非静态函数都可以是虚函数
5.virtual不能出现在类外部的函数定义
6.基类一个函数声明成虚函数，则函数在派生类中隐式地也是虚函数。
7.成员函数不是虚函数的话，在编译时解析，虚函数在运行时

三、访问控制与继承
1.派生类能访问公有成员，而不能访问私有成员
2.基类希望它的派生类有权访问该成员，同时禁止其他用户访问，用受保护的访问运算符说明
protected，即使基类的对象也不可访问，但是在派生类的类内部可以访问

*/

double print_total(ostream& os,
	const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn() <<
		"# sold:" << n << "total due:" << ret << endl;
	return ret;
}
int main()
{
	int a;

	Quote basic;
	Bulk_quote bulk;
	// 练习
	/*
	15.1 virtual声明的成员函数
	15.2protected是受保护的，private是私有的 
	protected，即使基类的对象也不可访问，但是在派生类的类内部可以访问
	protected，即使基类的对象也不可访问，在派生类的类内部也不可以访问
	*/
	cin >> a;
	return 0;
}