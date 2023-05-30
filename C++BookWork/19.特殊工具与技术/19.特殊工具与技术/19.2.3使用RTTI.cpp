#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
	Derived(int val1,string st1):val1(val1),st1(st1),Base(val1,st1) {
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
int main()
{
	int a;
	Derived d1(1,"123"),d2(1, "123");
	bool bln = d1 == d2;
	cout << bln << endl;

	Base* b1 = new Derived(1,"12");
	Base* b2 = new Derived(1, "12");
	bool bln2 = (*b1 == *b2);
	cout << bln2 << endl;

	Base* b1 = new Base(1, "12");
	Base* b2 = new Base(2, "12");
	bool bln3 = (*b1 == *b2);
	cout << bln3 << endl;
	/*
	练习：无
	*/
	cin >> a;
	return 0;
}