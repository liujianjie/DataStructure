#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Partice157.h"
#include "Disc_quote.h"

using namespace std;

/*
引出：
每个类定义自己的作用域，作用域中定义类的成员。
继承关系时：派生类的作用域嵌套在其基类的作用域之内
如果在派生类的作用域无法找到成员，则会在外层的基类作用域查找

一、在编译时进行名字查找
一个对象、引用或指针的静态类型决定了该对象的哪些成员是可见的。
即使静态类型与动态类型可能不一致。
总：由静态类型决定哪些成员可见可使用

即：向上转型时若静态类型与动态类型不一致，从静态类型（父类）查找，则会忽略动态类型（子类）的成员

二、名字冲突与继承
派生类的成员名字会隐藏定义在基类的成员名字,同名

三、通过作用域运算符来使用隐藏的成员
可以使用作用域运算符来使用一个被隐藏的基类成员
note：除了覆盖继承而来的虚函数之外，最好不要定义同名名字

关键概念：名字查找与继承
p->mem();4个步骤
1.确定p的静态类型。必然是类类型
2.p的静态类型对应的类中查找mem，找不到再找基类直至顶，若没有则报错
3.若找到了mem，常规的类型检查，是否合法
4.合法：是否是虚函数产生不同的代码：
1）若mem是虚函数且我们是通过引用或指针进行的调用，则编译器产生的代码将在运行时确定到底运行该虚函数的哪个版本，根据动态类型
2）若不是虚函数或者通过对象（而非引用或指针）进行的调用，则编译器将产生一个常规函数调用

四、一如往常，名字查找先于类型检查
内层作用域的函数不会重载外层作用域的函数
定义派生类中的函数也不会重载基类的成员。
若派生类中的成员与基类的某个成员同名，则派生类将在其作用域内隐藏该基类成员，即使形参列表不一致

d.memfcn();//
一旦找到名为memfcn的成员，查找过程就终止，再进行类型检查，形参合法否。

五、虚函数与作用域
所以基类与派生类的虚函数接受的实参必须相同

六、通过基类调用隐藏的虚函数
就是根据动态类型查找，不会调用隐藏的虚函数，会向上查找

七、覆盖重载的函数
引出：和其它函数一样，成员函数无论是否是虚函数都能被重载
派生类可以覆盖重载函数的0个或多个实例。
派生类希望所有的重载版本对于它来说都是可见，则需要覆盖所有的版本，或者一个也不覆盖

问题是：若派生类需要使用基类的重载成员，并且自身需要覆盖部分基类的重载成员，则不得不需要覆盖基类的每个版本，显然麻烦

解决方案是：使用using
用using声明基类中重载函数的名称，再重新定义向覆盖的重载函数版本则可以解决。
对派生类没有重新定义的重载版本的访问实际上是对using声明点的访问
*/
struct Base1 {
	Base1():mem(0){}
	int memfcn()
	{
		cout << "Base1::memfcn()" << endl;
	}
public:
	virtual int fcn() {
		cout << "Base1::fcn()" << endl;
		return 0;
	}
protected:
	int mem;
};
struct Derived :Base1 {
	Derived() = default;
	int memfcn(int a)
	{
		cout << "Derived::memfcn()" << endl;
		return 0;
	}
	Derived(int i):mem(i){}
	//int get_mem() { return mem; }
	int get_mem() { return Base1::mem; }
protected:
	int mem;
};

class D1 :public Base1 {
public:
	using Base1::fcn;
	int fcn() {
		cout << "D1::fcn()" << endl;
		return 0;
	}
	int fcn(int) {
		cout << "D1::fcn(int)" << endl;
		return 0;
	}
	virtual void f2() {
		cout << "D1::f2()" << endl;
	}
};
class D2 :public D1 {
public:
	int fcn(int) {
		cout << "D2::fcn(int)" << endl;
		return 0;
	}
	int fcn() {
		cout << "D2::fcn()" << endl;
		return 0;
	}
	void f2() {
		cout << "D2::f2()" << endl;
	}
};

struct Base2 {
public:
	void fcn() { cout << "Base2::fcn()"<<endl;}
	void fcn(int){ cout << "Base2::fcn(int)" << endl; }
	void fcn(int,double) { cout << "Base2::fcn(int,double)" << endl; }
};
struct Derived2:public Base2 {
public:
	using Base2::fcn;
	void fcn() { cout << "Derived2::fcn()" << endl; }
	/*void fcn(int) { cout << "Derived2::fcn(int)" << endl; }
	void fcn(int, double) { cout << "Derived2::fcn(int,double)" << endl; }*/
};
int main()
{
	int a;
	Bulk_quote bulk;
	Bulk_quote *bulkP = &bulk;
	Quote *itemP = &bulk;
	bulkP->discount_policy();
	//itemP->discount_policy();

	//Derived d(42);
	//cout << d.get_mem() << endl;

	//Derived d;
	//Base1 b;
	//b.memfcn();
	//d.memfcn(10);
	//d.memfcn();//
	//d.Base1::memfcn();

	Base1 bobj;
	D1 dlobj;
	D2 d2obj;
	Base1 *bp1 = &bobj, *bp2 = &dlobj, *bp3 = &d2obj;
	bp1->fcn();
	bp2->fcn();
	bp3->fcn();

	D1 *d1p = &dlobj;
	D2 *d2p = &d2obj;
	//bp2->f2();
	d1p->f2();
	d2p->f2();

	Base1 *p1 = &d2obj;
	D1 *p2 = &d2obj;
	D2 *p3 = &d2obj;
	//p1->fcn(42);
	p2->fcn(42);
	p3->fcn(42);
	cout << "---------------" << endl;

	Derived2 dd2;
	dd2.fcn();
	dd2.fcn(32);


	// 练习
	/*
	15.23 ok
	*/
	cin >> a;
	return 0;
}
