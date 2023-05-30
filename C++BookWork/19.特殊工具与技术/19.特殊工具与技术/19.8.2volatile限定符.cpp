#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <functional>
#include "Screen.h"

using namespace std;

class Task {

};

class Foo {
	Foo(const volatile Foo&);// 从一个volatile对象进行拷贝
	Foo& operator=(volatile const Foo&);// volatile 对象赋给非volatile对象
	Foo& operator=(volatile const Foo&) volatile;// volatile对象赋值给一个volatile对象
};
int main()
{
	int a;

	const int max_size = 20;
	volatile int display_register = 1;// 可能发生改变
	volatile Task *curr_task;// 指向一个volatile对象
	volatile int iax[max_size];// 每个元素都是volatile的
	volatile Screen bitmapBuf;// 每个成员都是volatile的

	cout << display_register << endl;
	display_register = 2;
	cout << display_register << endl;
	int novo = 3;
	display_register = novo;
	
	volatile int v;
	int *volatile vip;// volatile指针，指向int
	volatile int *ivp;// 是一个指针，指向volatile int
	// 是一个volatile指针，它指向一个volatile int
	volatile int *volatile vivp;

	//int *ip = &v;// 不可
	//vip = &v;// 不可
	ivp = &v;
	vivp = &v;


	/*
	练习：
	*/
	cin >> a;
	return 0;
}
