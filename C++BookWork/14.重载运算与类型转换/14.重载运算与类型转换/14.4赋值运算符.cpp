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
��ֵ��Ҫ�ǳ�Ա

��ƪ��
����˿�����ֵ���ƶ���ֵ������ ʹ�ñ��������Ϊ�Ҳ���������磺�������ڡ�
Ҳ�����������Լ���������С�

��ͬ���� ����������ֵ

note:���ǿ������ظ�ֵ������������βε�������ʲô�������ǳ�Ա����

�������ϸ�ֵ�����
1.���ǵ�����ĳ�Ա��������Ϊ��������ڲ�
2.Ϊ�����������͵ĸ��ϸ�ֵ����һ�£�ҲҪ�����������������
*/
int main()
{
	int a;
	StrVec sv1;
	sv1 = { "asdf","dsfds","zcv" };
	sv1.printStrVec();

	// ��ϰ
	Sales_data sd1;
	sd1 = string("123123");
	cout << sd1.isbn() << sd1.getrevene() << endl;

	Sales_data sd2;
	sd2 = { "adsfad-sfasdf-asdfas",10,23 };
	print(cout, sd2);
	/*
	14.20 ok

	*14.21 ��һ�£�+= ���� +,�ɶ��Բû��ok��

	14.22 ok

	14.23 ok

	14.24 ������ֵ��Ҫ���ƶ���ֵ����Ҫ��û�����ģ�û��д ok

	14.25 ����Ҫ�����ŵİɣ�����д ok
	*/
	cin >> a;
	return 0;
}