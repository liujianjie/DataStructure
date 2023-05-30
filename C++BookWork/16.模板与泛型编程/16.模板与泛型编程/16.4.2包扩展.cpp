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
#include "Sales_data.h"
#include "Blob.h"
#include "DebugDelete.h"
#include "NoDefault.h"
using namespace std;

template<typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t;// 打印最后一个并且结束
}

template<typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
	os << t << ",";
	return print(os, rest...);
}

template<typename... Args>
ostream &errorMsg(ostream &os, const Args&... rest)
{
	return print(os, debug_rep(rest)...);// 扩展是生成以逗号分开的列表，不是执行语句！
	//cout << (debug_rep(rest)...) << endl;
	//return print(os, debug_rep(rest...));// 还可以吧debug_rep(a1,a2,a3,a4);
}

template <typename T>
string debug_rep(const T &t)
{
	cout << "debug_rep(const T &t)" << endl;
	ostringstream ret;
	ret << t;
	return ret.str();// 返回副本
}

template <typename T, typename T2, typename T3>
string debug_rep(const T &t, const T2 &t2, const T3 &t3)
{
	cout << "debug_rep(const T &t)" << endl;
	ostringstream ret;
	ret << t;
	return ret.str();// 返回副本
}
int main()
{
	int a;
	int v1 = 3; double v2 = 323.23; string v3 = "i feel good";
	errorMsg(cout, v1, v2, v3);

	//initializer_list<string> il{};
	/*
	练习：
	16.56:ok
	16.57:
	这个：麻烦，代码量多，但是可以接受任何类型
	198的：只能一种类型，简洁
	*/
	cin >> a;
	return 0;
}


