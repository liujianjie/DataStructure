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
		cout << "ZooAnimal(string s)" << endl;
	}
	ZooAnimal(const ZooAnimal& b) {
		cout << "ZooAnimal(const ZooAnimal& b) {" << endl;
	}
	virtual ~ZooAnimal() {
		cout << "~ZooAnimal()" << endl;
	}
	void x() {
		cout << "zooanimal x()" << endl;
	}
public:
	int zoo = 1;
	string s;
};
class Bear :virtual public ZooAnimal {
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
	void x() {
		cout << "Bear x()" << endl;
	}
public:
	int bea = 2;
	string s;
};
class Racoon :public virtual ZooAnimal {
public:
	virtual void print() {
		cout << "Racoon::print()" << endl;
	}
	Racoon() {
		cout << "Racoon()" << endl;
	}
	Racoon(string s) :s(s) {
		cout << "Racoon(string s)" << endl;
	}
	Racoon(const Racoon& b) :ZooAnimal(b) {
		cout << "Racoon(const Racoon& b) {" << endl;
	}
	virtual ~Racoon() {
		cout << "~Racoon()" << endl;
	}
	//18.3.3
	//private:
	double max_weight()const {
		return 10.0;
	}
public:
	int rac = 6;
	string s;
};
class EndageredBase {
public:
	virtual void print() {
		cout << "EndageredBase::print()" << endl;
	}
	virtual void highlight() {
		cout << "EndageredBase::highlight()" << endl;
	}
	EndageredBase() {
		cout << "EndageredBase()" << endl;
	}
	EndageredBase(string s) :s(s) {
		cout << "EndageredBase(string s)" << endl;
	}
	EndageredBase(const EndageredBase& b) {
		cout << "EndageredBase(const EndageredBase& b) {" << endl;
	}
	virtual ~EndageredBase() {
		cout << "~EndageredBase()" << endl;
	}
	double max_weight(int a) const {
		return 20.0;
	}
	void x() {
		cout << "EndageredBase x()" << endl;
	}
public:
	string s;
	int end = 7;
};
class Endangered:public virtual EndageredBase {
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
	void x() {
		cout << "Endangered x()" << endl;
	}
public:
	string s;
	int enda = 3;
};
class Panda :public Bear, public Racoon, public Endangered {
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
	Panda():ZooAnimal(),Bear(),Racoon(),Endangered() {
		cout << "Panda()" << endl;
	}
	Panda(string s) :s(s), ZooAnimal(s), Racoon(s),Bear(s), Endangered(s) {
		cout << "Panda(string s)" << endl;
	}
	Panda(const Panda& b) :Bear(b), Endangered(b) {
		cout << "Panda(const Panda& b) {" << endl;
	}
	virtual ~Panda() {
		cout << "~Panda()" << endl;
	}
	double Panda::max_weight() const {
		return std::max(Bear::max_weight(), Endangered::max_weight(3));
	}
	void x() {
		cout << "Panda x()" << endl;
	}
public:
	string s;
	int pand = 4;
};

class Class {
public:
	Class() {
		cout << "Class()" << endl;
	}
};
class Base :public Class {
public:
	Base() {
		cout << "Base()" << endl;
	}
	Base(int i) {
		cout << "Base(int)" << endl;
	}
	Base(const Base&) {
		cout << "Base(const Base&)" << endl;
	}
};
class D1 :virtual public Base {
public:
	D1() {
		cout << "D1()" << endl;
	}
	D1(int i):Base(i) {
		cout << "D1(int)" << endl;
	}
	D1(const D1& d):Base(d) {
		cout << "D1(const D1&)" << endl;
	}
};
class D2 :virtual public Base {
public:
	D2() {
		cout << "D2()" << endl;
	}
	D2(int i) :Base(i) {
		cout << "D2(int)" << endl;
	}
	D2(const D1& d) :Base(d) {
		cout << "D2(const D2&)" << endl;
	}
};
class MI :public D1, public D2 {
public:
	MI() {
		cout << "MI()" << endl;
	}
	MI(int i) :Base(i),D1(i),D2(i) {
		cout << "MI(int)" << endl;
	}
	MI(const MI& d) :Base(d), D1(d), D2(d) {
		cout << "MI(const MI&)" << endl;
	}
};
// final是虚继承的子类的子类，但是也是先构造虚基类，所以也要显示Base(i)
class Final :public MI, public Class {
public:
	Final() {
		cout << "Final()" << endl;
	}
	Final(int i) :Base(i), MI(i),Class() {
		cout << "Final(int)" << endl;
	}
	Final(const MI& d) :Base(d),MI(d), Class() {
		cout << "Final(const MI&)" << endl;
	}
};
int main()
{
	int a;
	//Panda p1;

	//cout << "---------" << endl;
	//Panda p2("zxcv");

	//cout << "---------" << endl;
	//Panda p3 = p2;

	//cout << "---------" << endl;
	//Panda *p4 = new Panda();
	//cout << "---------" << endl;
	//delete p4;

	//Final fi;
	//Base *pb;
	//Class *pc;
	//MI *pmi;
	//D2 *pd2;
	//pb = new Class;
	//pc = new Final;
	//pmi = pb;
	//pd2 = pmi;
	Final fi(2);
	/*
	练习：
	18.29:
	a. 作对了 就是细节 少了Final
	构造：Class Base D1 D2 MI Class Final

	b.
	一个base，两个class

	c. 作对了
	1.错 2.对 
	3.错 4.对

	18.30:


	*/
	cin >> a;
	return 0;
}
