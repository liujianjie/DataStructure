#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>
#include <list>
#include <string> 
#include <memory>
#include <type_traits>
#include <climits>
#include "Blob.h"
#include "DebugDelete.h"
#include "NoDefault.h"
using namespace std;

/*

*/
// 局部变量会销毁的，fcn也许是这样的形式
int& reval(int* a)
{
	return *a;
}
template <typename It>
auto fcn(It beg, It end)->decltype(*beg)
{
	return *beg;
}
template <typename It>
auto fcn2(It beg, It end)->
	typename remove_reference<decltype(*beg)>::type
{
	return *beg;
}
template <typename It>
auto fcn3(It beg, It end)->
	decltype(*beg + 0)
{
	return *beg;
}

template <typename It>
auto sum(It lhs, It rhs)->decltype(lhs + rhs)
{
	return lhs + rhs;
}
int main()
{
	int a;
	int testvl = 32;
	vector<int> vi3 = { 1,2,3,4,5 };
	vector<int>::iterator it1 = vi3.begin();
	decltype(*it1) dl1 = testvl;

	// 16.40
	decltype(*it1 + 0) dl2 = 4;

	
	cout << SHRT_MAX << endl;
	short st1 = 32766, st2 = 32766;
	short st3 = st1 + st2;
	cout << st3 << endl;
	// 16.41
	cout << sum(st1, st2) << endl;
	int vl = 43;
	int *v2 = new int(12);
	int &v3 = vl;
	decltype(vl) dp1 = 23;
	decltype(v2) dp2 = &vl;
	//int &a4 = val2;
	//decltype(a4 + 0) a = 23;

	// 一个引用给另一个引用
	int val1 = 9, val2 = 12;
	int &a1 = val1;
	int &a2 = a1;
	int &a3 = reval(&val2);
	int *ap1 = &val2;
	cout << "a3" << endl;
	cout << a3 << endl;
	a3 = 100;
	cout << val2 << endl;

	

	vector<int> vi = { 1,2,3,4,5 };
	vector<string> ca = { "hi","asdf" };
	
	auto &i = fcn(vi.begin(), vi.end());
	auto &s = fcn(ca.begin(), ca.begin());
	cout << "i" << endl;
	cout << i << endl;
	i = 23;
	cout << vi[0] << endl;
	// 脱去引用，获得类型,返回值
	auto rval1 = fcn2(vi.begin(),vi.end());
	cout << rval1 << endl;

	vector<double> ve2{1,2,3,4};
	auto d1 = fcn3(ve2.begin(), ve2.end());
	vector<NoDefault> ve3{ 1,2,3,4 };
	//auto rval2 = fcn(ve3.begin(), ve3.end());
	//auto d1 = fcn3(ve3.begin(), ve3.end());// 没有+法运算符
	/*
	练习：
	16.40:
	1.自己：先执行加法运算，那么就获得一个值,再decltype是类型，需要实参类型能有加法运算符吧

	16.41:ok
	*/

	cin >> a;
	return 0;
}


