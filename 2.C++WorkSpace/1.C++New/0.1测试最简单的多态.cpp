#include <iostream>

using namespace std;

class A {
public:
	virtual void f1()
	{
	};
	void f2()
	{
		f1();
	}
	virtual void say()
	{
		cout << "hello A" << endl;
	}
};
class B : public A {
public:
	virtual void say()
	{
		cout << "hello B" << endl;
	}
	virtual void f1()
	{
		cout << "Bv" << endl;
	}
};
int main()
{
	A* a = new B();
	a->say();
	a->f2();

	return 0;
}