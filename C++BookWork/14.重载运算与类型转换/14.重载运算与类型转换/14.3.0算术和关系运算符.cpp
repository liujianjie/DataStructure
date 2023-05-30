#include <iostream>
#include "String.h"
#include "Sales_data.h"
using namespace std;

/*
开篇：
通常是非成员函数，以允许对左侧或右侧的运算对象进行转换。都是常量的引用

新得到的值通常是局部变量，返回这个副本

如果有算术运算符，一般有一个对应的复合赋值运算符，，使用复合赋值来定义算术运算符

*/
int main()
{
	int a;

	// 练习
	/*
	14.13 不会
	*/
	/*
	因为返回局部对象，不会改变左侧和右侧自身
	*/
	/*
	14.15 不会
	*/
	cin >> a;
	return 0;
}