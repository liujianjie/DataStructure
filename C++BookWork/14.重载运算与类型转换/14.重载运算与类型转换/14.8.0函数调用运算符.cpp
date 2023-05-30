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

struct absInt {
	int operator()(int val)const {
		return val < 0 ? -val : val;
	}
};
class PrintString {
public:
	PrintString(ostream &o = cout, char  c = ' '):
		os(o),sep(c){}
	void operator()(const string &s)const { os << s << sep; }
	void operator()(const int &s)const { os << s << sep; }
private:
	ostream &os;
	char sep;
};
class Partice1 {
public:
	int operator()(const int& a1, const int &a2, const int &a3) {
		if (a1 > 5) {
			return a1;
		}
		else if (a2 > 5) {
			return a2;
		}
		return a3;
	}
};

class Partice2 {
public:
	Partice2(istream& o = cin):
		is(o) {

	}
	string& operator()() {
		if (is >> s && s != "-1") {
			return s;
		}
		return zeros;
	}
private:
	istream& is;
	string s;
	string zeros;
};
class Partice3 {
public:
	Partice3(istream& o = cin) :
		is(o) {
	}
	string& operator()() {
		while (is >> s && s != "-1") {
			ve.push_back(s);
		}
		return zeros;
	}
	vector<string> ve;
private:
	istream& is;
	string s;
	string zeros;
};
class Partice4 {
public:
	Partice4(){}
	Partice4(int val):val(val){}
	bool operator()(const int &a1) {
		return a1 == val;
	}
private:
	int val;
};
/*
��ƪ������
��ʹ�ú���һ��ʹ�ø���Ķ�����Ϊ����Դ洢״̬������ͨ���������

Ҫ�㣺
1�������ǳ�Ա����
2.���Զ�������ͬ�汾�ĵ��������
3.�ඨ���˵�������������Ķ����������������Ϊ����һ��

��������״̬�ĺ����Ķ�����
���������԰���������Ա�����������ݳ�Ա

1.ͨ�����ڷ����㷨��ʵ��


*/
int main()
{
	int a;
	absInt abs1;
	int val1 = abs1(-1);
	cout << val1 << endl;

	// ʹ��printstring������ʹ��Ĭ��ֵ��Ҳ����ָ��ֵ
	string s = "try to print";
	PrintString printer;
	printer(s);
	PrintString printer1(cerr, '\n');
	printer1(s);

	// 
	vector<string> ve1{"adf","dfds","zv","bvc"};
	for_each(ve1.begin(),ve1.end(), PrintString(cerr, '\n'));

	cout <<"---------" << endl;

	Partice1 pt1;
	cout << pt1(1, 2, 3) << endl;
	cout << pt1(6, 7, 3) << endl;
	cout << pt1(2, 7, 3) << endl;

	Partice2 pt2;
	//cout << pt2() << endl;

	Partice3 pt3;
	//pt3();
	//cout << pt3.ve.size() << endl;

	vector<int> v1{3,3,23,212,21,32,3,65,3,34};
	replace_if(v1.begin(),v1.end(),Partice4(3),110);

	for_each(v1.begin(),v1.end(), PrintString(cerr, '\n'));
	// ��ϰ
	/*
	14.33 �ͺ����Ĳ�����һ���ࣿ
	14.34 ok
	14.35 ok
	14.36 ok
	14.37 ok
	*/

	cin >> a;
	return 0;
}