#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <list>
#include <string> 
#include <memory>
#include "DebugDelete.h"
#include "NoDefault.h"
using namespace std;

/*

*/
int main()
{
	int a;
	int *i1 = new int;
	double *d1 = new double;
	
	shared_ptr<int> s1(i1);
	shared_ptr<double> s2(d1, DebugDelete());

	s1.reset(i1, DebugDelete());

	NoDefault *n1 = new NoDefault(2);
	NoDefault *n2 = new NoDefault(24);
	shared_ptr<NoDefault> sp1(n1);
	sp1.reset(n2, DebugDelete());
	cout << n1->val << endl;
	sp1.reset(n1);
	cout << n1->val << endl;

	NoDefault *n3 = new NoDefault(3);
	unique_ptr<NoDefault, DebugDelete> u1(n3, DebugDelete());
	u1.reset();
	/*
	��ϰ��
	16.28:  ��ʱ����д�ɡ�
	��ž�����ģ����ָ���κ����ͣ�һ��������
	ɾ������������ģ�嶨���ģ�������del��ʱ�����ж����Ƿ�Ϊ��
	Ҳ�����ó�Աģ�庯������ָ����

	һ����ģ�壬û�г�Աģ��Ӧ�ø��򵥵㡣
	16.29: 
	
	*/

	cin >> a;
	return 0;
}


