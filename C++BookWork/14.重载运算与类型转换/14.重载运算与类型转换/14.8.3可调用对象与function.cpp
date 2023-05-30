#include <iostream>
#include "String.h"
#include <map>
#include "Sales_data.h"
#include "StrVec.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Employee.h"
#include <memory>
#include <functional>
#include "NewClass1432.h"
using namespace std;

/*
������
�����һ�����ɵ��õĶ���Ҳ�����͡�����������ָ����������䷵��ֵ���ͺ�ʵ�����;���

���⣺������ͬ���͵Ŀɵ��ö�����ܹ���ͬһ�� ������ʽ��
������ʽ��ָ�����ص����ͺ�ʵ�����͡�
һ�ֵ�����ʽ��Ӧһ����������

������ͬ���Ϳ��ܾ�����ͬ�ĵ�����ʽ
����һ�����������洢ָ����Щ�ε��ö���� ��ָ�롱��������Ȼ������ʽһ�����������Ͳ�һ����
add�Ǻ���ָ�룬lambda���Լ���������

������׼��function����
// Ϊ����������⣬function��׼�����ͣ����Դ洢ͬһ�ֵ�����ʽ�ĺ�����lambda��������

�ġ����صĺ�����function
���ܽ����صĺ�������function��

int(*fp1)(int, int) = overadds;
binops3.insert({ "+",fp1 });// �����ú���ָ�룬��ָ���ض��汾

����ʹ��lambda�������صĺ���

*/
//
int adds(int i, int j) 
{
	return i + j; 
}
struct divide {
	int operator()(int d, int d2) {
		return d / d2;
	}
};
auto mod = [](int i, int j) { return i % j; };

double overadds(double i, double j)
{
	return i + j;
}
int overadds(int i, int j)
{
	return i + j;
}
int main()
{
	int a;

	// ��Ϊ������ʽ��һ�������Կ���ʹ��int(*)(int,int)��ʽ�洢
	map<string, int(*)(int, int)> binops;
	binops.insert({ "+",adds });
	binops.insert({ "%",mod });// ����11�ᱨ��ģ���Ϊlambda��һ��δ����������
	//binops.insert({ "%",divide() });// ��������ָ�벻�ܴ洢������

	// Ϊ����������⣬function��׼�����ͣ����Դ洢ͬһ�ֵ�����ʽ�ĺ�����lambda��������
	function<int(int, int)> f1 = adds;
	function<int(int, int)> f2 = divide();
	function<int(int, int)> f3 = [](int i, int j) {return i * j; };
	cout << f1(4, 2) << endl;
	cout << f2(4, 2) << endl;
	cout << f3(4, 2) << endl;

	map <string, function<int(int, int)>> binops2 = {
		{"+",adds},
		{ "-",std::minus<int>() },
		{ "/",divide() },
		{ "*",[](int i, int j) {return i * j; }},
		{ "%",mod }
	};
	cout << binops2["+"](10, 5) << endl;
	binops2["-"](10, 5);
	binops2["/"](10, 5);
	binops2["*"](10, 5);
	binops2["%"](10, 5);

	// ����
	map <string, function<int(int, int)>> binops3;
	//binops3.insert({"+",overadds});// ����
	int(*fp1)(int, int) = overadds;
	double(*fp2)(double, double) = overadds;
	binops3.insert({ "+",fp1 });// �����ú���ָ�룬��ָ���ض��汾

	cout << "----" << endl;
	string ope;
	cout << "�������" << endl;
	cin >> ope;
	double v1, v2;
	cout << "��������Ҫ�����ֵ" << endl;
	cin >> v1 >> v2;
	cout << binops2[ope](v1, v2) << endl;
	// ��ϰ
	/*
	14.44 ok��û���࣬��һ��map��û��������󣬾�ֱ�ӵĲ���
	*/
	cin >> a;
	return 0;
}