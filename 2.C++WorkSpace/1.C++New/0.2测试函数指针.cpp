#include <iostream>
using namespace std;

class Student {
public:
	int age;
	Student() {

	}
	void Say() {
		cout << "hello" << endl;
	}
};
int main()
{
	Student st[50];
	st[9].Say();

	void(Student:: * p)() = &Student::Say;
	(st[0].*p)();

	return 0;
}