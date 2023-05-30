#include <iostream>
#include "T1.h"

using namespace std;

class TestFrid1;
class TestFrid2 {
	friend class TestFrid1;// friend TestFrid1
public:
	TestFrid2(int a) :val1(a) {}
private:
	int val1 = 20;
public:
	int val2 = 30;
};

class TestFrid1 {
public:
	void doac(TestFrid2 t) {
		cout << t.val1 << endl;
	}
};

//
class Sample
{
public:
	Sample(int val) {}
	//~Sample() {}

	int f(int b, int a = 10) {
		return 0;
	}
	int f(int b)
	{
		return 1;
	}
public:
	int a = 2.5;
	Sample() {
		cout << "Sample()!!!!!" << endl;
	}
	~Sample() {
		cout << "~Sample()!!!!!!!" << endl;
	}
};
int main()
{
	int a;
	

	T1 t1;
	t1.say();

	t1.fanwenval1();

	T1::fanwenval1();

	cout << t1.val1 << T1::val1 << endl;

	const T1 t2;
	//t2.val2 = 0;
	t2.say(1);

	//
	cout << endl;
	TestFrid2 tf2(19);
	TestFrid1 tf1;
	tf1.doac(tf2);

	cout << tf2.val2 << endl;

	Sample s1;
	cout << s1.a << endl;
	//s1.f(2);

	Sample *s2;
	Sample *s3 = new Sample();
	cin >> a;
	return 0;
}