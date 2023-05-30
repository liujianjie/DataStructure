#include <iostream>
#include <string>
#include <vector>

using namespace std;

int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };
decltype(odd) *arrPtr(int i)
{
	return (i % 2) ? &odd : &even;
}
int main() 
{
	int getchar;
	// 返回数组指针

	// 1.类型别名
	typedef int arrT[10];	//表示含有10个整数的数组
	using arrT = int[10]; // 等价的声明，不影响，可以
	arrT* func(int i);	// func返回一个指向含有10个整数的数组的指针

	// 2.声明一个返回数组指针的函数,这是普通的定义，函数的返回值 返回数组指针的函数定义不一样
	int arr[10];
	int *p1[10];
	int(*p2)[10] = &arr;

	// 与上一个一样，不可以，不能重定义，除非维度一样
	//int(*func(int i))[9];
	int(*func2(int i))[9];

	// 3.使用尾置返回类型
	auto func(int i) -> int(*)[10];

	// 4.使用decltype，如果知道函数要返回的指针将指向哪个数组，就可以使用decltype关键字声明返回类型。
	//int arrs[5] = arrPtr(4);
	// 返回一个指针，该指针指向含有5个整数的数组
	// 注意：decltype并不负责把数组类型转换成相对应的指针，所以，decltype返回的是数组，想要表示返回指针还需在函数声明时添加一个*

	cin >> getchar;
	return 0;
}