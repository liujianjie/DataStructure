#include <iostream>
#include <string>
#include <random>
using namespace std;

class Base {
public:
	virtual void eat() = 0;
};
void Base::eat() {
	cout << "Base::eat()" << endl;
}
class Dervied :public Base {
public:
	void eat() {
		cout << "Dervied::eat()" << endl;
	}
};
int main()
{
	int a;
	Base *b = new Dervied;
	b->Base::eat();
	//Base b2;
	//Base *b3 = new Base;

	cin >> a;
	return 0;
}