#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Partice157.h"
#include "Disc_quote.h"

using namespace std;

/*
引出：
拷贝控制成员，操作了派生类也要操作基类部分的成员
1.不同的是析构函数只负责销毁派生类自己分配的资源。对象的成员是被隐式销毁的，类似的，派生类对象的基类部分也是自动销毁的

note：当派生类定义了拷贝或移动操作时，该操作负责拷贝或移动包括基类部分成员在内的整个对象

二、定义派生类的拷贝或移动构造函数
需要使用对应的基类构造函数初始化对象的基类部分
D(const D& d):B(d){}
将一个D对象传递给基类构造函数。道理上说，base可以有一个参数类型为D的构造函数，但通常不那么做
一般会匹配Base的拷贝构造函数，将参数d上的基类部分拷给要创建的对象

2.假如没有提供基类的初始值的话，基类的部分被默认初始化，很可能未定义的行为
note：基类默认构造函数初始化派生类对象的基类部分，若想拷贝或移动基类部分，必须在派生类的
构造函数初始化列表中显示地使用基类的拷贝或移动构造函数

三、派生类赋值运算符
也必须显示地为其基类部分赋值

显示的：那么无论基类的构造函数或赋值运算符是自定义的版本还是合成版本，派生类的对应操作都能使用它们。

四、派生类析构函数
析构函数体执行完成后，对象的成员会被隐式销毁。
对象的基类部分也是隐式销毁的。
和构造函数及赋值运算符不同的是，派生类析构函数只负责销毁由派生类自己分配的资源：

Base::~Base被自动调用执行
对象销毁的顺序正好与其创建的顺序相反：派生类析构函数首先执行，然后是基类的析构函数，沿着继承体系的反方向直至最后

五、在构造函数和析构函数中调用虚函数
基类部分首先被构建，基类构造函数运行时，派生类的部分是未被初始化状态
销毁派生类对象时，基类的析构函数运行时，派生类的部分已经被销毁掉了
则执行上述基类的成员时候，该对象处于未完成的状态，因为派生类并不完整未被初始化或销毁掉了

虚函数的调用绑定是把对象的类和构造函数的类看成同一个
为了能处理上述状态：
编译器认为对象的类型在构造或析构的过程中仿佛发生了改变一样，在我们构建一个对象时，需要把对象的类和构造函数的类看做是同一个
这样则基类构造函数运行时，对象的类为基类，那么执行虚函数则是基类版本的虚函数。
直接调用虚函数
间接调用：并且通过构造函数或析构函数调用另一个函数也是可以

假设上述行为没有执行，在基类的构造函数执行虚函数的派生类版本时，派生类成员未初始化，程序可能会崩溃。

note：如果构造函数或析构函数调用了某个虚函数，应该与我们执行构造函数或析构函数所属类型相对应得虚函数版本

*/
class B {
public:
	//B() = default;
	B() { 
		testvir();
	}
	//B(const B&) = delete;
	B(const B&) = default;
	B(B&&) = default;
	B& operator=(const B&) = default;
	B& operator=(B&&) = default;
	//virtual ~B() = default;
	virtual ~B()
	{
		testvir();
	}
	virtual void testvir() { cout << "B:  testvir()" << endl; }
};
class D :public B {
public:
	D():B(){}
	D(const D& d):B(d){}
	D(D&& d):B(std::move(d)){}
	D& operator=(const D &rhs);
	// B::~B被自动调用执行
	~D(){/* 该处由用户定义清楚派生类成员的操作*/
		testvir();
	}

	virtual void testvir() { cout << "D:  testvir()" << endl; }
};
D &D::operator=(const D &rhs)
{
	// 显示的调用
	B::operator=(rhs);
	return *this;
}
// 练习
class Quote1 {
public:
	Quote1() {
		cout << "Quote1()" << endl;
	}
	Quote1(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}

	Quote1(const Quote1&)
	{
		cout << "Quote1(const Quote1&)" << endl;
	}
	Quote1(Quote1&&)
	{
		cout << "Quote1(Quote1&&)" << endl;
	}
	Quote1& operator=(const Quote1& q1) {
		cout << "Quote1& operator=(const Quote1&) " << endl;
		return *this;
	}
	Quote1& operator=(Quote1&&) {
		cout << "Quote1& operator=(Quote1&&)" << endl;
		return *this;
	}

