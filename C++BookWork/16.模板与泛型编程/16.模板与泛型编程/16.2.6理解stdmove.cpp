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

// 试试能否确定T为int而不为int&
//template <typename T>
//void f(const T& t1)
//{
//	// 不知道为什么，这个不可
//	//const int &v1 = 43;
//	// int &&d = v1;
//	// T是&&，t1是const int& 为什么不行呢
//	cout << " f(const T&)" << endl;
//	T t2 = t1;
//	t2 = 1114;
//	if (t2 == t1) {
//		cout << "int&" << endl;
//	}
//	else {
//		cout << "int" << endl;
//	}
//}
//template <typename T>
//void f(T&& t1)
//{
//	cout << " f(T&&)" << endl;
	/*T t2 = t1;
	t2 = 4;
	if (t2 == t1) {
	cout << "int&" << endl;
	}
	else {
	cout << "int" << endl;
	}*/
//}

template <typename T>
typename remove_reference<T>::type&& moves(T&& t)
{
	return static_cast<typename remove_reference<T>::type&&>(t);
}

int main()
{
	int a;
	// 前一节内容
	//cout << "four:解决是引用还是类型 int&与int" << endl;
	//int i2 = 4;
	//const int ci2 = 12;
	//const int &&i3 = 23;
	//f(i2);// 为什么选T&&版本,折叠比转换const更好吗
	//f(ci2);// 选第二个
	//f(42);// 选第一个
	//f(std::move(i3));// 选第一个，不知道为什么
	//f(static_cast<const int&&>(i3));// 选第一个，不知道为什么
	int &&ii1 = 223;
	int &ii2 = ii1;
	int i1 = 9, i2;
	i2 = std::move(i1);
	cout << i2 << endl;
	cout << i1 << endl;

	int &&i3 = static_cast<int&&>(i1);
	cout << i3 <<"123"<< endl;

	int i4 = i3;
	cout << i4 << endl;

	int i5 = moves(i3);
	cout << i5 << endl;

	//int &&i7 = i1;// 本来是无法将一个左值给右值的
	int &&i6 = moves(i1);// 传入左值，返回右值
	cout << i6 << endl;

	//不可的
	//int &&i7 = &&i6;
	int &&i7 = moves(i6);
	
	/*
	练习：
	16.46:
	elem是一个左值，获取它的右值。
	反正在dest位置上，获取elem位置开始的右值来构造size个

	*/
	cin >> a;
	return 0;
}


