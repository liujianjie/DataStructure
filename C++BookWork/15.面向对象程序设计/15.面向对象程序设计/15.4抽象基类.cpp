#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Partice157.h"
#include "Disc_quote.h"

using namespace std;

/*
引出：
一种通用的折扣策略

一、纯虚函数
无需定义
在声明语句的分号之前书写=0就可以将一个虚函数说明为纯虚函数。
也可以为一个纯虚函数定义，但是不能在类内部定义

二、含有纯虚函数的类是抽象基类
1.含有（或者未经覆盖直接继承）纯虚函数的类是抽象基类
2.有纯虚函数的抽象基类不能定义对象，它的派生类可以有对象，但是前提是这些类覆盖了纯虚函数

三、派生类构造函数只初始化它的直接基类
1.Bulk_quote没有自己的数据成员，但也需要提供一个接受四个参数的构造函数
2.派生类构造函数将它的实参给disc_quote的构造函数，disc_quote的构造函数再继续调用quote的构造函数
当quote的构造函数完成再执行回disc_quote的构造函数初始化成员，最后运行派生类的构造函数

关键概念：重构
在Quote的继承体系中增加disc_quote类是重构的一个典型示例。
重构是将操作和或数据从一个类移动到另一个类中。
1.改不了整个继承体系，使用了bulk_quote或quote的代码也无须进行任何改动。不过一旦类被重构，就意味着我们必须
重新编译含有这些类的代码

*/



int main()
{
	int a;

	//Disc_quote dq;
	Bulk_quote bk;
	// 练习
	/*
	15.15 ok
	15.16 ok
	15.17：会报错误信息
	*/
	cin >> a;
	return 0;
}