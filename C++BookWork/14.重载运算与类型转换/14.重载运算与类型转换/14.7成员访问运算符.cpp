#include <iostream>
#include "String.h"
#include "Sales_data.h"
#include "StrVec.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Employee.h"
#include <memory>
#include "NewClass1432.h"
using namespace std;

/*
*��->

��ͷ�������������ĳ�Ա��������ͨ��Ҳ�ǲ������Բ���
->����string��ָ��

�����Լ�ͷ���������ֵ���޶�
��Զ���ܶ�����Ա�������������ĺ���?

���صļ�ͷ��������뷵�����ָ������Զ����˼�ͷ�������ĳ����Ķ���

���ã�
*point.��ָ���������ĳ�Ա
point->()->��ָ���������ĳ�Ա

*/
int main()
{
	int a;

	StrBlob a1 = { "hi","bye","now" };
	StrBloPtr p1(a1);
	cout << (*p1) << endl;

	cout << *(p1.operator->()) << endl;
	
	*p1 = "okays";
	cout << p1->size() << endl;// ��Ԫ�صĴ�С
	cout << (*p1).size() << endl;

	int val1 = 32;
	int &val2 = val1;
	int *it1 = new int(val2);
	int &r1 = *it1;
	int *it3 = &r1;
	int &it2 = r1;
	cout << it2 << endl;
	*it1 = 43;
	cout << it2 << endl;
	cout << val1 << endl;
	cout << "----------" << endl;

	StrBlob sb1 = {"12321","34324","23423"};
	StrBloPtr sp1(sb1);
	NewClass1432 nc1(sp1);

	NewClass1432 *nc2 = &nc1;

	cout << (*nc1).deref() << endl;
	cout << (nc1.operator->()->deref()) << endl;

	cout << (nc1->deref()) << endl;

	cout << (*nc2).operator*().deref() << endl;
	// ��ϰ
	/*
	14.30 û��
	14.31 �������Զ�����
		��������Ļ���

	14.32

	*/

	cin >> a;
	return 0;
}