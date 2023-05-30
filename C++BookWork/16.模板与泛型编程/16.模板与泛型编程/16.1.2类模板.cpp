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
#include "Screens.h"
#include "Screen.h"

using namespace std;

/*
复习拷贝控制
Blob<int> b0 ({ 1,2,3,4,5 });
Blob<int> b1 = b0;
Blob<int> b2(b1);
Blob<int> b4 = Blob<int>({ 1,2,3,4,5 });// 不知道为什么没有拷贝构造执行
Blob<int> b3;
b3 = b2;
b3 = Blob<int>({ 1,2,3,4,5 });// 先构造再拷贝赋值
b3 = { 1,2,3,4,5 };// 先构造再拷贝赋值
*/
/*
1.练习16.15 的输入输出运算符，看==运算符怎么声明的，或者在内部声明，看一个模板包含另一个模板
*/
template<typename T> using twin = pair<T, T>;

template<typename T> using partNo = pair<T, unsigned>;

int main()
{
	int a;
	// 1.实例化类模板
	//Blob<int> ia;
	//Blob<int> ia2 = { 0,1,2,3 };

	//Blob<string> names;
	//Blob<double> prices;

	// 在模板作用域中引用模板类型

	// 5.类模板的成员函数
	// 6.	Check和元素访问成员
	// 7.	Blob构造函数
	//Blob<string> articles = { "a","an","the" };

	//// 8.	类模板成员函数的实例化
	//Blob<int> squares = { 0,1,2,3 };
	//for (size_t i = 0; i != squares.size(); ++i)
	//	squares[i] = i * i;
	// 9.简化
	Blob<int> bb1({ 1,2,3,4,5 });
	//Blob<double> bb2({ 1,2,3,4,5 });
	// 10.友元
	BloPtr<int> bp1(bb1);
	bp1++;
	//BloPtr<double> bp2(bb1);// 不匹配

	//11
	typedef Blob<string> StrBlob;

	twin<string> authors;// pair<string,string>

	partNo<string> books;
	partNo<int> cars;
	//partNo<int, int> car2;// 不能指定第二个成员

	// 12
	Foo<int> fi;
	auto ct = Foo<int>::count();
	ct = fi.count();
	//ct = Foo::count;

	// 友元模板
	//Pal2<C1> t1;
	//t1.printC1();

	////Pal2<double> t2;
	////t2.printC1(); //不可访问

	//Pal3<int> t3;
	//t3.printC1();//可以随意实例化

	//Pal2<int> t4;
	//t4.printPal1();

	//t3.printPal1();// 内部是double

	//C2 t5;
	//t5.printPal1();// 所有

	C3 t6;
	t6.printPal1();// 自己模板参数的实例

	cout << "Test :16.14" << endl;
	//Screens<3, 3> sc1('g');
	//cout << sc1.get() << endl;

	//Screen<5, 5> sc3('a');
	//cin >> sc3;
	//cout << sc3;

	Screens<6, 6> sc4;
	cin >> sc4;
	cout << sc4;

	// 练习
	/*
	16.9:函数模板，可以显示和隐式，并且可以非类型模板参数。。。类模板蓝图只能显示指定类型
	16.10:实例化所有成员
	16.11：在类域内，不用加上模板参数列表，但是若是当函数参数则需要加上
	16.12: 没啥好实现
	16.13：一对一友好关系，不然不同类型的对比 保错
	16.14:ok
	16.15:ok
	16.16:先放着
	*/

	cin >> a;
	return 0;
}