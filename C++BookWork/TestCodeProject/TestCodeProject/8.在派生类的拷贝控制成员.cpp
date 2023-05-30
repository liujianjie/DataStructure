#include <iostream>

using namespace std;

class Base {
public:
	Base() {
		eat();
	}
	virtual void eat() {
		cout << "Base::eat()" << endl;
	}
};
class Derived :public Base {
public:
	virtual void eat() {
		cout << "Derived::eat()" << endl;
	}
};
int main()
{
	int a;
	Base *b = new Derived;
	

	cin >> a;
	return 0;
}
