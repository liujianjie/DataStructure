#include <iostream>
#include <string>
#include <random>
using namespace std;

class Base {
public:
	virtual void eat() {
		cout << "Base eat()" << endl;
	}
	int val1 = 1;
protected:
	int val2 = 2;
private:
	int val3 = 3;
};
class Tiger : protected Base {
public:
	virtual void eat() {
		cout << val1 << endl;
		cout << val2 << endl;
		//cout << val3 << endl;
		cout << "Tiger eat()" << endl;
	}
};
class xiaoTiger : public Tiger {
public:
	void prints() {
		//cout << val1 << endl;
		cout << val2 << endl;
	}

};
// 非静态方法不能调用静态方法，反过来一样
class C1 {
public:
	static void counts() {
		static int i = 0;
		i++;
		cout << "i"<< i << endl;
		//cts();
	}
	static void cts() {
		//counts();
		default_random_engine e;
		uniform_int_distribution<unsigned> u(0, 9);
		cout << u(e) << endl;
	}
	// static  virtual void testme() {

	//}
protected:
	int val1 = 20;
};
class C2 : public C1 {
public:
	void testval() {
		cout << val1 << endl;
	}
};

class Base2 {
public:
	//virtual void rpse(){}
};
class Dots :public Base2 {
public:
	//virtual void rpse() {}
};
int main()
{
	int a;
	Tiger t;
	t.eat();

	C1 c1,c2,c3;
	c1.counts();
	c2.counts();
	c3.counts();

	c1.cts();
	c2.cts();
	c3.cts();

	C1 &c4 = *(new C1);
	c4.counts();

	C1 c5;
	//c5.v

	//C2 c2;
	//c2.val1

	xiaoTiger x1;
	x1.prints();
	//cout << x1.val1 << endl;

	Base2 *bs2 = new Dots();
	cout << typeid(*bs2).name() << endl;
	cin >> a;
	return 0;
}