	std::string isbn() const { return bookNo; }

	virtual double net_price(std::size_t n)const
	{
		return 0;
	}
	// 对析构函数进行动态绑定
	virtual ~Quote1(){ cout << "~Quote1()" << endl; }

	void Quote_quoteMethod()
	{
		cout << "Quote_quoteMethod()" << endl;
	}
	virtual void testMorenShi(int val = 2) {
		cout << "Quote::testMorenShi:" << val << endl;
	}
	virtual void debug()
	{
		cout << "price:" << price << "val:" << val1 << "bookNo:" << bookNo << endl;
	}
protected:
	double price = 0.0;
public:
	int val1 = 10;
	std::string bookNo;
};
class Disc_quote1 : public Quote1
{
public:
	Disc_quote1():Quote1() {
		cout << "Disc_quote1()" << endl;
	}
	Disc_quote1(const std::string& book, double price,
		std::size_t qty, double disc) :
		Quote1(book, price),
		quantity(qty), discount(disc) {
		cout << "Disc_quote1(const std::string& book, double price,std::size_t qty, double disc)" << endl;
	}

	Disc_quote1(const Disc_quote1&)
	{
		cout << "Disc_quote1(const Disc_quote1&)" << endl;
	}
	Disc_quote1(Disc_quote1&&)
	{
		cout << "Disc_quote1(Disc_quote1&&)" << endl;
	}
	Disc_quote1& operator=(const Disc_quote1& q1) {
		cout << "Disc_quote1& operator=(const Disc_quote1&) " << endl;
		return *this;
	}
	Disc_quote1& operator=(Disc_quote1&&) {
		cout << "Disc_quote1& operator=(Disc_quote1&&)" << endl;
		return *this;
	}
	virtual ~Disc_quote1() { cout << "~Disc_quote1()" << endl; }

	virtual double net_price(std::size_t)const = 0;
	std::pair<size_t, double> discount_policy() const
	{
		return{ quantity, discount };
	}
protected:
	std::size_t quantity = 0;// 折扣适用的购买量
	double discount = 0.0;// 表示折扣的小数值
};

class Bulk_quote1 :public Disc_quote1 {
public:
	Bulk_quote1() :Disc_quote1(){
		cout << "Bulk_quote1()" << endl;
	}
	//Bulk_quote():Disc_quote("",0,0,0){}
	Bulk_quote1(const std::string& book, double p, std::size_t qty, double disc)
		: Disc_quote1(book, p, qty, disc)
	{
		cout << "Bulk_quote1(const std::string& book, double p, std::size_t qty, double disc)" << endl;
		//bookNo = books; //倘若bookNo是私有的 就不可访问
		//price = p;
	}
	Bulk_quote1(const Bulk_quote1&)
	{
		cout << "Bulk_quote1(const Bulk_quote1&)" << endl;
	}
	Bulk_quote1(Bulk_quote1&&)
	{
		cout << "Bulk_quote1(Bulk_quote1&&)" << endl;
	}
	Bulk_quote1& operator=(const Bulk_quote1& q1) {
		cout << "Bulk_quote1& operator=(const Bulk_quote1&) " << endl;
		return *this;
	}
	Bulk_quote1& operator=(Bulk_quote1&&) {
		cout << "Bulk_quote1& operator=(Bulk_quote1&&)" << endl;
		return *this;
	}
	virtual ~Bulk_quote1() { cout << "~Bulk_quote1()" << endl; }
	double net_price(std::size_t)const override
	{
		return 0;
	}
	void Bulk_quoteMethod()
	{
		cout << "Bulk_quoteMethod()" << endl;
	}
	virtual void testMorenShi(int val = 3) {
		//Quote::testMorenShi();
		cout << "Bulk_quote::testMorenShi:" << val << endl;
	}
	virtual void debug()
	{
		cout << "min_qty:" << quantity << "discount:" << discount << endl;
	}
};

int main()
{
	int a;

	B *b1 = new D();
	delete b1;

	cout << "----" << endl;
	//Bulk_quote1 bk1;
	Quote1 *qt1 = new Bulk_quote1();
	delete qt1;
	// 练习
	/*
	15.26: ok
	*/
	cin >> a;
	return 0;
}
