#include <iostream>

using namespace std;

class Base {
public:
	//Base(int a = 1,int b = 2) {
	//	cout << "no" << endl;
	//}
	Base() = default;
	Base(int a, int b = 2) {
		cout << "no" << endl;
	}
	int val2 = 2;
};
class Derived :public Base {
public:
	//Derived() {};
	Derived()=default;
	using Base::Base;
	int val1 = 1;
public:
	static void chang(){
		// cout << val1 << endl;
	}
};
int main()
{
	int a;
	//Derived d0();
	//Derived d1(2);
	//Derived d2(2,3);

	Derived d1;
	Base& ba1 = d1;
	ba1.val2;

	cin >> a;
	return 0;
}
