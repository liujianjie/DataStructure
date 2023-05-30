#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "ZooClass.h"
#include "AllClass.h"
using namespace std;

class Base {
public:
	Base(){
	
	}
	virtual ~Base() {
		
	}
};
class Derived : public Base{
public:
	Derived() {

	}
	virtual ~Derived() {

	}
};

class Base2 {
public:
	Base2() {

	}
};
class Derived2 :public Base2{
public:
	Derived2() {

	}
};
int main()
{
	int a;

	Derived *dp = new Derived;
	Base *bp = dp;
	if (typeid(*bp) == typeid(*dp)) {
		cout << "is same object" << endl;
	}
	if (typeid(*bp) == typeid(Derived)) {
		cout << "is Derived" << endl;
	}
	if (typeid(bp) == typeid(Derived)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
		//cout << "typeid(bp)" << typeid(bp) << endl;
	}

	Base2 *b2 = new Derived2;
	if (typeid(*b2) == typeid(Derived2)) {
		cout << "is Derived2" << endl;
	}else if (typeid(*b2) == typeid(Base2)) {
		cout << "is Base2" << endl;
	}
	Base2 *b3 = 0;
	if (typeid(*b3) == typeid(Base2)) {
		cout << "is Base2" << endl;
	}

	// 有虚函数不能是空指针
	//Base *b4 = 0;
	//if (typeid(*b4) == typeid(Base)) {
	//	cout << "is Base" << endl;
	//}

	cout << "----练习-----" << endl;

	Query_base* pb1 = 0;
	AndQuery *and1 = dynamic_cast<AndQuery*>(pb1);
	cout << and1 << endl;
	WordQuery *and2 = dynamic_cast<WordQuery*>(pb1);
	cout << and2 << endl;

	AndQuery& and3 = dynamic_cast<AndQuery&>(*pb1);
	cout << &and3 << endl;


	Query_base* pb5 = new WordQuery("sdf");
	Query_base* pb6 = new WordQuery("sddf");
	if (typeid(*pb5) == typeid(*pb6)) {
		cout << "is pb6" << endl;
	}
	if (typeid(*pb6) == typeid(AndQuery)) {
		cout << "is AndQuery" << endl;
	}
	else {
		cout << "not is AndQuery" << endl;
	}
	/*
	练习：
	19.6: 不会呀，因为query_base是 纯虚类

	19.7: 

	19.8:ok
	*/
	cin >> a;
	return 0;
}