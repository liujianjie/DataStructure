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

// ���� T&& �Ƿ񱣳�const ���ǵĻᣬ

template <typename F,typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
	f(t1, t2);
}
template <typename F, typename T1, typename T2>
void flip2(F f, T1&& t1, T2&& t2)
{
	f(t1, t2);
}

template <typename F, typename T1, typename T2>
void flip3(F f, T1&& t1, T2&& t2)
{
	f(std::forward<T1>(t1), std::forward<T2>(t2));
}


void f(int &v1, int v2)
{
	cout << ++v1 << " " << v2 << endl;
}
void g(int &v1, int&& v2)
{
	cout << ++v1 << " " << ++v2 << endl;
}

void p1(int &v1, const int& v2)
{
	cout << ++v1 << " " << v2 << endl;
}
int main()
{
	int a;

	int j = 1;
	flip1(f,j,42);
	cout << j << endl;// ����ı䣬��ΪT1��int��t1ֻ��j�Ŀ�������������

	flip2(f, j, 42);
	cout << j << endl;// ��ı�,T��int&��

	//int v1 = 32;
	//int &&v2 = v1;
	// �޷�������2��intת����int&&,��Ϊ������ int&& t2,������ģ��������ֵ�ˣ��޷�int &&a = b��
	// �޷�����ֵ�󶨵���ֵ��
	//flip2(g, j, 41);
	flip3(g, j, 41);// ����

	//std::forward<Type> ��type����&&����typeΪ&�� && &�۵�Ϊ&����typeΪint����&& Ϊint&&

	//flip3(g, j, j);// jΪ��ֵ��TΪint&
	// ����ֵ�����Ƿ��ı䣿
	int jj2 = 12;
	int &jj3 = jj2;
	flip3(g, j, std::move(jj3));
	cout << jj3 << endl;// ��ı�ԭ����ֵ������
	int jj4 = 10;
	int &&jj5 = move(jj4);
	jj5 = 11;
	cout << jj5 << endl;
	cout << jj4 << endl;

	// �Լ�д��p1����
	const int j2 = 32;
	int j3 = 48;
	flip3(p1, j, j2);// T2Ϊconst int&,forward��const int& &&,����const int& ����
	flip3(p1, j, j3);// T2Ϊ int&,forward�� int& &&,���� int& ����ת��const int&
	/*
	��ϰ��
	16.47: ok
	*/
	cin >> a;
	return 0;
}


