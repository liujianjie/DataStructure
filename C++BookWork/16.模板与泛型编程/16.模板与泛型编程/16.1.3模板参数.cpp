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
	double B;// 不会报错 c+14
}

//template <typename v, typename v> void f2(v vv)// 调用出错，因为没有匹配的到的函数实参

// 模板声明
//template <typename T> int calc(const T&, const T&);
template <typename T> class CC;

template <typename T> T calc(const T&, const T&);

//template<typename T>
//T calc(const T &, const T &)
//{
//	return T();
//}

//定义的模板参数名字不必相同，但是需要相同？？编译器的问题吧，还是可以运行的
template <typename Type> 
Type calc(const Type&, const Type&) 
{ 
	cout << "Type calc(const Type&, const Type&) " << endl;
	return Type(); 
}

// 使用类的类型成员
// 需要显示设置为类型 typename 告诉为是类型,
template <typename T>
typename T::value_type top(const T &c)
{
	if (!c.empty())
		return c.back();
	else {
		// 
		typename T::value_type re = 'd';// 通过typename指定为类型，默认是值的
		return re;
		//return T::value_type();// 生成一个值初始化元素返回给T::value_type类型
	}
}
// 默认模板实参
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
// 类模板与模板默认实参
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
	// size_type为类型需要指定为类型不然默认为值，size成员函数为值
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

	// 是value_type()返回的，生成一个值初始化的元素给value_type
	cout << v << endl;
	cout << st2 << endl;

	// 返回尾后值
	cout << st1 << endl;

	// 
	Sales_data sd1("sdfsd"), sd2("zxcvzxcv");
	calc(sd1,sd2);

	// 默认模板实参
	less<int> le;
	int sval = le(5, 10);
	//sval = le(sd1, sd2);
	cout << sval << endl;
	cout << compare(12, 14) << endl;
	// 可以自己指定比较类型
	//cout << compare(&sd1, &sd2) << endl;// by the way ,对指针类型比较良好的代码
	cout << compare(sd1, sd2, compareIsbn) << endl;

	//
	Numbers<long double> l1;
	Numbers<> l2;// 默认类型

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
	// 练习
	/*
	16.17:
	1.类型参数。。。没有吧
	1.用模板参数访问这个类型的成员时需用typename，不能class

	16.18:
	a.非法，U没有typename
	b.非法吧，T是类型，不能当做变量吧
	c.错误，inline在模板声明后
	d.返回值少了
	e.没问题，隐藏外层同名

	16.19：ok
	16.20: ok

	*/

	cin >> a;
	return 0;
}


