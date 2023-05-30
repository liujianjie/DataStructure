#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

class Base {
public:
	Base() { cout << "Base()" << endl; }
};
class Derived : public Base {
public:
	Derived(){ cout << "Derived()" << endl; }
};


class XA {
	int a;
public:
	XA(int aa) :a(aa) { ++b; }
	static int b;
	int get() { return a; }
};
int XA::b = 0;

class BigNumber {
public:
	//operator long()const;
	//operator long(BigNumber);
	//long operator long()const;
	//long operator long(BigNumber)const;
	~BigNumber() {}
	//~BigNumber(int a) {}
};
//operator long(BigNumber b) {
//
//}

int main()
{
	int a;

	XA d1(1), d2(3);
	cout << d1.get() + d2.get() + XA::b << endl;

	//Derived d1;

	ifstream iss("create.txt");
	if (!iss) {
		cout << "no val" << endl;
	}
	if (!iss.eof()) {
		cout << "no val" << endl;
	}
	string s1;
	getline(iss, s1);
	//ofstream os("create2.txt");
	//os << "sdfdsf";

	string s2 = "sdf\tsf";
	const char* s3= "sdf\nsf";
	cout << s2.size() << endl;
	cout << s2.length() << endl;

	cout << s2 << endl;

	cout << s3 << endl;

	cout << internal << 123131245 << endl;
	cout << left << 12345 << endl;
	cout <<setw(3)<<right << 12345 << endl;
	cout << setw(6) << 12345 << endl;

	Derived *b3;
	//BigNumber (*ad) { 3 };
	cin >> a;
	return 0;
}

