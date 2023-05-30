#include <iostream>
using namespace std;

struct S1 {
	int a;
};
class Test1 {
	int value = 1;
public:
	int value1 = 2;
public:
	int Sum() {
		cout << "sum1" << endl;
		return 1;
	}
	int Sum() const {
		cout << "sum2" << endl;
		return 2;
	}

private:
	const static int a = 1;
};

class Test2 : protected Test1 {
	friend void Say() {
		cout << "hello" << endl;
	}
public:
	void Say() {
		cout << value1 << endl;
	}
	~Test2() {

	}
};

int TestFun1() {
	cout << "TestFun1()" << endl;
	return 0;
}

// 初始化不能越级
class T1 {
public:
	int n;
};
class T2 :public T1 {
public:
	//T2() :n(2) {
	//}
	T2() {
		n = 2;
	}
};
int main()
{
	int(* p)() = TestFun1;
	p();
	//Test2::Say();
	Test1 t;
	t.Sum();
	const Test1 t2;
	t2.Sum();
	//cout << t.value;

	int m = 3;
	//int* p = m;
	//int& p = *m;
	while (int i = 0) {
		i--;
		cout << "1" << endl;
	}
	Test2 tt2; 
	//tt2.value1 = 3;
	tt2.Say();

	 int * const p1 = &m;
	*p1 = 4;
	int c = 2;
	//p1 = &c;

	S1 s;
	s.a = 3;

	char c1 = '\005';
	cout << c1 << endl;

	char s1[] = "C++";
	char s2[4] = "C++";
	char s3[4] = { 'C', '+', '+'};
	char s4[4] = { 'C', '+', '+', '\0'};
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	for (int i = 0; i < 4; i++) {
		break;
		break;
	}
	return 0;
}