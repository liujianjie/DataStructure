#include <iostream>
using namespace std;

class Base {
public:
	Base(int val1) : bval1(val1) {

	}
	int bval1;
};

class D1 : public Base {
public:
	D1(int val1) : val1(val1), Base(val1) {

	}
	int val1;
};

int main()
{
	int a;

	Base b1(1),*b2 = &b1;
	D1 d1(2),d2(3);
	b1 = d1;

	//d1 = b1; ����

	//cout << b1.val1 << endl;����
	b2 = &d2;
	cout << b2->bval1 << endl;// �����������ֵ
	//cout << b2->val1 << endl;// ��ʹ��ָ��������ò���


	


	cin >> a;
	return 0;
}