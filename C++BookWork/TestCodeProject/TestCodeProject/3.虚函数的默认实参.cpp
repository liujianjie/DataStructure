#include <iostream>
#include <string>
#include <random>
using namespace std;

class Base {
public:
	virtual void eat(int val = 1) {
		cout << "Base eat()" << val<< endl;
	}
	int val1 = 1;
protected:
	int val2 = 2;
private:
	int val3 = 3;
};
class Tiger : public Base {
public:
	virtual void eat(int val = 2) {
		cout << "Tiger eat()" << val << endl;
	}
	//virtual void eat() {
		//cout << val1 << endl;
		//cout << val2 << endl;
		//cout << val3 << endl;
		/*cout << "Tiger eat()" << endl;
	}*/
};
int main()
{
	int a;
	Base *b = new Tiger;
	b->eat();

	Tiger t;
	t.eat();

	cin >> a;
	return 0;
}