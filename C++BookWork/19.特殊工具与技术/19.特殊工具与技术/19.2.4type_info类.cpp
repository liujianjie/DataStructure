#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <typeinfo>
#include <typeinfo.h>
#include "ZooClass.h"
#include "AllClass.h"
using namespace std;

class Base {
	friend bool operator==(const Base&, const Base&);
public:
	Base() {
	}
	Base(int val1, string st1) :val1(val1), st1(st1) {
	}
	virtual ~Base() {
	}
	int val1;
	string st1;
protected:
	virtual bool equal(const Base&)const;
};
class Derived : public Base {
public:
	Derived() {
	}
	Derived(int val1, string st1) :val1(val1), st1(st1), Base(val1, st1) {
	}
	virtual ~Derived() {

	}
	int val1;
	string st1;
protected:
	bool equal(const Base&)const override;
};
bool operator==(const Base& lhs, const Base& rhs)
{
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

bool Derived::equal(const Base& rhs)const
{
	auto r = dynamic_cast<const Derived&>(rhs);
	// 比较r与this
	return val1 == r.val1 && st1 == r.st1;
}
bool Base::equal(const Base& rhs)const
{
	// 直接比较
	return val1 == rhs.val1 && st1 == rhs.st1;
}
// 就判断string就可以
string jianshao(string st) {
	if (st.find("string") != string::npos) {
		return "string";
	}
	return st;
}
class A {
public:
	A(){}
	virtual ~A(){}
};
class B :public A {
public:
	B() {}
	virtual ~B() {}
};
class C :public B {
public:
	C() {}
	virtual ~C() {}
};

int main()
{
	int a;
	Base* b1 = new Base(1,"123");
	cout << typeid(b1).name() << endl;

	Base* b2 = new Derived(1, "123");
	cout << typeid(*b2).name() << endl;


	Derived *d1 = new Derived();
	cout << typeid(d1).name() << endl;

	int arr[19];
	cout << typeid(42).name() << ","
		<< typeid(arr).name() << ","
		<< typeid(Base).name() << ","
		<< typeid(string).name() << ","
		<< typeid(d1).name() << ","
		<< typeid(*d1).name() << endl;

	cout << jianshao(typeid(42).name()) << ","
		<< jianshao(typeid(arr).name()) << ","
		<< jianshao(typeid(Base).name()) << ","
		<< jianshao(typeid(string).name()) << ","
		<< jianshao(typeid(d1).name()) << ","
		<< jianshao(typeid(*d1).name()) << endl;

	A *pa = new C;
	cout << typeid(pa).name() << endl;

	C cobj;
	A &ra = cobj;
	cout << typeid(&ra).name() << endl;

	B *px = new B;
	A& ra2 = *px;
	cout << typeid(ra2).name() << endl;
	
	int vals = 10;
	int &zhi = vals;
	cout << zhi << endl;
	cout << &zhi << endl;
	/*
	练习：
	19.9:ok,就string很多字，把这个处理就行
	19.10:
	a.class C* 错了 是class A* 是pa不是*pa
	b.class C  错了 是class A* &ra是指A，是取地址
	c.class B* 错了，是class B，ra2是*px，typeid(*px)
	*/
	cin >> a;
	return 0;
}