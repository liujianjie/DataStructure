#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Partice157.h"

using namespace std;

/*
引出：
使用基类的引用或指针调用一个虚成员函数会执行动态绑定

一、对虚函数的调用可能在运行时才被解析
虚函数被调用是与绑定到指针或引用上的对象的动态类型相匹配的那个

具有普通类型的表达式调用虚函数，在编译时就确定了版本，可以改变ase表示的对象的值，但是不会改变该对象的类型

关键概念：C++多态性
1.把具有继承关系的多个类型称为多态类型
2.基类的引用或指针调用基类定义的一个函数时
虚函数：运行时才决定哪个版本
非虚函数：编译时就决定与静态类型一致版本
3.用对象进行调用的函数
虚函数与非虚函数在编译时与静态类型一致

二、派生类中的虚函数
1、一个函数为虚函数，在所有派生类中都是虚函数，可以再写virtual显示表示
2.当派生类重新覆盖了某个继承而来的虚函数，形参必须与覆盖的基类函数完全一致
3.返回类型也必须匹配，例外的是当基类中返回类本身的指针或引用时
如：基类的虚函数返回B*,派生类的虚函数返回D*
前提是D到B的类型转换是可访问的

三、final和override说明符
override，说明派生类中的虚函数覆盖了基类的虚函数，若没有则会显示提示报错
只有虚函数才可以被覆盖

final，把函数指定为final，则之后任何尝试覆盖该函数的操作都将引发错误

override 与final出现在形参列表 以及尾置类型之后 这两个顺序无所谓

四、虚函数与默认实参
虚函数也可以有默认实参
实参值由本次调用的静态类型决定。
所以派生类的虚函数的默认实参应该与积累的默认实参保持一致

五、回避虚函数的机制
希望对虚函数的调用不要执行动态绑定，而是强迫执行虚函数的某个特定版本。使用作用域运算符

在编译时完成解析
note：通常，只有成员函数（或友元）中的代码才需要使用作用域运算符来回避虚函数的机制

什么时候用：
一般在派生类的虚函数中调用基类虚函数的虚函数完成共同任务，
注意要用作用域，不然就会自身调用自身
*/
struct B {
	virtual void f1(int)const{}
	virtual void f2(){}
	void f3(){}
};
struct D1 : B {
	void f1(int) const override{}
	//void f2(int) override;
	//void f3() override; 只有虚函数才可以被覆盖
	//void f4() override;
};
struct D2 : B {
	virtual void f1(int)const override final {}
	//virtual void f2() {}
};
struct D3 : D2 {
	//void f2() override final{}
	//virtual void f1(int) const{}
};
double print_total(ostream& os,
	const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn() <<
		"# sold:" << n << "total due:" << ret << endl;
	return ret;
}

class base {
public:
	string name() 
	{ 
		cout << "string name()" << endl;
		return basename; 
	}
	virtual void print(ostream &os) { os << basename << "basename" << endl; }
private:
	string basename;
};
class derived :public base {
public:
	void print(ostream &os) { base::print(os); os << " " << i<<"i"<<endl; }
private:
	int i;
};
int main()
{
	int a;
	Quote base1("0-021-32-1", 50);
	print_total(cout, base1, 10);
	Bulk_quote derived1("09-sdfsd-9sdf",50,5, .19);
	print_total(cout, derived1, 10);

	base1 = derived1;
	base1.net_price(20);
	//base.min_qty// 访问不了派生类的成员

	Bulk_quote bq;
	Quote* qt = &bq;
	qt->testMorenShi();

	qt->Quote::testMorenShi();


	
	derived dr1;
	base* bs1 = &dr1;
	bs1->print(cout);


	cout << endl;
	base bobj;
	derived dobj;
	base *bp1 = &bobj;
	base *bp2 = &dobj;

	base &br1 = bobj;
	base &br2 = dobj;

	bobj.print(cout);
	dobj.print(cout);

	bp1->name();
	bp2->name();

	br1.print(cout);
	br2.print(cout);
	// 练习
	/*
	15.11 ok
	15.12 特定情况下需要
	15.13 没有用基类的作用域
	15.14 ok
	*/
	cin >> a;
	return 0;
}