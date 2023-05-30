#include <iostream>

using namespace std;

class Box {
public:
	//static virtual void Area() { }
};
class Box2 {
public:
	virtual void Area() = 0;
	void Say() {
		cout << "HEllo" << endl;
	}
};
void Dos();
class Box3 {
	friend void Dos() {
		cout << "Dos()" << endl;
	}
public:
};

class Box4 {
public:
	Box4(){}
	Box4(int val) :value1(val) {
		cout << "Box4()" << endl;
	}
	int value1;
};
class Box5 {
public:
	Box5() {
		cout << "" << endl;
	}
	Box5(int val):value2(val) {

	}
	Box4 box;
	int value2;
};
class Box6 :Box5 {
public:
	Box6() {
		cout << "Box6()" << endl;
	}
	Box6(int val) :Box5(val) {
		//Box5.box()
	}
	//~Box6(int val){}
};
//void Test(int val1 = 10, int val2) {

//}
class Box7 {
public:
	int m;
	int* p = &m;
	static int n;
	static void Say() {
		cout << "Hello" << endl;
	}
};
int Box7::n = 3;

class Box8 :public Box7{
public:
	
};
class Box9 {
public:
	void Say() {
		cout << "Box9" << endl;
	}
};
class Box10:public Box9 {
public:
	int Say() {
		cout << "Box10" << endl;
		return 1;
	}
};
void Say() {
	cout << "Say()" << endl;
}
int main() {

	Box10 b10;
	b10.Say();
	b10.Box9::Say();

	void (* p3)() = &Say;
	p3();
	
	int val2 = 1;
	int* p2 = &val2;
	int*& ip2 = p2;
	Box8 b8;
	cout << b8.n << endl;
	b8.Say();

	Box7 b7;
	(* b7.p) = 3;
	cout << b7.m << endl;

	cout << '\005' << endl;
	Box6* b6 = new Box6();
	int a[10] = { 0, 11, 12, 13, 14, 15, 16, 17 };
	int* p = a;
	int val = p[3];
	cout << val << endl;
	int arr[4] = {};
	int(* p1)[4] =& arr;
	cout << (8 & 3) << endl;
	Dos();
	//Box2 b2;

	//Say();
	return 0;
}
//void Say() {
//	cout << "Hello." << endl;
//}