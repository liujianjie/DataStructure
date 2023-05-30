#include <iostream>
using namespace std;

class T2 {
public:

	T2(int v):val1(v)
	{
		
	}
	T2 operator +(T2 t) {
		return T2(val1 + t.val1);
	}
	T2 operator+=(T2 t) {
		*this = *this + t;
		return *this;
	}
	int val1;
};
ostream& operator << (ostream& os, T2 t) {
	os << t.val1;
	return os;
}

//operator =(T2 t1, T2 t2)
//{
//
//}

class T3 {
public:
	//operator int() {
	//	return val1;
	//}
	T3(int v) :val1(v)
	{

	}
	int val1;
};
T3 operator +(T3 t, T3 val1) {
	return (t.val1 + val1.val1);
}


class T4 {

public:
	T4& operator++() {
		cout << "T4 operator++() " << endl;
		return *this;
	}
	T4 operator++(int a) {
		cout << "T4 operator++(int) " << endl;
		return *this;
	}
};

int main()
{
	int a;
	T2 t1(1), t2(2);
	cout << (t1 + t2) << endl;

	int a2 = (t1 += t2).val1;
	cout << t1.val1 << endl;
	cout << a2 << endl;

	int i = 1;
	cout << (++++++i) << endl;

	T3 tt3(2);
	T3 tt4 = tt3 + 5;
	cout << tt4.val1 << endl;


	cout << (6 + tt3).val1 << endl;

	cout << (8.0 / 3.0) << " "<<(8.0 / 3) << endl;
	cout << (8.0 / 3.0) << " " << (8 / 3) << endl;
	cout << (8 / 3.0) << " " << (8 / 3) << endl;
	cout << (8.0 / 3) << " " << (8 / 3) << endl;

	int va = 31;
	cout << (--va / 15.0) << endl;

	cout << endl;
	T4 t41;
	t41++;
	++t41;
	cin >> a;
	return 0;
}