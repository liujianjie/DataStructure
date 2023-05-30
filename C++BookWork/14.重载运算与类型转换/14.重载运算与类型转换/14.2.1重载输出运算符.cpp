#include <iostream>
#include "String.h"
using namespace std;

/*
索引：
1.第一个形参是非常量ostream对象的引用(因为会改变其状态，无法直接复制一个ostream)
2.第二个形参是一个常量的引用，打印的类型，引用是避免复制实参，打印不会改变对象内容


二、输出运算符尽量减少格式化操作

三、输入输出运算符必须是非成员函数
因为左侧运算对象是我们类的第一个对象

假设输入输出是某个类的成员，则他们也必须是istream或ostream的成员。然而，这两个类属于标准库，无法给标准库中的类添加任何成员


*/
int main()
{
	int a;
	// 练习
	// 14.6

	// 14.7
	String st("String first");
	cout << st;

	// 14.8
	cin >> a;
	return 0;
}