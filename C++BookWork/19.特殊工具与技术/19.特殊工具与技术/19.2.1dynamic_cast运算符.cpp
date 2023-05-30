#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "ZooClass.h"
using namespace std;

class A{
public:
	A() {}
	virtual ~A() {

	}
};
class B:public A{
public:
	B() {}
	virtual ~B() {

	}
};
class C :public B{
public:
	C() {}
	virtual ~C() {

	}
};
class D:public B,public A{
public:
	D() {}
	virtual ~D() {

	}
};
int main()
{
	int a;
	// 向下转型，错误
	ZooAnimal z0;
	Bear ba0 = dynamic_cast<Bear&>(z0);

	cout << "----" << endl;
	Panda *pa1 = new Panda;
	Bear *ba1 = new Bear;
	ZooAnimal *z1 = new ZooAnimal;
	Bear *ba2 = dynamic_cast<Bear*>(pa1);
	Bear *ba3 = dynamic_cast<Bear*>(z1);
	cout << "ba3" << ba3 << endl;
	Bear *ba4 = dynamic_cast<Bear*>(ba1);

	Panda *pa2 = 0;
	Bear *ba5 = dynamic_cast<Bear*>(pa2);
	cout << ba5 << endl;

	Panda pa3;
	Panda &pa4 = pa3;
	Bear &ba6 = dynamic_cast<Bear&>(pa4);
	//Bear &ba7 = dynamic_cast<Bear&>((&pa3));

	Bear &&ba8 = dynamic_cast<Bear&&>(pa4);// 可以是左值

	cout << "-----练习-------" << endl;
	A *pa = new C;
	B *pb = dynamic_cast<B*>(pa);
	//B *pb = new B;
	//C *pc = dynamic_cast<C*>(pb);
	//cout << pc << endl;// 转换失败耶。向下转型会失败。
	//A *pa = new D;
	//B *pb = dynamic_cast< B* >(pa);

	A *pa = new C;
	B *pbb = new B;
	A *paa = new D;
	if (B *pb = dynamic_cast<B*>(pa))
	{
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	if (C *pc = dynamic_cast<C*>(pbb))
	{
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	if (B *pb = dynamic_cast< B* >(paa))
	{
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	try
	{
		ZooAnimal *z0 = new ZooAnimal;
		// 引用抛出异常，不支持向下转型
		//C& cp = dynamic_cast<C&>(*pbb);
		//Bear ba0 = dynamic_cast<Bear&>(z0);
		
		// 指针不抛出异常但是指针值为0
		//C *pc = dynamic_cast<C*>(pbb);
		//Bear *ba00 = dynamic_cast<Bear*>(z0);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	/*
	练习：
	19.3:
	a.可以
	b.不可以 不支持向下转型
	c.可以
	19.4:
	ok
	19.5：
	当不能使用虚函数又需要用基类指针或引用调用派生类成员的时候，
	用dynamic_cast直接转换为派生类，再直接调用派生类的虚函数成员

	*/
	cin >> a;
	return 0;
}