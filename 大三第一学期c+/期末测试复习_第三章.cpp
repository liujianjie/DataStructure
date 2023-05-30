#include <iostream>
using namespace std;

class Box {
public :
	Box() { cout << "Box() cons" << endl;; }
	Box(int, int) {}
	Box(int, int a = 10, int b = 10){}
	void Say() { cout << "Box::Say()" << endl; }
public:
	~Box() {
		cout << "~BOX()" << endl;
	}
};

class Box2 {
public:
	Box b1;
	Box2() { cout << "Box2() cons" << endl; }
	void Say() { cout << "Say()" << endl; }
public:
	~Box2() {
		cout << "~Box2()" << endl;
	}
};

class Box3 {
public:
	const Box2 b2;
	const int value1;
	int value2;

	Box3(int v1, Box2 b) : value1(v1),b2(b) {

	}
	void Say() {
		//b2.Say();
		cout << value1 << endl;
	}
	const void Eat() {
		Say();
	}
};
void Say() {

}

class Box5 {
public:
	int val1;
	Box5(int v1) :val1(v1) {

	}
	Box5(const Box5& box) {
		cout << "Box5(Box& box)" << endl;
	}
private:
	static int val2;
};
int Box5::val2 = 3;
Box5 Copy1(Box5 b) {
	return b;
}

class Date;
class Time {
public:
	void Display(Date& da);
};
class Date {
public:
	int value1;
};

void Time::Display(Date& da) {
	cout << "Display:" << da.value1 << endl;
}

template<class T1>
int Fun() {
	T1 t = 3;
	cout << t << endl;
	return 0;
}
class C {
public:
	C(){}
	C(int r) {
		vr = r;
	}
	int GetVr() {
		return vr;
	}
private:
	int vr;
};

class Complex {
public:
	Complex() {
		real = 0;
		imag = 0;
	}
	Complex(double r) {
		cout << "Complex(double r)" << endl;
		real = r;
		imag = 0;
	}
	Complex(double r, double i) {
		real = r;
		imag = i;
	}
	//operator double() {
	//	cout << "operator double" << endl;
	//	return real;
	//}
	//Complex operator+(Complex &c1) {
	//	Complex c;
	//	return c;
	//}
	friend Complex operator+(Complex c1, Complex c2);
private:
	double real;
	double imag;
};
Complex operator+(Complex c1, Complex c2)
{

	return Complex(c1.real + c2.real);
}
int main()
{
	Complex co1, co2(3.5, 3);
	co1 =  2.5;
	co1 = co2 + Complex(2.5);

	C c1;
	c1 = C(2);
	cout << c1.GetVr() << endl;

	Fun<int>();
	Time t1;
	Date d1;
	d1.value1 = 3;
	t1.Display(d1);
	//cout << Box5::val2 << endl;
	Box5 b51(3);
	Copy1(b51);

	Box2 b22;
	const Box3 b3(3, b22);
	cout << b3.value1 << endl;
	cout << b3.value2 << endl;
	//b3.Eat();

	void (*p1)() = Say;
	void (*p2)();// ¿ÕÖ¸Õë
	//void(Box::*p3)();
	void(Box::*p4)() = &Box::Say;
	Box b1;
	(b1.*p4)();

	Box2* b2 = new Box2();
	delete b2;
	return 0;
}