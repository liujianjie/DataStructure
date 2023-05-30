#include <iostream>
using namespace std;

struct S1 {
	int a;
};
class Test1 {
	int value = 1;
public:
	int value2 = 3;
public:
	int Sum() {
		cout << "sum1" << endl;
		return 1;
	}
	int Sum() const {
		cout << "sum2" << endl;
		return 2;
	}
	static void Say() {
		cout << csa << endl;

	}
private:
	const static int csa = 3;
};
int main()
{
	S1 s;
	Test1 t1;
	s.a = 3;
	cout << s.a << endl;
	//cout << t1.csa << endl;
	t1.Sum();
	t1.Sum();
	const Test1 t2;
	t2.Sum();
	t2.Say();
	return 0;
}