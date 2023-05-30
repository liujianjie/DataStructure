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

// 尝试 T&& 是否保持const ，是的会，

template <typename F,typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
	f(t1, t2);
}
template <typename F, typename T1, typename T2>
void flip2(F f, T1&& t1, T2&& t2)
{
	f(t1, t2);
}

template <typename F, typename T1, typename T2>
void flip3(F f, T1&& t1, T2&& t2)
{
	f(std::forward<T1>(t1), std::forward<T2>(t2));
}


void f(int &v1, int v2)
{
	cout << ++v1 << " " << v2 << endl;
}
void g(int &v1, int&& v2)
{
	cout << ++v1 << " " << ++v2 << endl;
}

void p1(int &v1, const int& v2)
{
	cout << ++v1 << " " << v2 << endl;
}
int main()
{
	int a;

	int j = 1;
	flip1(f,j,42);
	cout << j << endl;// 不会改变，因为T1是int，t1只是j的拷贝，不是引用

	flip2(f, j, 42);
	cout << j << endl;// 会改变,T是int&，

	//int v1 = 32;
	//int &&v2 = v1;
	// 无法将参数2从int转换到int&&,因为参数二 int&& t2,但是在模板里是左值了，无法int &&a = b，
	// 无法将右值绑定到左值上
	//flip2(g, j, 41);
	flip3(g, j, 41);// 可以

	//std::forward<Type> 给type加上&&，若type为&则 && &折叠为&，若type为int，则&& 为int&&

	//flip3(g, j, j);// j为左值，T为int&
	// 传右值变量是否会改变？
	int jj2 = 12;
	int &jj3 = jj2;
	flip3(g, j, std::move(jj3));
	cout << jj3 << endl;// 会改变原来的值，就像
	int jj4 = 10;
	int &&jj5 = move(jj4);
	jj5 = 11;
	cout << jj5 << endl;
	cout << jj4 << endl;

	// 自己写的p1函数
	const int j2 = 32;
	int j3 = 48;
	flip3(p1, j, j2);// T2为const int&,forward后，const int& &&,还是const int& 可以
	flip3(p1, j, j3);// T2为 int&,forward后， int& &&,还是 int& 可以转换const int&
	/*
	练习：
	16.47: ok
	*/
	cin >> a;
	return 0;
}


