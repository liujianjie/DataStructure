#include <iostream>
using namespace std;

class AA {
public:
	virtual void f() { cout << "AA"; }
};

class BB :public AA {
public:
	BB() { cout << "BB"; }
};
class CC :public BB {
public:
	virtual void f() { 
		BB::f();
		cout << "CC";
	}
};

// 3
class Person {
public:
	Person() { cout << "Constructor of person" << endl; }
	~Person() { cout << "Destructor of person" << endl; }
};

class Student : public Person {
public:
	Student() { cout << "Constructor of Student" << endl; }
	~Student() { cout << "Destructor of Student" << endl; }
};
class Teacher : public Person {
public:
	Teacher() { cout << "Constructor of Teacher" << endl; }
	~Teacher() { cout << "Destructor of Teacher" << endl; }
};

void fun() {
	Student s;
	Teacher t;

}
int main()
{
	int a;
	//AA aa, *p;
	//BB bb;
	//CC cc;
	//p = &cc;
	//p->f();

	fun();

	cin >> a;
	return 0;
}