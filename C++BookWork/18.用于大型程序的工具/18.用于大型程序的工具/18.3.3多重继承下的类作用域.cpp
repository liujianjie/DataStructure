#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <algorithm>
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
	//18.3.3
//private:
	double max_weight()const {
		return 10.0;
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
	double max_weight(int a) const {
		return 20.0;
	}
public:
	string s;
	int enda = 3;
};
class Panda :public Bear, public Endangered {
public:
	void cuddle() {
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
	double Panda::max_weight() const {
		return std::max(Bear::max_weight(),
			Endangered::max_weight(3));
	}
public:
	string s;
	int pand = 4;
};

struct Base1 {
	void print(int) const{}
protected:
	int ival;
	double dval = 2;
	char cval = 'l';
private:
	int *id;
};
struct Base2 {
	void print(double)const{}
protected:
	double fval;
private:
	double dval;
};

struct Derived : public Base1 {
	void print(std::string) const {}
protected:
	std::string sval = "a";
	double dval = 5;
};
struct MI : public Derived, public Base2 {
	void print(std::vector<double>){}
	void foo(double cval);
public:
	int *ival;
	std::vector<double> devc;
};
int ival;
double dval;
void MI::foo(double cval) {
	int dval;
	cout << ival << endl;
	dval = Base1::dval + Derived::dval;
	cout << "dval:" << dval << endl;

	// d
	Base2::fval = devc.back();
	cout << "d" << endl;
	Derived::sval[0] = Base1::cval;
	cout << Base1::cval << endl;
	cout << Derived::sval << endl;

	int a = dval;
	//print();
}

int main()
{
	int a;

	Panda *p1 = new Panda();
	//p1->max_weight(3);
	//cout << p1->Bear::max_weight() << endl;

	cout << p1->max_weight() << endl;

	cout << "-----------" << endl;
	//MI mi;
	//mi.print(3);

	MI *mi = new MI();
	vector<double> ve{ 12.3,12.9 };
	mi->devc = ve;
	mi->Base1::print(12);
	mi->foo(3);

	string ts = "dsf";
	ts[0] = 'd';
	cout << ts;
	/*
	练习：
	18.26:
	是int不能转换为vector<int>
	令其动态分配内存,可以是base2，或者base1为静态类型

	18.27：
	a.
	：：ival
	::dval
	MI::ival dvec print
	Derived::sval,dval print
	Base1::ival,dval,cval print
	base2:fval print
	局部:cval dval
	b.
	dval,即使private也是会的
	print

	c
	dval = Base1::dval + derived::dval;

	d

	e
	sval[0] = base1::cval;



	*/
	cin >> a;
	return 0;
}
