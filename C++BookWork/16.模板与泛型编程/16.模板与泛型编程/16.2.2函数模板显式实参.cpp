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
	//sum2(12, 43);// Ҫ
	auto val3 = sum<long long>(12, 43);// long long sum(int, int);
	//auto val4 = sum3<long long>(1, 2);// ������ʾ��ÿ��ʵ����
	NoDefault n1(2);
	auto val4 = sum3<long long, long, long>(1, 2);
	//sum3<long long, long, long>(1, n1);// n1����ת��Ϊlong

	// ����ʾָ����ʵ��Ϊ������������������ת��
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
	��ϰ��
	16.37�����ԣ���ʾָ��double���ɣ�int����ת��double ����ת ��ȫ
	16.38:����ָ�����صĹ���ָ���ʵ�������͡�������Ͳ�֪��Ҫ����Ĵ�С��// ���ϵġ�
	16.39:��ʾָ��const char*ָ�뼴��

	*/

	cin >> a;
	return 0;
}


