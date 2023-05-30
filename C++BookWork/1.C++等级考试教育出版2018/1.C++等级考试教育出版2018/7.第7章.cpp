#include <iostream>
using namespace std;

class Base {
public:
	Base(int val1): bval1(val1) {
	
	}
	int bval1;
};

class D1 : public virtual Base {
public:
	D1(int val1) : val1(val1), Base(val1) {

	}
	int val1;
};

class D2 :public virtual Base {
public:
	D2(int val1) : val1(val1),Base(val1) {

	}
	int val1;
};

class DD1 : D1,D2 {
public:
	DD1(int a,int b,int c,int d) : val1(a), Base(b), D1(c), D2(d) {

	}
	void print() {
		cout << Base::bval1 << endl;
	}
	int val1;
	
};

// ´¿ÐéÀà
class Base2 {
public:
	virtual void say() = 0;
};
void Base2::say() 
{
	cout << "Base2::say() " << endl;
}
class Dervied1 :public Base2{
public:
	virtual void say() {
		cout << "Dervied1::say() " << endl;
	}
};
class Dervied2 :public Dervied1 {
public:
	virtual void say() = 0;
};
class Dervied3 :public Dervied2 {

};

void Dervied2::say()
{
	cout << "Dervied2::say() " << endl;
}
int main()
{
	int a;
	DD1 d1(1,2,3,4);
	d1.print();

	D2 d2(2);
	cout << d2.Base::bval1 << endl;

	//Base2 bs1;
	Dervied1 dd1;
	dd1.say();

	//Dervied2 dd2;
	//dd2.say();

	//Dervied3 dd3;
	//dd3.say();
	cin >> a;
	return 0;
}