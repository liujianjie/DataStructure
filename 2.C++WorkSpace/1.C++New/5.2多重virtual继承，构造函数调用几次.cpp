#include <iostream>
#include <string>
using namespace std;
/*
如果不虚继承，会调用两次 N构造函数
*/
//class N {
//public:
//	int a;
//	void Display() { cout << "A::a=" << a << endl; }
//	N(){}
//	N(int b) :a(b) { cout << "N：构造调用" << endl; }
//};
//class A : public N {
//public:
//	int a1;
//	A(int a):a1(a),N(a){}
//};
//class B : public N {
//public:
//	int a2;
//	B(int a) :a2(a), N(a) {}
//	void Display() { N::Display(); cout << "B::a=" << a << endl; }
//};
//class C : public A,  public B {
//public:
//	int a3;
//	C(int a) :a3(a), A(a), B(a) {}
//	void show() { cout << "a3=" << a3 << endl; }
//};
/*
如果虚继承，会调用一次 N构造函数
*/
//class N {
//public:
//	int a;
//	void Display() { cout << "A::a=" << a << endl; }
//	N() {}
//	N(int b) :a(b) { cout << "N：构造调用" << endl; }
//};
//class A :virtual public N {
//public:
//	int a1;
//	A(int a) :a1(a), N(a) {}
//};
//class B :virtual public N {
//public:
//	int a2;
//	B(int a) :a2(a), N(a) {}
//	void Display() { N::Display(); cout << "B::a=" << a << endl; }
//};
//class C : public A, public B {
//public:
//	int a3;
//	C(int a) :a3(a), A(a), B(a), N(a) {}
//	void show() { cout << "a3=" << a3 << endl; }
//};
/*标准写法*/
class N {
public:
	int a;
	void Display() { cout << "A::a=" << a << endl; }
	N() {}
	N(int b) :a(b) { cout << "N：构造调用" << endl; }
};
class A :virtual public N {
public:
	int a1;
	A(int a) :a1(a) { cout << "A：构造调用" << endl; }
};
class B :virtual public N {
public:
	int a2;
	B(int a) :a2(a) { cout << "B：构造调用" << endl; }
	void Display() { N::Display(); cout << "B::a=" << a << endl; }
};
class C : public B, public A {
public:
	int a3;
	C(int a) :a3(a), A(a), B(a), N(a) {}
	void show() { cout << "a3=" << a3 << endl; }
};
int main() {
	C c1(2);
	//c1.Display();
	return 0;
}