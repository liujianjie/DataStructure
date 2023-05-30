#include <iostream>
#include <string>
using namespace std;

class N {
public:
	int a;
	void Display() { cout << "A::a=" << a << endl; }
};
class A :public N {
public:
	int a1;
};
class B :public N {
public :
	int a2;
};
class C :public A, public B {
public:
	int a3;
	void show() { cout << "a3=" << a3 << endl; }
};
int main() {
	C c1;
	c1.N::a = 3;
	c1.A::Display();
	c1.A::a = 3;
	return 0;
}