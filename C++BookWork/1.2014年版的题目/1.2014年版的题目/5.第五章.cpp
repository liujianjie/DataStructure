#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#pragma warning(disable:4996)


class T1 {
public:
	operator int() {
		cout << "operator int()" << endl;
		return 1;
	}
};

class T2 {
public:
	long n;
	T2(int i):n(i){}
	T2 operator+(T2 t) {
		return T2(n + t.n);
	}
};

int main()
{
	int a;

	T1 t;

	int val1 = t + 2;

	T2 t1(2);
	//3 + t1;
	//t1 + 3;
	//3 + 3;

	cin >> a;
	return 0;
}