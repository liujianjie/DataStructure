#include <iostream>
#include <string>

using namespace std;

class Base {
public:
	virtual void eat() {
		cout << "Base eat()" << endl;
	}

};
class Tiger :public Base{
public:
	virtual void eat() {
		cout << "Tiger eat()" << endl;
	}
};
int main()
{
	int a;

	int a2[] = { 0,0,0 };

	Base *b = new Tiger();
	b->eat();
	cout << typeid(*b).name() << endl;

	cin >> a;
	return 0;
}