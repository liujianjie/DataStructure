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

template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest)
{
	cout << "void foo(const T &t, const Args& ... rest)" << endl;
	cout << sizeof...(Args) << endl;// 类型参数
	cout << sizeof...(rest) << endl;// 函数参数
}
int main()
{
	int a;

	int i = 0; double d = 3.14; string s = "how now borwn cow";
	foo(i, s, 42, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("hi");
	/*
	练习：
	数目，类型参数的数目和函数参数的数目是一样的
	*/
	cin >> a;
	return 0;
}


