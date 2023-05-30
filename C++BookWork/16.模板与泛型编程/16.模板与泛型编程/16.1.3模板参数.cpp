#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <list>
#include <string> 
#include "Sales_data.h"
//#include "BlobAndBloPtr.h"
#include "TestMod.h"
#include "Blob.h"
#include "BloPtr.h"
#include "Foo.h"

using namespace std;

/*

*/
typedef double A;
//template <typename A, int B> void f(A a,const char(&a)[B])
template <typename A, typename B> void f(A a, const int b, B bc)
{
	cout << "template" << endl;
	A tmp = a;
	double B;// ���ᱨ�� c+14
}

//template <typename v, typename v> void f2(v vv)// ���ó�����Ϊû��ƥ��ĵ��ĺ���ʵ��

// ģ������
//template <typename T> int calc(const T&, const T&);
template <typename T> class CC;

template <typename T> T calc(const T&, const T&);

//template<typename T>
//T calc(const T &, const T &)
//{
//	return T();
//}

//�����ģ��������ֲ�����ͬ��������Ҫ��ͬ����������������ɣ����ǿ������е�
template <typename Type> 
Type calc(const Type&, const Type&) 
{ 
	cout << "Type calc(const Type&, const Type&) " << endl;
	return Type(); 
}

// ʹ��������ͳ�Ա
// ��Ҫ��ʾ����Ϊ���� typename ����Ϊ������,
template <typename T>
typename T::value_type top(const T &c)
{
	if (!c.empty())
		return c.back();
	else {
		// 
		typename T::value_type re = 'd';// ͨ��typenameָ��Ϊ���ͣ�Ĭ����ֵ��
		return re;
		//return T::value_type();// ����һ��ֵ��ʼ��Ԫ�ط��ظ�T::value_type����
	}
}
// Ĭ��ģ��ʵ��
template <typename T, typename F = less<T>>
int compare(const T &v1, const T &v2, F f = F())
{
	if (f(v1, v2))return 1;
	if (f(v2, v1))return -1;
	return 0;
}

bool compareIsbn(const Sales_data& s1, const Sales_data& s2)
{
	cout << "compareIsbn(const Sales_data& s1, const Sales_data& s2)" << endl;
	return s1.isbn().size() < s2.isbn().size();
}
// ��ģ����ģ��Ĭ��ʵ��
template <class T = int> class Numbers {
public:
	Numbers(T v = 0) : val(v){}
private:
	T val;
};

template <typename T> void f1(T, int )
{
	cout << "template <typename T> void f1(T, int *)" << endl;
}
template <typename T> void f2(T, T)
{}

// 16.19
template <typename T>
void prints(const T &con)
{
	// size_typeΪ������Ҫָ��Ϊ���Ͳ�ȻĬ��Ϊֵ��size��Ա����Ϊֵ
	typename T::size_type i = 0;
	for (i; i != con.size(); ++i) {
		cout << con[i] << " " << con.at(i) << endl;
	}
}
// 16.20
template <typename T>
void prints2( T &con)
{
	for (typename T::iterator beg = con.begin(), end = con.end();
		beg != end; ++beg) {
		cout << *beg << endl;
	}
}
int main()
{
	int a;
	
	//f(3,"aa");
	const int six = 6;
	f(3, six, 8);
	//f2(5);

	string s("test templates"),s2;
	string::value_type v = string::value_type();
	string::value_type st1 = top(s);
	string::value_type st2 = top(s2);

	// ��value_type()���صģ�����һ��ֵ��ʼ����Ԫ�ظ�value_type
	cout << v << endl;
	cout << st2 << endl;

	// ����β��ֵ
	cout << st1 << endl;

	// 
	Sales_data sd1("sdfsd"), sd2("zxcvzxcv");
	calc(sd1,sd2);

	// Ĭ��ģ��ʵ��
	less<int> le;
	int sval = le(5, 10);
	//sval = le(sd1, sd2);
	cout << sval << endl;
	cout << compare(12, 14) << endl;
	// �����Լ�ָ���Ƚ�����
	//cout << compare(&sd1, &sd2) << endl;// by the way ,��ָ�����ͱȽ����õĴ���
	cout << compare(sd1, sd2, compareIsbn) << endl;

	//
	Numbers<long double> l1;
	Numbers<> l2;// Ĭ������

	f1(5,1);

	vector<int> ve1{1,2,3,4,5};
	vector<int>::size_type i = 0;
	cout << i << endl;
	cout << ve1.size() << endl;
	//auto pr = vector<int>::size();
	//for (int i = 0; i != ve1.size(); ++i) {
	//	cout << ve1[i] << " "<< ve1.at(i)<< endl;
	//}
	/*for (vector<int>::iterator beg = ve1.begin(), end = ve1.end(); beg != end; ++beg) {
		cout << *beg << endl;
	}*/

	prints(ve1);
	prints2(ve1);
	// ��ϰ
	/*
	16.17:
	1.���Ͳ���������û�а�
	1.��ģ���������������͵ĳ�Աʱ����typename������class

	16.18:
	a.�Ƿ���Uû��typename
	b.�Ƿ��ɣ�T�����ͣ����ܵ���������
	c.����inline��ģ��������
	d.����ֵ����
	e.û���⣬�������ͬ��

	16.19��ok
	16.20: ok

	*/

	cin >> a;
	return 0;
}


