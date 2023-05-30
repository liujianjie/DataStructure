#include <iostream>
#include <vector>
#include <list>
using namespace std;


int main()
{
	int a;
	try
	{
		range_error r("dsf");
		exception *p = &r;
		//throw r;
		//throw *p;
		throw p;
	}
	catch (range_error e)
	{
		cout << "range_error:" << e.what() << "，msg:";
	}
	catch (exception e)
	{
		cout << "exception e:" << e.what() << "，msg:";
	}
	catch (exception *e)
	{
		cout << "exception *e:" << (*e).what() << "，msg:";
	}
	/*
	练习：
	18.1:
	a. range_error
	b. exception ，静态类型决定，切掉派生类range_error的部分
	需要抛出 exception *p对象

	18.2：
	会销毁vector创建的对象，输入流会调用析构函数销毁，但是p动态分配对象不会自动销毁。

	18.3：
	1.把p改写为智能指针
	2.创建一个具有int*成员的类，用析构函数来销毁指针

	*/
	cin >> a;
	return 0;
}
