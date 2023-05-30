#include <iostream>
#include <string>
#include <random>
using namespace std;

class Base1 {
	friend class Pal;

protected:
	int prot_mem;
public:
	int testconst;
	void prints(){}
private:
	int testval1;
};
class Sneaky1 :protected Base1 {
	friend void clobber(Sneaky1&);
	//friend void clobber(Base1&);// 不可
	int j;
	void testfun() {
		prot_mem = 2;
	}
public:
	using Base1::testconst;
	using Base1::prints;

};
void clobber(Sneaky1 &s) { s.j = s.prot_mem = 0; }
//void clobber(Base1 &s) { s.prot_mem = 0; }
class Pal {
public:
	int f(Base1 b) { return b.prot_mem; }
	//int f2(Sneaky1 s) { return s.j; }
	int f3(Sneaky1 s) { return s.prot_mem; }// 对基类的访问权限由基类本身控制，派生类的基类部分也是如此
};

class Base2 {
public:
	void testWay() {}
public:
	void pub_mem() { cout << "Base:pub_mem()" << endl; }
public:
	int val33;
protected:
	int prot_mem;
private:
	char priv_mem;
};
struct Pub_Derv1 : public Base2 {
	int f()
	{
		pub_mem();
		return prot_mem;
	}
	char g() {
		//return priv_mem;// error
	}
	void memfcn(Base2 &b) { b = *this; }
};
struct Prot_Derv1 : protected Base2 {
	int f()
	{
		//Prot_Derv1 p;
		//Base2* b = &p;
		//testWay();
		pub_mem();
		return prot_mem;
	}
	char g() {
		//return priv_mem;// error
	}
	void memfcn(Base2 &b) { b = *this; }
};
struct Dervied_from_Protected : public Prot_Derv1 {
	void memfcn(Base2 &b) { b = *this; }
	int use_base() { return prot_mem; }
	void use_base2() { testWay(); }
	void testchange(Prot_Derv1 &p)
	{
		pub_mem();
		Base2* bs = &p;
	}
	void testchange(Dervied_from_Protected &p)
	{
		Base2* bs = &p;
	}
};
struct Priv_Derv1 : private Base2 {
	void memfcn(Base2 &b) { b = *this; }
	// private 不影响派生类的访问权限
	int f1()const {
		//pub_mem();
		return prot_mem;
	}
	void testchange(Priv_Derv1 p)
	{
		pub_mem();
		p.pub_mem();
		Base2* bs = &p;
	}
public:
	int val = 0;
};
struct Dervied_from_Private : public Priv_Derv1 {
	//void memfcn(Base2 &b) { b = *this; }
	int use_base() {
		//return val33;
		return val;
	}
	//void testchange(Priv_Derv1 &p)
	//{
	//	pub_mem();
	//	Base2* bs = &p;
	//}
	void testchange(Dervied_from_Private &p)
	{
		//pub_mem();
		//Base2* bs = &p;
	}
};
int main()
{
	int a;
	Base1 b;
	//b.prot_mem;
	Sneaky1 s1;
	//s1.prot_mem;
	const Sneaky1 s2;
	s2.testconst;

	Pub_Derv1 d1;
	Priv_Derv1 d2;
	d1.pub_mem();
	//d2.pub_mem();
	d1.testWay();
	//d2.testWay();

	const Pub_Derv1 d3;
	//d3.pub_mem();

	Prot_Derv1 pd1;
	//pd1.testWay();
	//Base2 *bs21 = &pd1;

	Pub_Derv1 pb1;
	pb1.testWay();
	cin >> a;
	return 0;
}