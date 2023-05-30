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

template<typename T,typename... Args>
ostream &print(ostream &os, const T &t,const Args&... rest)
{
	os << t << ",";
	return print(os,rest...);
}



int main()
{
	int a;

	int i = 0; double d = 3.14; string s = "how now borwn cow";
	short b = 12;
	float ft = 13.43;
	print(cout,i,s,d,b,ft);

	Sales_data sd1;
	//print(cout, sd1, s, d, b, ft);
	/*
	练习：
	16.53:ok
	16.54:失败
	16.55：本来是无限递归并报错的，但是并没有，不知道为什么
	*/
	cin >> a;
	return 0;
}
template<typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t;// 打印最后一个并且结束
}

