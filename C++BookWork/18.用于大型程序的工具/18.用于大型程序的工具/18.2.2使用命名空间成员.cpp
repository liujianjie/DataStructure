#include <iostream>
#include <vector>
#include <fstream>
#include "cplusplus_primer.h"
#include "cplusplus_primer_cpp.h"
#include "TestHeadAndUsing.h"
using namespace std;


namespace A {
	int i = 9, j = 8;
}
void f() {
	using namespace A;// �������������������
	cout << i*A::j << endl;
}
namespace blip {
	int i = 16,j = 15, k = 23;
}
int j = 0;
void mainp() {
	using namespace blip;
	++i;
	//++j;// ����ȷ
	++::j;
	++blip::j;
	int k = 823;
	++k;
}

namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;
//using Exercise::dvar;
//using Exercise::ivar;
//using Exercise::limit;
//using namespace Exercise;
void manip() {
	//using Exercise::dvar;
	//using Exercise::ivar;
	//using Exercise::limit;
	using namespace Exercise;
	double dvar = 3.1416;
	cout << dvar << endl;
	int iobj = limit + 1;
	//++ivar;
	++::ivar;
}
int main()
{
	int a;
	namespace cpl = cplusplus_primer;
	cout << cpl::outmember << endl;

	namespace cp2 = cplusplus_primer::QueryLib;
	cout << cp2::QueryLibmem << endl;

	// 
	f();
	//cout << v1 << endl;
	TestHeadAndUsing t1;
	t1.TestOutMsg();

	manip();
	/*
	��ϰ��
	18.15:
	������ͬ
	�����ǵ���
	ָʾ������
	18.16��
	����
	λ��1.
	ivar�ض����,����ȥ��һ��
	iobj = 1001
	ivar 
	ivarΪû��ȥ�����Ǹ�
	λ��2
	ivar���ڲ�����
	iobj 
	dvar������
	++::ivarʹ��ȫ�ֵ�

	λ��1.
	ivarû���ض���
	iobj = 1001
	ivar ����ȷ
	ivar��ȫ�ֵĲ��������ռ��
	λ��2
	ivarû���ض���
	dvarû���ض��壬��Ϊָʾ������������
	iobj = 1001
	++ivar; ����ȷ
	++::ivarʹ��ȫ�ֵ�

	*/
	cin >> a;
	return 0;
}
