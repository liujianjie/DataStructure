#include <iostream>
using namespace std;

class TestClass {
public:
	int age;
	static int number;
	static void Func1() {
		cout << number << endl;
	}
	void Func2() {
		cout << age << endl;
		cout << number << endl;
	}
};
int TestClass::number = 10;
int main()
{
	TestClass test1;
	test1.Func1();
	test1.Func2();
	return 0;
}

