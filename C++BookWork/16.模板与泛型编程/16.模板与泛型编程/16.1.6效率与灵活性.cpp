#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <list>
#include <string> 
#include <memory>
#include "DebugDelete.h"
#include "NoDefault.h"
using namespace std;

/*

*/
int main()
{
	int a;
	int *i1 = new int;
	double *d1 = new double;
	
	shared_ptr<int> s1(i1);
	shared_ptr<double> s2(d1, DebugDelete());

	s1.reset(i1, DebugDelete());

	NoDefault *n1 = new NoDefault(2);
	NoDefault *n2 = new NoDefault(24);
	shared_ptr<NoDefault> sp1(n1);
	sp1.reset(n2, DebugDelete());
	cout << n1->val << endl;
	sp1.reset(n1);
	cout << n1->val << endl;

	NoDefault *n3 = new NoDefault(3);
	unique_ptr<NoDefault, DebugDelete> u1(n3, DebugDelete());
	u1.reset();
	/*
	练习：
	16.28:  有时间在写吧。
	大概就是用模板来指向任何类型，一个计数器
	删除器可以在类模板定义个模板参数，del的时候看运行对象是否为空
	也可以用成员模板函数重新指定？

	一样的模板，没有成员模板应该更简单点。
	16.29: 
	
	*/

	cin >> a;
	return 0;
}


