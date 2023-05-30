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
赋值需要是成员

开篇：
类除了拷贝赋值和移动赋值还可以 使用别的类型作为右侧运算对象，如：花括号内。
也能用在我们自己定义的类中。

不同的是 无需检查自身赋值

note:我们可以重载赋值运算符，不论形参的类型是什么，必须是成员函数

二、复合赋值运算符
1.不非得是类的成员，更倾向为定义类的内部
2.为了与内置类型的复合赋值保持一致，也要返回以左侧对象的引用
*/
int main()
{
	int a;
	StrVec sv1;
	sv1 = { "asdf","dsfds","zcv" };
	sv1.printStrVec();

	// 练习
	Sales_data sd1;
	sd1 = string("123123");
	cout << sd1.isbn() << sd1.getrevene() << endl;

	Sales_data sd2;
	sd2 = { "adsfad-sfasdf-asdfas",10,23 };
	print(cout, sd2);
	/*
	14.20 ok

	*14.21 反一下，+= 调用 +,可读性差。没有ok！

	14.22 ok

	14.23 ok

	14.24 拷贝赋值需要，移动赋值不需要，没有增的，没有写 ok

	14.25 还需要方括号的吧，懒得写 ok
	*/
	cin >> a;
	return 0;
}