#include <iostream>
#include <string>
#include <map>
using namespace std;

class Base {
public:
	
	Base() = default;
	Base(int a, int b = 2) {
		cout << "no" << endl;
	}
	int val2 = 2;
};
class Derived :public Base {
public:
	//Derived() {};
	Derived() = default;
	using Base::Base;
	int val1 = 1;
public:
	static void chang() {
		// cout << val1 << endl;
	}
};

class Sal {
public:
	Sal& operator+(int a) {
		cout << "1" << endl;
		val = a;
		return *this;
	}
	//friend Sal operator--(Sal& s1,int);
	//Sal operator--(Sal&, int);
	int val;
	ostream& operator << (ostream &os) {
		os << (string)("sdf");
		return os;
	}
};
//ostream& operator << (const Sal&sl,ostream &os) {
//	os << (string)("sdf");
//	return os;
//}
//Sal operator--(Sal& s1,int)
//{
//	s1.val--;
//	return s1;
//}
Sal& operator+(Sal& s1,int a) {
	cout << "2" << endl;
	s1.val = a;
	return s1;
}
Sal& operator+(int a, Sal& s1) {
	cout << "3" << endl;
	s1.val = a;
	return s1;
}
//Sal& operator+(int a, int b) {
//	Sal s1;
//	return s1;
//}

#include <functional>
class Test1 {

};
int add(int i, int j) { return i + j; }
Test1 add(const Test1&, const Test1&);

class Test2 {
public:
	Test2& operator+(const Test2& t2) {
		cout << "1" << endl;
		Test2 t;
		return t;
	}
};
Test2& operator+(const Test2& t1, const Test2& t2) {
	cout << "2" << endl;
	Test2 t;
	return t;
}

class SmallInt {
	friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
	SmallInt(int = 0) {}
	operator int() const {
		cout << "operator int() const " << endl;
		return val;
	}
private:
	std::size_t val;
};
SmallInt operator+(const SmallInt&, const SmallInt&) {
	cout << "SmallInt operator+(const SmallInt&, const SmallInt&) " << endl;
	SmallInt sl;
	return sl;
}

int main()
{
	int a;
	Sal s1;
	//s1 + 4;
	4 + s1;
	cout << s1.val << endl;
	//s1--;
	cout << s1.val << endl;
	//Sal& s2 = new Sal;

	Sal s3;
	s3 << cout;

	map<string, function<int(int, int)>> binops;
	//binops.insert({ "+",add });
	
	//int i = 42;
	//while(cin >> i)
	cout << endl;
	Test2 t2,t1;
	t2.operator+(t1);
	operator+(t1,t2);

	t2 + t1;

	SmallInt s11, s22;
	SmallInt s33 = s11 + s22;
	//int i = s33 + 0;
	cin >> a;
	return 0;
}
