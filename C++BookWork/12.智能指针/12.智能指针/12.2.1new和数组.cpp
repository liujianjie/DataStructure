#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
/*
����һ�������õ�һ��Ԫ�����͵�ָ��
1.�� ��̬���飬�������������������

pֻ��ָ��һ�������������Ԫ��

// ����ָ��Ͷ�̬����
// 1.���Թ���new����������unique_ptr�汾
unique_ptr<int[]> up1(new int[10]);
//up1.release();// ���Զ�ʹ��delete[]

// ���ҿ������±���������е�Ԫ��

shared_ptr
1.��ֱ��֧�ֹ���̬���飬������Ҫ�Զ���ɾ����
2.���ṩ�±���������Ԫ�أ�����get�Ȼ�ȡ����ָ���ٲ���
*/
char* lian1(const char *c1, const char *c2)
{
	
	// ��strcpy ��strcat���Ǳ�׼��
	int sizes1 = strlen(c1);
	int sizes2 = strlen(c2);;
	char *cptr1 = new char[sizes1 + sizes2 + 1];
	strcpy(cptr1, c1);
	strcat(cptr1, c2);
	cout << sizes1 << endl;
	cout << sizes2 << endl;
	//for (size_t i = 0; i != sizes1; ++i) {
	//	cptr1[i] = c1[i];
	//}
	//for (size_t i = 0; i != sizes2; ++i) {
	//	cptr1[sizes1 + i] = c2[i];
	//}
	//cout << *cptr1 << endl;
	return cptr1;
}
char* lian1load(string c1, string c2)
{
	int sizes1 = c1.length();
	int sizes2 = c2.length();
	char *cptr1 = new char[sizes1 + sizes2 + 1];
	strcpy(cptr1, (c1+c2).c_str());
	/*for (size_t i = 0; i != sizes1; ++i) {
		cptr1[i] = c1[i];
	}
	for (size_t i = 0; i != sizes2; ++i) {
		cptr1[sizes1 + i] = c2[i];
	}*/
	//cout << sizes1 << endl;
	//cout << sizes2 << endl;
	return cptr1;
}
int main()
{
	int a;
	int *pia1 = new int[4];// pia1ָ���һ��int����Ҫ�����δ�С����һ��Ҫ����

	typedef int arrT[42];
	int *pia2 = new arrT;//new����һ��int���飬���ҷ���ָ���һ��int��ָ��

	// ��ʼ����̬�����������飬new����Ķ��󣬿���Ĭ�ϳ�ʼ����ֵ��ʼ��
	int *pia3 = new int[10];
	int *pia4 = new int[10]();
		
	// ���Գ�ʼ���б�
	int *pia5 = new int[10]{ 0,1,2,3,4,5,6 };
	// ��ʼ�����Ի�ϣ�ǰ4����ʼ������ʼ��ʣ�µ�ֵ��ʼ��
	string *pia6 = new string[10]{ "a","an","the",string(3,'x') };
	cout << *pia6 << endl;
	string *pia7 = pia6;
	// ���ɴ���������С

	//��̬����һ���������ǺϷ��Ĳ��ҿ���ʹ���±�Ϊ0��Ԫ�أ������ܽ�����
	//char arr[0];// ���ܶ��峤��Ϊ0������
	char *cp1 = new char[0];//������һ����̬����һ��������
	// ����β��ָ��һ�������Խ��бȽϲ������ɼӼ�0��

	// �ͷŶ�̬����
	//delete pia6;//����� δ����� �������룺ֻɾ����һ��Ԫ�ذɣ� �������ٵ�һ��Ԫ�ز��Ҳ�ָ�����������Ի���ʲ���������������Ȼ���ڳ��˵�һ��λ�õ�

	//cout << pia7[3] << endl;
	//cout << pia4[0] << endl;
	// pia4ֻ��ָ��һ�������������Ԫ��
	delete []pia5;

	// ����ָ��Ͷ�̬����
	// 1.���Թ���new����������unique_ptr�汾
	unique_ptr<int[]> up1(new int[10]);
	//up1.release();// ���Զ�ʹ��delete[]

	// ���ҿ������±���������е�Ԫ��
	for (size_t i = 0; i != 10; ++i) {
		up1[i] = i;
	}

	shared_ptr<int> sp1(new int[10], [](int *p) {delete[] p; });
	for (size_t i = 0; i != 10; ++i) {
		*(sp1.get() + i) = i;
	}
	cout << "--------------" << endl;
	// ��ϰ ��֪����ôŪ��
	char *cp2 = lian1("12345678","1234567asdfazzz");
	//for (int i = 0; i != strlen(cp2)-2; ++i) {
	//	cout << cp2[i];
	//}
	cout << cp2 << endl;
	char *cp3 = lian1load("zvzxzx", "sadfasdfzzzzzzxcvxc");
	cout << cp3 << endl;
	//for (int i = 0; i != strlen(cp3); ++i) {
	//	cout << cp3[i];
	//}
	//cout << endl;
	delete[] cp2;
	delete[] cp3;

	char c1;
	int i = 0;
	char *cp4 = new char[10];
	//while (cin.get(c1)) {
	//	if (i < 10) {
	//		cp4[i] = c1;
	//	}
	//	else {
	//		cerr << "out range" << endl;
	//		break;
	//	}
	//	i++;
	//}
	//cp4[i] = 0;// ���Ǹ�ɶ�ģ�
	//cout << cp4 << endl;

	delete[]cp4;

	int *pa = new int[10];
	 delete []pa;

	cin >> a;
	return 0;
}
