#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#pragma warning(disable:4996)
// 30
template<typename>
class T1 {

};

//
class T2 {
	char cs;
public:
	T2(char c):cs(c) { cout << "T2();" << cs << endl; }
};
class Myclass {
	int x;
public:
	T2 b;
	T2 a;
	T2 c;
public:
	Myclass():c('c'),b('b'),a('a'){}
};

// 34
class T3 {
	char a;
	const char b;
	char &cs;
public:
	T3(char c):b(c),cs(c)
	{
		a = c;
		//b = c;
	}
	void f(char a)const
	{
		//this->a = a;

	}
	void g(char b)
	{
		//this->b = b;
	}
	char h() const
	{
		return a;
	}
};

//36

class Base {
public:
	void fun() { cout << 'B'; }
};
class Derived :public Base {
public:
	void fun()
	{
		Base::fun();
		//cout.flush();
		cout << "D" << endl;
	}
};

// 37
class B {
public:
	virtual void f() { cout << 'B'; }
	void g() { cout << 'B'; }
};
class D :public B {
public:
	void f() { cout << "D"; }
	void g() { cout << "D"; }
};
void h(B * p)
{
	p->f();
	p->g();
}


class T4 {

};
T4 operator+(T4 t, T4 t2)
{
	return t;
}
int main() 
{
	int a;
	T4 t1, t2;
	t1 = t1 + t2;
	//char aa;
	//cin >> aa;
	//if (aa == '*')
	//	cout << "**" << endl;
	//else
	//	cout << "###" << endl;
	//	
	Myclass my;

	char ch1 = 'a';
	char *ch2 = &ch1;
	cout << *ch2 << endl;

	Derived d;
	d.fun();

	D obj;
	h(&obj);

	cout << endl;
	ifstream infile("DATA.DAT");
	if (!infile.good())
		cout << "A";
	else {
		cout << "B";
		ofstream outfile("DATA.DAT");
		if (outfile.fail()) {
			cout << "C";
		}
		else{
			cout << "D";
		}
	}

	//string s1("hello"), s2(" world");
	char chr1[90];
	
	char *s1 = "hello";
	char *s2 = "world";
	char chr2[90];

	strcpy(chr1, s1);
	strcpy(chr2, s2);

	cout << chr1 << endl;
	strcat(chr2, chr1);
	cout << chr2 << endl;
	cin >> a;
	return 0;
}