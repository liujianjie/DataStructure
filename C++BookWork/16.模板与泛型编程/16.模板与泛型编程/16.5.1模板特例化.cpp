#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <list>
#include <string> 
#include <memory>
#include <type_traits>
#include <climits>
#include <unordered_set>
#include "Sales_data.h"
#include "Blob.h"
#include "Foo.h"
#include "DebugDelete.h"
#include "StrVec.h"
#include "NoDefault.h"
using namespace std;

template <typename T>
int compare(const T&,const T&)
{
	cout << "int compare(const T&,const T&)" << endl;
	return 0;
}
template <size_t N,size_t M>
int compare(const char (&)[N], const char (&)[M])
{
	cout << "int compare(const char (&)[N], const char (&)[M])" << endl;
	return 0;
}

// �����ַ�ָ��
template <>
int compare(const char* const &p1, const char* const &p2)
{
	cout << "�������汾" << endl;
	return 0;
}
// ��ģ��
namespace std {
	template<>
	struct hash<Sales_data>
	{
		typedef size_t result_type;// ��ϣֵ��
		typedef Sales_data argument_type;// ��ҪĬ��==������bool
		size_t operator()(const Sales_data& s) const;
	};
}
size_t
hash<Sales_data>::operator()(const Sales_data& s) const
{
	return hash<string>()(s.bookNo) ^
		hash<unsigned>()(s.units_sold) ^
		hash<double>()(s.revenue);
}
bool operator==(const Sales_data& lhs,const Sales_data& rhs) {
	return lhs.bookNo == rhs.bookNo &&
		lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue;
}
template <class T> struct remove_references {
	typedef T type;
};
template <class T> struct remove_references<T&>
{
	typedef T type;
};
template <class T> struct remove_references<T&&>
{
	typedef T type;
};
//template < typename T, typename... Args>
//void psixt(T fv, Args...arg)
//{
//	cout << fv << endl;
//	cout << sizeof...(arg) << endl;
//}

template < typename T,typename T2>
void psixt(T fv, T2& con) 
{
	cout << count(con.begin(), con.end(), fv) << endl;
}

template <>
void psixt(const char* fv,vector<const char*>& con)
{
	cout << "�������汾" << endl;
	cout << count(con.begin(), con.end(), fv) << endl;
}
int main()
{
	int a;
	vector<double> ve1{ 1,2,3,4,5,6,4,4 };
	vector<string> ve2{ "12","12","12","a","b","a"};
	vector<const char*> ve3{ "a","a","a","12","b","a" };
	psixt(4, ve1);
	psixt("12", ve2);
	psixt("a", ve3);

	cout << "-----------" << endl;

	const char *p1 = "hi", *p2 = "mom";
	// ��Ϊ�������������汾�����Բ���ת�����飬������ƥ����
	compare(p1, p2);
	compare("123","asdf");// ���������ԣ������ַ���������İ汾��������

	Sales_data s1("asdfsd-1",3,12);
	Sales_data s2("asdfsd-3", 3, 12);
	Sales_data s3("asdfsd-4", 3, 12);
	Sales_data s4("asdfsd-4", 3, 12);
	Sales_data s5("asdfsd-3", 3, 12);
	Sales_data s6("asdfsd-2", 3, 12);
	Sales_data s7("asdfsd-1", 3, 12);
	Sales_data s8("asdfsd-2", 3, 12);
	Sales_data s9("asdfsd-1", 4, 12);
	unordered_multiset<Sales_data> SDset;
	SDset.insert(s1);
	SDset.insert(s2);
	SDset.insert(s3);
	SDset.insert(s4);
	SDset.insert(s5);
	SDset.insert(s6);
	SDset.insert(s7);
	SDset.insert(s8);
	SDset.insert(s9);
	SDset.insert(s1);
	for (auto be = SDset.begin(), end = SDset.end();be != end ; ++be) {
		cout << (*be).isbn() << endl;
	}
	cout << SDset.size() << endl;

	int v1 = 12;
	int &v2 = v1;
	remove_references<decltype(42)>::type aa;
	remove_references<decltype(v1)>::type b;
	remove_references<decltype(std::move(v2))>::type c;

	Foo<string> fs;
	fs.Bar();
	Foo<int> fI;
	fI.Bar();
	/*
	��ϰ��
	16.62:ok
	16.63:ok
	16.64:ok
	16.65:ok
	16.66:���ػ�ı�ƥ�����ȶȣ����������᣿
	16.67������Ӱ�죬��������ģ��ƥ�����ȶ���ģ�弶��һ�¡�
	��������ģ���ʵ��

	*/
	cin >> a;
	return 0;
}


