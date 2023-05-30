#include <iostream>
#include <string>
using namespace std;

class N {
public:
	int a;
	void Display() { cout << "A::a=" << a << endl; }
	N(int b) :a(b) { cout << "N：构造调用" << endl; }
};
class A {
public:
	int a1;
	A(int a):a1(a){ cout << "A：构造调用" << endl; }
};
class B{
public:
	int a2;
	B(int a) :a2(a){ cout << "B：构造调用" << endl; }
};
class C : public N {
public:
	int a3;
	static int val;
	B bc;
	A ac; // 受声明的前后顺序限制
	C(int a) :a3(a),N(a),ac(a), bc(a){

	}
};
int C::val = 3;

int main() {
	C c1(2);
	//c1.Display();
	cout << C::val << endl;
	return 0;
}