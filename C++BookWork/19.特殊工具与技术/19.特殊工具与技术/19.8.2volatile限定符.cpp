#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <functional>
#include "Screen.h"

using namespace std;

class Task {

};

class Foo {
	Foo(const volatile Foo&);// ��һ��volatile������п���
	Foo& operator=(volatile const Foo&);// volatile ���󸳸���volatile����
	Foo& operator=(volatile const Foo&) volatile;// volatile����ֵ��һ��volatile����
};
int main()
{
	int a;

	const int max_size = 20;
	volatile int display_register = 1;// ���ܷ����ı�
	volatile Task *curr_task;// ָ��һ��volatile����
	volatile int iax[max_size];// ÿ��Ԫ�ض���volatile��
	volatile Screen bitmapBuf;// ÿ����Ա����volatile��

	cout << display_register << endl;
	display_register = 2;
	cout << display_register << endl;
	int novo = 3;
	display_register = novo;
	
	volatile int v;
	int *volatile vip;// volatileָ�룬ָ��int
	volatile int *ivp;// ��һ��ָ�룬ָ��volatile int
	// ��һ��volatileָ�룬��ָ��һ��volatile int
	volatile int *volatile vivp;

	//int *ip = &v;// ����
	//vip = &v;// ����
	ivp = &v;
	vivp = &v;


	/*
	��ϰ��
	*/
	cin >> a;
	return 0;
}
