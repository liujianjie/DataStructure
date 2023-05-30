#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
using namespace std;
/*
第一节用make_shared();创建智能指针
1.若不初始化一个智能指针，就被初始化为一个空指针
2.智能指针的构造函数是explicit ，就是说，必须用直接初始化，不能用赋值初始化 = 
3.初始化智能指针的普通指针必须指向动态内存，智能指针用delete删除它，但是可以关联指向其它类型的资源的指针上，需提供自己delete的操作
****
调用所在的表达式结束时，这个临时对象呗销毁了，于是是将这个临时对象传给了形参才结束
创建时为1，传递给形参计数为2，销毁为1，形参结束为0
*/

shared_ptr<int> clone(int p) {
	//return new int(p);// 错误 隐式不可
	return shared_ptr<int>(new int(p));
}

void process(shared_ptr<int> ptr)
{
	cout << *ptr << endl;
}
int main()
{
	int a;
	shared_ptr<int> p1;
	shared_ptr<int> p2(new int(10));// p2指向一个值为42的int

	//
	//shared_ptr<int> p3 = new int(30);//错误
	shared_ptr<int> p4(new int(54));

	// 不要混合使用普通和智能指针
	// 协调对象的析构，但仅限于自身的拷贝，避免无意中将同一块内存绑定到多个独立创建的shared_ptr上

	shared_ptr<int> p5(new int(23));
	process(p5);// 拷贝p5会增加计数 计数为2
	int i = *p5;// 正确 计数为1
	cout << "i"<< i << endl;

	int *x(new int(102));
	//process(x);//error 隐式不可
	/*
	****
	调用所在的表达式结束时，这个临时对象呗销毁了，于是是将这个临时对象传给了形参才结束
	创建时为1，传递给形参计数为2，销毁为1，形参结束为0
	*/
	process(shared_ptr<int>(x));// 合法，但是内存被释放，即x被释放 不能访问了
	int j = *x;//未定义的，
	cout << j << endl;// 把内置指针交给智能指针操作，就不要使用内置指针访问内存的好，无法知道什么时候被销毁

	// 不要用get初始化另一个智能指针或者为智能指针赋值
	/* get返回位置指针
	为了不能使用智能指针而使用它的内置指针
	使用get得到的内置指针最好不要delete
	*/
	shared_ptr<int> p6(new int(109));
	int *q1 = p6.get();
	cout << *q1 << endl;
	{
		shared_ptr<int> p7(q1);// 引用计数为1, p7与p6是独立的，并么有关联
	}// p7离开作用域，引用计数为0，那么删除了q1指针，并且p6的指针内存也销毁了，导致p6的引用计数为1但是 指向的内存销毁了
	// 并且p6被销毁时，内存会被delete 二次
	cout << *p6 << endl;

	// 其它shared_ptr操作
	shared_ptr<int> p7(new int(12));
	cout << p7.unique() << endl;// unique是否独占
	p7.reset(new int(19));// 正确，p7指向新对象,会销毁原来p7的内存并且指向新内存，若没有指向新内存，让p置位空

	// 练习 
	// p8引用计数为1，给临时对象2，临时对象给形参3，临时对象销毁2，形参销毁为1 没错
	shared_ptr<int> p8(new int(11));
	process(shared_ptr<int>(p8));
	cout << *p8 << endl;

	// p9引用计数为1，get内置指针给临时对象，临时为1，给形参为2，临时销毁临时为1，形参销毁为0 那么指针指向的内存没了
	shared_ptr<int> p9(new int(111));
	process(shared_ptr<int>(p9.get()));
	cout << *p9 << endl;

	// 三
	auto p10 = new int();
	auto sp = make_shared<int>();
	process(sp);// 没有错
	//process(new int());//不可隐式
	//process(p10);不可隐式 同上
	process(shared_ptr<int>(p10));// 用内置指针创建临时智能指针计数1，给形参计数2，销毁为1，形参销毁为0
	cout << *p10 << endl;

	//
	auto sp2 = make_shared<int>();
	auto p11 = sp.get();
	delete p11;// 将sp智能指针的内置指针删除的话，内存会销毁
	//cout << *sp2 << endl;// 会错误

	cin >> a;
	return 0;
}
