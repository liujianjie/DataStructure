#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <array>
#include "Sales_data.h"
#include "noDefault.h"
#include <string>
using namespace std;
int main()
{
	int a;
	const char *cp = "Hello World!!";// �Կ��ַ���Ϊ����������
	char noNull[] = { 'H','i' };
	string s1(cp);// ֱ�������ַ�
	string s2(noNull, 2);// ����2���ַ�
	string s3(noNull);//δ����û�п��ַ�
	string s4(cp + 6, 5);//��cp[6]��ʼ����5���ַ�
	string s5(s1, 6, 5);// ��s1[6]��ʼ����5���ַ�
	string s6(s1, 6);// ��s1[6]��ʼ����ֱ��ĩβ
	//string s7(s1, 16);// ��ʼ�±겻�ܴ���length �쳣 out_of_range

	string s8("hello world");
	string s9 = s8.substr(0, 5);
	string s10 = s8.substr(6);
	string s11 = s8.substr(6, 11);
	//string s12 = s8.substr(12);// �쳣

	// ��ϰ
	// 9.4.1
	vector<char> v1{'1','2','3' ,'4' ,'5' ,'6' ,'7','8','9' };
	string s12(v1.begin(), v1.end());
	cout << s12 << endl;

	cin >> a;
	return 0;
}