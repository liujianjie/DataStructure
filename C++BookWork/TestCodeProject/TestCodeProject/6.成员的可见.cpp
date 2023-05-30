#include <iostream>
#include <string>
#include <random>
using namespace std;

class Base1 {
//	friend class Pal;
//protected:
//	int prot_mem;
//public:
//	int testconst;
//	void prints() {}
//private:
//	int testval1;
public:
	~Base1() {
		cout << "Base1::~Base1()" << endl;
	}
};
class Sneaky1 :public Base1 {
	//friend void clobber(Sneaky1&);
//	int j;
//	void testfun() {
//		prot_mem = 2;
//	}
//public:
//	int val2 = 0;
};

int main()
{
	int a;
	Sneaky1 *b1 = new Sneaky1;
	//b1->val2;
	Base1 *b2 = new Sneaky1;
	//b1->val2;
	delete b2;

	cin >> a;
	return 0;
}