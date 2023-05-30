#include <iostream>
#include <string>

template <typename T> class Pal2;

class C1 {
	friend class Pal2<C1>;// ���� ��C1
	template <typename T> friend class Pal3;// ����
private:
	void prints() {
		cout << "class C1" << endl;
	}
};

template <typename T>
class Pal1 {
	// ��ͬʵ��
	friend class Pal2<T>;
	// ȫ��ʵ��
	template <typename X> friend class Pal3;

	// ��ģ���� ȫ��ʵ��
	friend class C2;

	friend  T;//�Լ�ģ�������ʵ��Ϊ��Ԫ
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