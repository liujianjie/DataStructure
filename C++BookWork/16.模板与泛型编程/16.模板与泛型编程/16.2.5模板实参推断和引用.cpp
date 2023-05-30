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

// �����ܷ�ȷ��TΪint����Ϊint&
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
	//f1(5);// ������ֵ

	// const T&,T Ĭ��const����ʡ��const
	f2(i);
	f2(ci);
	f2(42);// �۵�Ϊconst int& TΪint

	cout << "f3()" << endl;
	// T&&
	f3(i);// TΪint&
	//f3(ci);// TΪconst int&
	f3(42);// TΪint

	// f3<int&>(int& &&);
	f3<int&>(i);

	cout << "four:��������û������� int&��int" << endl;
	int i2 = 4;
	const int ci2 = 12;
	const int &&i3 = 23;
	f(i2);// ΪʲôѡT&&�汾,�۵���ת��const������
	f(ci2);// ѡ�ڶ���
	f(42);// ѡ��һ��
	f(std::move(i3));// ѡ��һ������֪��Ϊʲô
	f(static_cast<const int&&>(i3));// ѡ��һ������֪��Ϊʲô

	// ��const��ֵT����int
	ctf(static_cast<const int&&>(i3));

	int a1 = 43,a2=32;
	//vector<int&> v2;

	/*
	��ϰ��
	16.42:
	a����ֵ��b��const��ֵ��c����ֵ
	a.int&,(int& )
	b.const int&,(const int&)
	c.int ����Ϊ(int&&)

	16.43:
	i = ci ��һ����ֵ ��
	T:int&

	16.44��
	T��
	a.int int
	b.int int 
	c.int int// ��ȷ��,����˵����int
	
	const T&:
	a.int,(const int &)
	b.int,(const int &)
	c.int&&,(const int &)

	16.45��
	TΪint��vector<int> v;
	TΪint&,vector<int&> v;// �ǷǷ��Ķ���vector
	*/
	cin >> a;
	return 0;
}


