#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <list>
#include <string> 
#include <memory>
#include <type_traits>
#include <climits>
#include "Blob.h"
#include "DebugDelete.h"
#include "NoDefault.h"
using namespace std;

template <typename T>
string debug_rep(const T &t)
{
	cout << "debug_rep(const T &t)" << endl;
	ostringstream ret;
	ret << t;
	return ret.str();// 返回副本
}
template <typename T>
string debug_rep(T *p)
{
	ostringstream ret;
	ret << "pointer:" << p;
	if (p)
		ret << " " << debug_rep(*p);// ??*p得到的是指向的值，就相当于调用debug_rep(s1)选择第一个版本，再返回
	else
		ret << "null pointer";;
	return ret.str();// 返回
}
// 没有声明
//string debug_rep(const string &);
string debug_rep(char *p)
{
	return debug_rep(string(p));
}
string debug_rep(const char *p)
{
	return debug_rep(string(p));
}
string debug_rep(const string &s)
{
	return '"' + s + '"';
}
template<typename T>
void f(T)
{
	cout << "f(T)" << endl;
}
template<typename T>
void f(const T*)
{
	cout << " f(const T*)" << endl;
}
template<typename T>
void g(T)
{
	cout << " g(T)" << endl;
}
template<typename T>
void g(T*)
{
	cout << " g(T*)" << endl;
}
int main()
{
	int a;
	string s1("1312");
	cout << debug_rep(s1) << endl;

	cout << debug_rep(&s1) << endl;// 第二个版本更特例化，第一个版本需要进行const指针转换

	// 二
	const string *s2 = &s1;
	cout << debug_rep(s2) << endl;// 还是第二个版本，虽然需T需要转换到const string，但是特例化。

	//
	cout << debug_rep(s1) << endl;// 非模板

	// 
	cout << debug_rep("c hi world") << endl;//还是第二个版本，特例
	// 可以强转，为我们需要的非模板函数
	cout << "--------------" << endl;
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42); f(42);
	g(p); f(p);
	g(ci); f(ci);
	g(p2); f(p2);

	/*
	练习：
	16.48:

	16.49:
	g(42):g(T)
	f(42):f(T)
	g(p): g(T*)
	这个错了，不知道为什么不选这个，选T，因为要const转换吗？
	但第一个也要T转为int*呀，第二个T转为int，但p不是const
	f(p); f(cont T*)
	g(ci):g(T)
	f(ci):f(T)
	g(p2):g(T*)
	f(p2):f(const T*)
	*/
	cin >> a;
	return 0;
}


