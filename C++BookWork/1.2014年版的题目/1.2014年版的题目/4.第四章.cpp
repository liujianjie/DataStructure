#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#pragma warning(disable:4996)

class T1 {
public:
	T1() {

	}
	void fun1() {
		this->val = 2;
	}
	static void fun2() {
		
	}
	int val;
	const static int val1 = 5;
};


class B {
private:
	void fun1(){}
protected:
	void fun2() {}
public:
	void fun3() {}
};
class D :public B {
	friend istream& operator >> (istream& is, D &d) {
		is >> d.val1;
		return is;
	}
protected:
	void fun4(){}
	public:
	int val1;
};


//template<typename T>
//void swaps(T a[], T b[], int size){}

template<class T1, class T2>
void swaps(T1 a[], T2 b[], int size) {}

class MyClass {
public:
	MyClass(){}
	MyClass(int d) { data = d; }
	virtual void fun() {
		MyClass::data = 3;
	}
	virtual void fun(int a) {
		MyClass::data = 3;
	}
	virtual void fun(double b) {
		MyClass::data = 3;
	}
	//static virtual void fun2() {}
	~MyClass(){}
private:
	int data;
};
class Dervied : public MyClass {
public:
	Dervied() {

	}
	virtual void fun() {
		cout << "fun()" << endl;
	}
	virtual void fun(int a) {
		cout << "fun(int)" << endl;
	}
	virtual void fun(double b) {
		cout << "fun(double)" << endl;
	}
};
int main()
{
	MyClass myc1(2);
	myc1.fun();

	MyClass* myc2 = new Dervied;
	short st1 = 2;
	float ft1 = 2.0f;
	long lg1 = 2;
	myc2->fun(lg1);

	int ara[10], arb[10];
	swaps(ara, arb, 10);
	//int D\max;
	//int* v1, v2 = 3;
	int a = 1,b = 2,*cp = &a;
	int *ptr = cp;
	ptr = &b;
	cout << *cp << endl;
	cout << ptr << endl;
	cout << cp << endl;

	// 15
	cout << "----" << endl;
	char ab[] = "Hello";
	//char a[5] = "Hello";
	char abc[2][5] = { "Hell"};
	cout << (abc[0]) << endl;

	float fv1 = 2.0f, fv2 = 4.0f;
	//int fv3 = fv1 % fv2;

	D obj;
	obj.fun3();
	
	//B Bb1;
	//Bb1.fun2();

	//cin >> obj;
	//cout << obj.val1 << endl;

	// 31
	/*ifstream fin;
	fin.open("test.txt",ios_base::out);
	fin.close();*/
	//ofstream fin;
	//fin.open("test.txt", ios_base::out);
	//fin.close();
	fstream fin;
	fin.open("test.txt", ios_base::out);
	fin.close();

	//MyClass arrays[2];
	//MyClass arrays[2] = { MyClass(5) };
	//MyClass arrays[2] = { MyClass(5),MyClass(6) };
	MyClass *arrays[2] = { new MyClass(2) };

	unsigned int uiv = -39;
	cout << uiv << endl;
	cin >> a;
	return 0;
}