#include <iostream>
#include <iomanip>
#include <cstring>
//#include <string>
using namespace std;




// 16
void B() {
	cout << "B()" << endl;
}
void A();
void A() {
	B();
	cout << "A()" << endl;
}
void B();

// 17
//class AA{};
//class BB {
//	AA v1, *v2;
//	BB v3;
//	int *v4;
//public:
//	BB() {
//
//	}
//};

// 35
//class AA {
//public:
//	AA() { cout << '1'; }
//};
//class BB :public AA {
//	int k;
//public:
//	BB() { cout << '12'; }
//	BB(int n) { cout << '3'; }
//};


// 36
//class C1 {
//public:
//	~C1() { cout << 1; }
//};
//class C2 :public C1 {
//public:
//	~C2() { cout << 2; }
//};
// 40
//class A {
//	char *a;
//public:
//	A():a(0){}
//	A(char *aa) {
//		a = new char[strlen(aa) + 1];
//		strcpy(a, aa);
//	}
//	~A() { delete[]a; }
//};
//18
//class C1 {
//	//int c1 = 2;
//public:
//	
//};
//class C2 :public C1 {
//	int c2;
//public:
//	void count() {
//		//cout << c1 << endl;
//		cout << sizeof(C2) << endl;
//	}
//};
// 19
class C1 {
public:
	C1() = default;
	C1(int v):val1(v) {
	}
	//operator int() {
	//	return 0;
	//}
	operator int();
	int val1;

};
C1::operator int() {
	return val1;
}
int main()
{
	int a;
	//A();
	// 35
	//BB b(4), c;
	//cout << '12' << endl;

	// 36
	//C2 cb2;
	//C1 *cb1;

	// 39
	//int s[] = { 123,235 };
	//cout << setfill('*') << setw(6);
	//for (int i = 0; i < 2; i++) {
		//cout << s[0] << endl;
		//cout << s[1] << endl;
	//}

	// 40
	//char *a1 = "asdfasd";
	//char *a2 = new char[strlen(a1) + 1];
	//strcpy(a2, a1);
	//cout << a1 << endl;
	//cout << a2 << endl;
	// 25:
	//int arr[5] = { 1,2,3,4,5 };
	//cout << *arr + 1 << endl;

	//18
	//C2 c2;
	//c2.count();

	C1 c1(20);
	int a2 = c1;
	cout << a2 << endl;

	cin >> a;
	return 0;
}