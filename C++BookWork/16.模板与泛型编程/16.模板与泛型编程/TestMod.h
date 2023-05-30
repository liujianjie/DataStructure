#include <iostream>
#include <string>

template <typename T> class Pal2;

class C1 {
	friend class Pal2<C1>;// 部分 以C1
	template <typename T> friend class Pal3;// 所有
private:
	void prints() {
		cout << "class C1" << endl;
	}
};

template <typename T>
class Pal1 {
	// 相同实例
	friend class Pal2<T>;
	// 全部实例
	template <typename X> friend class Pal3;

	// 非模板类 全部实例
	friend class C2;

	friend  T;//自己模板参数的实例为友元
private:
	void prints() {
		cout << "class Pal1" << endl;
	}
};

template <typename T>
class Pal2 {
	Pal1<T> mypal1;
	C1 c1;
public:
	void printPal1() {
		mypal1.prints();
	}
	void printC1() {
		c1.prints();
	}
};

template <typename T>
class Pal3 {
	Pal1<double> p;
	C1 c1;
public:
	void printPal1() {
		p.prints();
	}
	void printC1() {
		c1.prints();
	}
};
class C2 {
	Pal1<double> p;
public:
	void printPal1() {
		p.prints();
	}
};

class C3 {
	Pal1<C3> p;
public:
	void printPal1() {
		p.prints();
	}
};