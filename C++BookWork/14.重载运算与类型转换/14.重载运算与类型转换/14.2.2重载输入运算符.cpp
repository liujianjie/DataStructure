#include <iostream>
#include "String.h"
#include "Sales_data.h"
using namespace std;

/*
开篇：
通常第一个形参是运算符要读取的流的引用
第二个形参是要读入到的非常量对象的引用，不是const

一、输入运算符可能有错，而输出运算符没有

二、输入可能的错误
1.类型不匹配
2.当达到文件末尾或遇到其它错误

一次性检查

三、标示错误


*/
int main()
{
	int a;
	// 练习
	// 14.10
	Sales_data s;
	//cin >> s;// 隐式
	operator >> (cin, s);// 直接
	// 若输入第二条数据 会退出，就是读取失败

	// 14.11 就是会不会恢复

	// 14.12

	cin >> a;
	return 0;
}