#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class ZooAnimal {
public:
	virtual void print() {
		cout << "ZooAnimal::print()" << endl;
	}
	ZooAnimal() {
		cout << "ZooAnimal()" << endl;
	}
	ZooAnimal(string s) :s(s) {
		cout << "Bear(string s)" << endl;
	}
	ZooAnimal(const ZooAnimal& b) {
		cout << "ZooAnimal(const ZooAnimal& b) {" << endl;
	}
	virtual ~ZooAnimal() {
		cout << "~ZooAnimal()" << endl;
	}
public:
	int zoo = 1;
	string s;
};
class Bear :public ZooAnimal {
public:
	virtual void toes() {
		cout << "Bear::toes()" << endl;
	}
	virtual void print() {
		cout << "Bear::print()" << endl;
	}
	Bear() {
		cout << "Bear()" << endl;
	}
	Bear(string s) :s(s) {
		cout << "Bear(string s)" << endl;
	}
	Bear(const Bear& b) :ZooAnimal(b) {
		cout << "Bear(const Bear& b) {" << endl;
	}
	virtual ~Bear() {
		cout << "~Bear()" << endl;
	}
public:
	int bea = 2;
	string s;
};
class Endangered {
public:
	virtual void print() {
		cout << "Endangered::print()" << endl;
	}
	virtual void highlight() {
		cout << "Endangered::highlight()" << endl;
	}
	Endangered() {
		cout << "Endangered()" << endl;
	}
	Endangered(string s) :s(s) {
		cout << "Endangered(string s)" << endl;
	}
	Endangered(const Endangered& b) {
		cout << "Endangered(const Endangered& b) {" << endl;
	}
	virtual ~Endangered() {
		cout << "~Endangered()" << endl;
	}
public:
	string s;
	int enda = 3;
};
class Panda :public Bear, public Endangered {
	//using Bear::Bear;
	//using Endangered::Endangered;
public:
	void cuddle(){
		cout << "Panda::cuddle()" << endl;
	}
	virtual void toes() {
		cout << "Panda::toes()" << endl;
	}
	virtual void print() {
		cout << "Panda::print()" << endl;
	}
	virtual void highlight() {
		cout << "Panda::highlight()" << endl;
	}
	Panda() {
		cout << "Panda()" << endl;
	}
	Panda(string s) :s(s), Bear(s), Endangered(s) {
		cout << "Panda(string s)" << endl;
	}
	Panda(const Panda& b) :Bear(b), Endangered(b) {
		cout << "Panda(const Panda& b) {" << endl;
	}
	virtual ~Panda() {
		cout << "~Panda()" << endl;
	}
public:
	string s;
	int pand = 4;
};

void print(const Bear&) {
	cout << "void print(const Bear&)" << endl;
}
void highlight(const Endangered&) {
	cout << "void highlight(const Endangered&) " << endl;
}
ostream& operator<<(ostream& os, const ZooAnimal&)
{
	os << "ostream& operator<<(ostream&, const ZooAnimal&)" << endl;
	return os;
}
// 二义性
//void print(const Endangered&) {
//	cout << "void print(const Endangered&)" << endl;
//}

class A{};
class B{};
class C:public A,public B{};

class X{};
class Y{};
class Z : public X,public Y{};
class MI:public C,public Z{};
class D :public X, public C {};
int main()
{
	int a;
	Panda p1;
	print(p1);
	highlight(p1);
	cout << p1 << endl;

	cout << "-------------" << endl;
	Bear *b1 = new Panda("pandsa");
	Endangered *e1 = new Panda("pan2");
	ZooAnimal *z1 = new Panda("pan3");
	Panda *p2 = new Panda("pan4");
	cout << b1->bea << endl;
	cout << e1->enda << endl;
	cout << z1->zoo << endl;
	cout << p2->pand << p2->bea << p2->enda << p2->zoo << endl;

	D *pd = new D;
	X *px = pd;
	A *pa = pd;
	B *pb = pd;
	C *pc = pd;
	cout << "-------------" << endl;
	Bear *pb0 = new Panda("ying_yang");
	pb0->print();
	//pb0->cuddle();
	//pb0->highlight();	
	delete pb0;

	ZooAnimal *pb1 = new Panda("ying_yang");
	pb1->print();
/*	pb1->cuddle();
	pb1->highlight();*/	
	delete pb1;
	/*
	练习：
	18.23:
	都可以
	18.24:
	只有print才可以调用
	18.25:
	a.Mi
	b.Mi
	c.MI
	d.MI,base2
	e.mi d1 base1
	f.mi d2,base2

	*/
	cin >> a;
	return 0;
}
