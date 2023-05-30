#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class ZooAnimal {
public:
	ZooAnimal() {
		cout << "ZooAnimal()" << endl;
	}
	ZooAnimal(string s) :s(s) {
		cout << "Bear(string s)" << endl;
	}
	ZooAnimal(const ZooAnimal& b) {
		cout << "ZooAnimal(const ZooAnimal& b) {" << endl;
	}
	virtual ~ZooAnimal(){
		cout << "~ZooAnimal()" << endl;
	}
private:
	string s;
};
class Bear :public ZooAnimal {
public:
	Bear() {
		cout << "Bear()" << endl;
	}
	Bear(string s):s(s) {
		cout << "Bear(string s)" << endl;
	}
	Bear(const Bear& b) :ZooAnimal(b) {
		cout << "Bear(const Bear& b) {" << endl;
	}
	virtual ~Bear() {
		cout << "~Bear()" << endl;
	}
private:
	string s;
};
class Endangered {
public:
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
private:
	string s;
};
class Panda :public Bear, public Endangered {
	using Bear::Bear;
	using Endangered::Endangered;
public:
	Panda() {
		cout << "Panda()" << endl;
	}
	Panda(string s):s(s),Bear(s),Endangered(s) {
		cout << "Panda(string s)" << endl;
	}
	Panda(const Panda& b):Bear(b),Endangered(b) {
		cout << "Panda(const Panda& b) {" << endl;
	}
	virtual ~Panda() {
		cout << "~Panda()" << endl;
	}
private:
	string s;
};

class CAD {

};
class Vehicle {

};
class CADVehicle :public CAD, Vehicle {

};
class List {

};
//class DbList :public List, public List {
//
//};
class istream {

};
class ostream {

};
//class iostream :public istream, public ostream {
//
//};

int main()
{
	int a;

	Panda p1;
	Panda p2("sdf");

	ZooAnimal *p3 = new Panda();
	delete p3;

	cout << "---------" << endl;
	Panda p4 = p2;
	/*
	练习：
	18.21:
	a.没错
	b.同一个基类不能被继承两次
	c.不明确 但正确，若没有using namespace std

	18.22:
	A
	B
	C
	X
	Y
	Z
	MI
	*/
	cin >> a;
	return 0;
}
