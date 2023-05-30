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
class Racoon :public virtual ZooAnimal{
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
	void x() {
		cout << "Endangered x()" << endl;
	}
public:
	string s;
	int enda = 3;
};
class Panda :public Bear,public Racoon,  public Endangered {
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
		return std::max(Bear::max_weight(),Endangered::max_weight(3));
	}
	void x() {
		cout << "Panda x()" << endl;
	}
public:
	string s;
	int pand = 4;
};

void dance(const Bear&)
{
	cout << "void dance(const Bear&)" << endl;
}
void rummage(const Racoon&)
{
	cout << "void rummage(const Racoon&)" << endl;
}
ostream& operator<<(ostream& os, const ZooAnimal&)
{
	os << "ostream& operator<<(ostream&, const ZooAnimal&)" << endl;
	return os;
}

int main()
{
	int a;
	Panda *pa1 = new Panda();
	//int z = pa1->zoo;// 会不明确
	//int z1 = pa1->Bear::zoo;
	int z2 = pa1->zoo;// 明确了
	cout << z2 << endl;

	cout << "------" << endl;
	Panda yin;
	dance(yin);
	rummage(yin);
	cout << yin;
	cout << "----------" << endl;

	yin.x();

	/*
	练习：
	18.28:
	直接访问 bar ival,只有一条路径覆盖
	需要限定符 foo cval 两条路径都覆盖

	*/
	cin >> a;
	return 0;
}
