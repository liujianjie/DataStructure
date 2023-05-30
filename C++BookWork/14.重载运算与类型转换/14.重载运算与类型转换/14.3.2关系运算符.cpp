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
��ƪ��
������������������ͨ��Ҳ������ϵ�������������������ҪС�������

��ϵ�����Ӧ�ã�
1.����˳���ϵ������������жԹؼ��ֵ�Ҫ��һ��
2.�����ͬʱҲ����==�����������һ�ֹ�ϵ������==����һ�¡�������������ǣ�=�ģ���ôһ������Ӧ��<����һ��

Sales_data��Ӧ�ö���<���������߼��ɿ���<���壬������<Ҳ�����

��Ϊ�Ƚ�isbn������������Ա������Ҫ��2
������isbn�Ƚ�
��д�ˣ�isbn��ͬ��������������Ա��ͬ�ǲ���ȵģ��ж����
ʵ�������: �����κ�һ����������һ��С�������������

������Ƚ�Ҳ���У���Ϊʵ�������ı�˳��

note����Ҫ����Ψһһ�ֿɿ���<����



*/
int main()
{
	int a;
	string s1("aa");
	string s2("aaa");
	cout << (s1 < s2) << endl;

	cout << "StrVec:" << endl;
	StrVec sv1, sv2;
	sv1.push_back("a");
	sv1.push_back("a");
	sv1.push_back("a");
	sv1.push_back("a");

	sv2.push_back("a");
	sv2.push_back("a");
	sv2.push_back("b");

	cout << (sv1 < sv2) << endl;
	cout << "StrVec:" << endl;

	String str1("a"), str2("aaa");
	cout << (str1 < str2) << endl;

	cout << endl;
	StrBlob sbb1, sbb2;
	sbb1.push_back("a");
	sbb1.push_back("a");
	sbb1.push_back("a");
	sbb1.push_back("a");
	//sbb1.push_back("a");

	sbb2.push_back("a");
	sbb2.push_back("a");
	sbb2.push_back("a");
	sbb2.push_back("b");
	cout << (sbb1 < sbb2) << endl;


	StrBloPtr sbp1(sbb1), sbp2(sbb2);
	cout << (sbp1 < sbp2) << endl;


	// ��ϰ
	/*
	14.18 StrBlobPtr ��֪���ǲ������� 
	14.19 �޷��ȣ���Ϊ�� ���� ������׼��2
	*/
	cin >> a;
	return 0;
}