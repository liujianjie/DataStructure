#include <iostream>
#include "String.h"
#include "Sales_data.h"
#include "StrVec.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Employee.h"
#include <memory>
using namespace std;

/*
����Ҫ���������ĳ�Ա�����ı�������������������״̬������Ϊ��Ա����
����ǰ��汾��Ӧ��ͬʱ����

һ������ǰ�õ������ݼ������
ǰ�ã�
�����ð汾һ�£�Ӧ�÷��ص�����ݼ�����������

��������ǰ�������
����ʹ��һ������������ʹ�õ� һ�������
���ã�
���ص��Ƕ����ԭֵ��������ݼ�֮ǰ��ֵ��������

������ʾ�ص��ú��������


*/
int main()
{
	int a;
	StrBlob a1;
	StrBloPtr p1(a1);
	//p1.operator++(0);//�ز�����
	//p1.operator++();

	StrBlob a2,a3;
	a2.push_back("you");
	a2.push_back("and");
	a2.push_back("lov2e");
	a3.push_back("me");
	a3.push_back("love");
	StrBloPtr p2(a2),p3(a2);
	p2 = p2 + 2;
	cout << p2.deref() << endl;
	p2 -= 1;
	cout << p2.deref() << endl;
	//p2 -= 3;
	//cout << (p2 + 3).deref() << endl;
	/*
	��ϰ
	14.27:ok
	14.28��
	14.29����Ϊ��ı�����ѽ
	*/

	cin >> a;
	return 0;
}