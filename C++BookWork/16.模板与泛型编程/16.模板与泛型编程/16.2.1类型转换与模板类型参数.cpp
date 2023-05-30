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
template <typename T> 
T fobj(T a, T) 
{
	cout << "T fobj(T, T) " << endl;
	return a;
}

template <typename T>
int compare(const T& v1, const T &v2)
{
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}

template <typename T, typename U>
int compare2(const T& v1, const U &v2)
{
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}

template<typename T> 
ostream &prints(ostream &os, const T &obj)
{
	return os << obj;
}

template <typename T>
int compare3(const T& v1, const T &v2)
{
	cout << "v1:" << v1 << ",v2:" << v2 << endl;
	return 0;
}
template <typename T>
T fref(const T& a, const T& b)
{
	cout << "T fref(const T&, const T&) " << endl;
	return a;
}

template <typename T> T calc(T a, int)
{
	T t = a;
	return t;
}
template <typename T> T fcn(T a, T b)
{
	T t = a;
	return t;
}

template <typename T> 
void f1(T a, T b)
{
	int *i = new int(2);
	a = i;
	b = i;
}
template <typename T1, typename T2> 
void f2(T1 a, T2 b)
{
	int *i = new int(2);
	a = i;
	b = i;
}
void print() 
{
}
//int[] testch() {
//	return char[];
//}
int main()
{
	int a;
	string s1("a vale");
	const string s2("s2");
	fobj(s1, s2);// ����const����
	fref(s1, s2);// constת��

	int ia[10], ib[23];
	fobj(ia, ib);// f(int*
	//fref(ia, ib);// ����2���������������ͣ�������fobjһ��ת��ָ��
	fobj("sadfas","sadfasdsfsd");// c����ַ������������飨����const char*�����ﵱ�������飬��TΪconst char*

	// ����
	long lng;
	//compare(lng, 1042);
	compare2(lng,1023);

	// ����
	prints(cout, 42);
	ofstream fs("output.txt");
	prints(fs, 10);

	cout << endl;

	//char d[6] = "12345";

	//compare3("hi","world");
	const char c1[] = "abcde";
	const char c2[] = "fghdj";
	//compare3("abcde", "world");
	int it1[] = {0,1,3};
	int it2[] = {1,2,3};
	compare3(c1, c2);
	compare3(it1, it2);
	//fref(c1, c2);

	const char(&ct1)[6] = c1;
	cout << ct1 << endl;

	double d = 1; float f = 1; char c = 'g';
	calc(c, 'c');
	calc(d, f);
	fcn(c, 'c');
	//fcn(d, f);

	string *st1 = new string("abcde");
	string *st2 = new string("qwert");
	compare3(st1, st2);

	//fobj(print, print);
	compare3(print, print);

	int i = 0, j = 42, *p1 = &i, *p2 = &j;
	const int *cp1 = &i, *cp2 = &j;
	f1(p1, p2);
	f2(p1, p2);
	f1(cp1, cp2);
	f2(cp1, cp2);
	//f1(p1, cp1);
	f2(p1, cp1);
	/*
	��ϰ��
	16.32:
	�Ӻ���ʵ�ε�ģ�����
	�����ͽ���ת��һЩ������ƥ��ƥ��

	16.33:
	const
	���鵽ָ�룬���ǲ�������

	16.34:
	a�Լ��ģ�.���Ϸ������鲻��ת��Ϊָ�룬��Ϊ�β�������
	a. ���Ϸ���˵ʲô���Ȳ�ƥ�䣬����Ϊchar[4],char[7],������
	b. �Ϸ�

	16.35:
	a.�Ϸ�������ת��
	b.�Ϸ���֧������ת��
	c.�Ϸ�
	d.���Ϸ�����ͬ

	16.36:
	a.TΪint*
	b.T1��T2λint*
	c.TΪ int*
	d.T1,T2  int*
	e.����ִ��ʵ�ε������Ƿ���ͬ
	f.T1 int* ��T2�� int*
	*/

	cin >> a;
	return 0;
}


