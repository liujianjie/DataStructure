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
	return ret.str();// ���ظ���
}
template <typename T>
string debug_rep(T *p)
{
	ostringstream ret;
	ret << "pointer:" << p;
	if (p)
		ret << " " << debug_rep(*p);// ??*p�õ�����ָ���ֵ�����൱�ڵ���debug_rep(s1)ѡ���һ���汾���ٷ���
	else
		ret << "null pointer";;
	return ret.str();// ����
}
// û������
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

	cout << debug_rep(&s1) << endl;// �ڶ����汾������������һ���汾��Ҫ����constָ��ת��

	// ��
	const string *s2 = &s1;
	cout << debug_rep(s2) << endl;// ���ǵڶ����汾����Ȼ��T��Ҫת����const string��������������

	//
	cout << debug_rep(s1) << endl;// ��ģ��

	// 
	cout << debug_rep("c hi world") << endl;//���ǵڶ����汾������
	// ����ǿת��Ϊ������Ҫ�ķ�ģ�庯��
	cout << "--------------" << endl;
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42); f(42);
	g(p); f(p);
	g(ci); f(ci);
	g(p2); f(p2);

	/*
	��ϰ��
	16.48:

	16.49:
	g(42):g(T)
	f(42):f(T)
	g(p): g(T*)
	������ˣ���֪��Ϊʲô��ѡ�����ѡT����ΪҪconstת����
	����һ��ҲҪTתΪint*ѽ���ڶ���TתΪint����p����const
	f(p); f(cont T*)
	g(ci):g(T)
	f(ci):f(T)
	g(p2):g(T*)
	f(p2):f(const T*)
	*/
	cin >> a;
	return 0;
}


