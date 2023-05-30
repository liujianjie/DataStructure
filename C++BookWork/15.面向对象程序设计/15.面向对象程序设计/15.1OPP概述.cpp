#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"

using namespace std;

/*
引出：
面向对象程序设计的核心思想是数据抽象、继承和动态绑定
数据抽象：将类的接口与实现分离
继承：相似的类型并对其相似关系建模
动态绑定：在一定程度上忽略相似的类型的区别，而以统一的方式使用它们的对象

一、继承
继承：联系在一起的类构成一种层次关系，基类，派生类

虚函数：派生类各自定义适合自身的版本，virtual开头，基类中声明也可以定义
类派生列表：明确指出是哪个基类继承而来的，一个冒号 + 访问说明符 + 基类

派生类如果对虚函数重新定义了就需要进行声明

二、动态绑定
能用同一段代码分别处理Quote和Bulk_quote对象。
动态绑定有时又被称为运行时绑定
note：当我们使用基类的引用 或指针调用一个虚函数时将发生动态绑定

*/

double print_total(ostream& os,
	const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn() <<
		"# sold:" << n << "total due:" << ret << endl;
}
int main()
{
	int a;

	Quote basic;

	Bulk_quote bulk;

	print_total(cout, basic, 20);
	print_total(cout, bulk, 20);

	cin >> a;
	return 0;
}