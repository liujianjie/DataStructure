#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>
#include <list>
#include <string> 
#include <memory>
#include "DebugDelete.h"
#include "NoDefault.h"
using namespace std;

/*

*/
template <typename T1, typename T2, typename T3>
void sum2(T2, T3)
{
}
template <typename T1,typename T2,typename T3>
T1 sum(T2, T3)
{
	T1 t = 2;
	return t;
}

template <typename T1, typename T2, typename T3>
T3 sum3(T2, T1)
{
	T3 t = 2;
	return t;
}
template <typename T1>
void compare2(T1, T1)
{
}

template <typename T1>
int compare(const T1 &v1, const T1 &v2)
{
	return 0;
}
int main()
{
	int a;
	//sum2(12, 43);// 要
	auto val3 = sum<long long>(12, 43);// long long sum(int, int);
	//auto val4 = sum3<long long>(1, 2);// 必须显示的每个实参了
	NoDefault n1(2);
	auto val4 = sum3<long long, long, long>(1, 2);
	//sum3<long long, long, long>(1, n1);// n1不能转换为long

	// 以显示指定的实参为主，可以正常的类型转换
	long lng = 23;
	compare2<long>(lng, 1024);// long long
	compare2<int>(lng, 1024);// int int

	// 16.37
	int at = 12;
	double bd = 123.3;
	max<double>(at,bd);

	int *in1 = new int(32);
	shared_ptr<int*> sdp1 = make_shared<int*>(in1);

	// 16.39
	compare<const char*>("sdf","sdfsd");


	/*
	练习：
	16.37：可以，显示指定double即可，int可以转换double 向上转 安全
	16.38:用来指定返回的共享指针的实例化类型。不分配就不知道要分配的大小。// 网上的。
	16.39:显示指定const char*指针即可

	*/

	cin >> a;
	return 0;
}


