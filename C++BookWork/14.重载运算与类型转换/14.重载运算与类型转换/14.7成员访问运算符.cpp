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

/*
*与->

箭头运算符必须是类的成员，解引用通常也是不过可以不用
->返回string的指针

二、对箭头运算符返回值的限定
永远不能丢掉成员访问这个最基本的含义?

重载的箭头运算符必须返回类的指针或者自定义了箭头运算符的某个类的对象

调用：
*point.接指向这个对象的成员
point->()->接指向这个对象的成员

*/
int main()
{
	int a;

	StrBlob a1 = { "hi","bye","now" };
	StrBloPtr p1(a1);
	cout << (*p1) << endl;

	cout << *(p1.operator->()) << endl;
	
	*p1 = "okays";
	cout << p1->size() << endl;// 首元素的大小
	cout << (*p1).size() << endl;

	int val1 = 32;
	int &val2 = val1;
	int *it1 = new int(val2);
	int &r1 = *it1;
	int *it3 = &r1;
	int &it2 = r1;
	cout << it2 << endl;
	*it1 = 43;
	cout << it2 << endl;
	cout << val1 << endl;
	cout << "----------" << endl;

	StrBlob sb1 = {"12321","34324","23423"};
	StrBloPtr sp1(sb1);
	NewClass1432 nc1(sp1);

	NewClass1432 *nc2 = &nc1;

	cout << (*nc1).deref() << endl;
	cout << (nc1.operator->()->deref()) << endl;

	cout << (nc1->deref()) << endl;

	cout << (*nc2).operator*().deref() << endl;
	// 练习
	/*
	14.30 没有
	14.31 析构，自动析构
		拷贝构造的话，

	14.32

	*/

	cin >> a;
	return 0;
}