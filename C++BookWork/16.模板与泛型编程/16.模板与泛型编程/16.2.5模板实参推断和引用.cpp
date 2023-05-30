#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>
#include <list>
#include <string> 
#include <memory>
#include <type_traits>
#include <climits>
#include "Blob.h"
#include "DebugDelete.h"
#include "NoDefault.h"
using namespace std;

/*

*/
template <typename T> void f1(T& t1)
{
	//t1 = 54;
	cout << "f1(T&)" << endl;
}
template <typename T> void f2(const T& t1)
{
	//t1 = 54;
	cout << "f2(const T&)" << endl;
}
template <typename T> void f3(T&& t1)
{
	//t1 = 3;
	T t2 = t1;
	t2 = 4;
	//cout << "f3(T&&)" << endl;
	if (t2 == t1) {
		cout << "int&" << endl;
	}
	else {
		cout << "int" << endl;
	}
}

// 试试能否确定T为int而不为int&
template <typename T>
void f(const T& t1)
{
	cout << " f(const T&)" << endl;
}
template <typename T> 
void f(T&& t1)
{
	cout << " f(T&&)" << endl;
	/*T t2 = t1;
	t2 = 4;
	if (t2 == t1) {
		cout << "int&" << endl;
	}
	else {
		cout << "int" << endl;
	}*/
}
// test const T&
template <typename T>
void ctf(const T& t1)
{
	cout << " ctf(const T&)" << endl;
	T t2 = t1;
	t2 = 42;
	if (t2 == t1) {
		cout << "int&" << endl;
	}
	else {
		cout << "int" << endl;
	}
}

int main()
{
	int a;

	int i = 1;
	const int ci = 2;

	// T&
	f1(i);
	f1(ci);// T :const int??
	//f1(5);// 不能右值

	// const T&,T 默认const，会省略const
	f2(i);
	f2(ci);
	f2(42);// 折叠为const int& T为int

	cout << "f3()" << endl;
	// T&&
	f3(i);// T为int&
	//f3(ci);// T为const int&
	f3(42);// T为int

	// f3<int&>(int& &&);
	f3<int&>(i);

	cout << "four:解决是引用还是类型 int&与int" << endl;
	int i2 = 4;
	const int ci2 = 12;
	const int &&i3 = 23;
	f(i2);// 为什么选T&&版本,折叠比转换const更好吗
	f(ci2);// 选第二个
	f(42);// 选第一个
	f(std::move(i3));// 选第一个，不知道为什么
	f(static_cast<const int&&>(i3));// 选第一个，不知道为什么

	// 传const右值T还是int
	ctf(static_cast<const int&&>(i3));

	int a1 = 43,a2=32;
	//vector<int&> v2;

	/*
	练习：
	16.42:
	a是左值，b是const左值，c是右值
	a.int&,(int& )
	b.const int&,(const int&)
	c.int 整体为(int&&)

	16.43:
	i = ci 是一个左值 ？
	T:int&

	16.44：
	T：
	a.int int
	b.int int 
	c.int int// 不确定,网上说的是int
	
	const T&:
	a.int,(const int &)
	b.int,(const int &)
	c.int&&,(const int &)

	16.45：
	T为int，vector<int> v;
	T为int&,vector<int&> v;// 是非法的定义vector
	*/
	cin >> a;
	return 0;
}


