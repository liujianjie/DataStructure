#pragma once
#include <iostream>
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
class Endangered :public virtual EndageredBase {
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
	Panda() :ZooAnimal(), Bear(), Racoon(), Endangered() {
		cout << "Panda()" << endl;
	}
	Panda(string s) :s(s), ZooAnimal(s), Racoon(s), Bear(s), Endangered(s) {
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

