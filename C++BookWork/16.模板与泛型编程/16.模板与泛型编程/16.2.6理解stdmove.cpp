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

// �����ܷ�ȷ��TΪint����Ϊint&
//template <typename T>
//void f(const T& t1)
//{
//	// ��֪��Ϊʲô���������
//	//const int &v1 = 43;
//	// int &&d = v1;
//	// T��&&��t1��const int& Ϊʲô������
//	cout << " f(const T&)" << endl;
//	T t2 = t1;
//	t2 = 1114;
//	if (t2 == t1) {
//		cout << "int&" << endl;
//	}
//	else {
//		cout << "int" << endl;
//	}
//}
//template <typename T>
//void f(T&& t1)
//{
//	cout << " f(T&&)" << endl;
	/*T t2 = t1;
	t2 = 4;
	if (t2 == t1) {
	cout << "int&" << endl;
	}
	else {
	cout << "int" << endl;
	}*/
//}

template <typename T>
typename remove_reference<T>::type&& moves(T&& t)
{
	return static_cast<typename remove_reference<T>::type&&>(t);
}

int main()
{
	int a;
	// ǰһ������
	//cout << "four:��������û������� int&��int" << endl;
	//int i2 = 4;
	//const int ci2 = 12;
	//const int &&i3 = 23;
	//f(i2);// ΪʲôѡT&&�汾,�۵���ת��const������
	//f(ci2);// ѡ�ڶ���
	//f(42);// ѡ��һ��
	//f(std::move(i3));// ѡ��һ������֪��Ϊʲô
	//f(static_cast<const int&&>(i3));// ѡ��һ������֪��Ϊʲô
	int &&ii1 = 223;
	int &ii2 = ii1;
	int i1 = 9, i2;
	i2 = std::move(i1);
	cout << i2 << endl;
	cout << i1 << endl;

	int &&i3 = static_cast<int&&>(i1);
	cout << i3 <<"123"<< endl;

	int i4 = i3;
	cout << i4 << endl;

	int i5 = moves(i3);
	cout << i5 << endl;

	//int &&i7 = i1;// �������޷���һ����ֵ����ֵ��
	int &&i6 = moves(i1);// ������ֵ��������ֵ
	cout << i6 << endl;

	//���ɵ�
	//int &&i7 = &&i6;
	int &&i7 = moves(i6);
	
	/*
	��ϰ��
	16.46:
	elem��һ����ֵ����ȡ������ֵ��
	������destλ���ϣ���ȡelemλ�ÿ�ʼ����ֵ������size��

	*/
	cin >> a;
	return 0;
}


