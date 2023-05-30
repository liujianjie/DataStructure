#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Partice157.h"
#include "Disc_quote.h"

using namespace std;

/*
自己的认为：
就是在基类中有许多构造函数，在派生类中若想使用而不用显示调用，直接using 基类：：基类构造函数
则编译器都生成一个与之对应的派生类构造函数，无需显示定义派生类的构造函数，可以使用派生类的构造函数，并且调用父类的相应构造函数

引出：
这些定义的构造函数不是默认的构造函数，是新定义的构造函数
类能够重用其直接基类定义的构造函数。
这些构造函数并非以常规方式继承而来的，为了方便，姑且陈为：继承的
1.一个类只继承其直接基类的构造函数
2.类不能继承默认、拷贝和移动构造函数
3.如果派生类没有直接定义这些构造函数，则编译器将为派生类合成它们

使用using声明语句对基类的构造函数声明，则再派生类中让编译器产生代码。
对于基类的每个构造函数（除了上述情况2外）编译器都生成一个与之对应的派生类构造函数，形参列表完全相同的构造函数

但代码中却可以实现直接基类的拷贝构造函数，间接基类不行

derived(parms) : base(args){ }

tips:如果派生类含有自己的数据成员，则这些成员将被默认初始化，因为上面的构造函数并不会执行派生类的成员初始化

二、继承的构造函数的特点
1.using声明不能指定explicit或constexpr，若基类的构造函数是explicit或constexpr的则继承的构造函数也拥有相同的属性
2.一个基类构造函数含有默认实参，生成两个继承的构造函数，若：基类的构造函数有两个形参，第二个形参含有默认实参的形参
则：派生类获得两个构造函数：
一个构造函数接受两个形参（没有默认实参）
另外一个构造函数只接受一个形参，对应与基类中最左侧的没有默认值的那个形参

3.除了两个例外，using都会继承这些构造函数
1）派生类定义了与派生类相同的参数列表，则这些构造函数不会被继承 替换继承而来的构造函数
2）是默认、拷贝和移动构造函数不会被继承。因为在派生类中这些函数按照正常规则合成。
继承的构造函数不会被作为用户定义的构造函数来使用
则像1）一样会替换继承而来的构造函数

但代码中却可以实现直接基类的拷贝构造函数，间接基类不行
*/

class Quote1 {
public:

	Quote1() {
		cout << "Quote1()" << endl;
	}
	Quote1(const std::string &book, double sales_price) : bookNo(book), price(sales_price) 
	{
		cout << "Quote1(const std::string &book, double sales_price) : bookNo(book), price(sales_price) " << endl;
	}

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
	// 对析构函数进行动态绑定
	virtual ~Quote1() { cout << "~Quote1()" << endl; }
protected:
	double price = 0.0;
public:
	int val1 = 10;
	std::string bookNo;
};
//class Disc_quote1 : public Quote1
//{
//public:
//	// test
//	Disc_quote1(double price,double disc = 3.1)
//	{
//		cout << "Disc_quote1(double price, double disc = 3.1)" << endl;
//	}
//
//	Disc_quote1() :Quote1() {
//		cout << "Disc_quote1()" << endl;
//	}
//	Disc_quote1(const std::string& book, double price,
//		std::size_t qty, double disc) :
//		Quote1(book, price),
//		quantity(qty), discount(disc) {
//		cout << "Disc_quote1(const std::string& book, double price,std::size_t qty, double disc)" << endl;
//	}
//
//	Disc_quote1(const Disc_quote1&)
//	{
//		cout << "Disc_quote1(const Disc_quote1&)" << endl;
//	}
//	Disc_quote1(Disc_quote1&&)
//	{
//		cout << "Disc_quote1(Disc_quote1&&)" << endl;
//	}
//	Disc_quote1& operator=(const Disc_quote1& q1) {
//		cout << "Disc_quote1& operator=(const Disc_quote1&) " << endl;
//		return *this;
//	}
//	Disc_quote1& operator=(Disc_quote1&&) {
//		cout << "Disc_quote1& operator=(Disc_quote1&&)" << endl;
//		return *this;
//	}
//	virtual ~Disc_quote1() { cout << "~Disc_quote1()" << endl; }
//
//protected:
//	std::size_t quantity = 0;// 折扣适用的购买量
//	double discount = 0.0;// 表示折扣的小数值
//};
class Disc_quote1
{
public:
	// test
	Disc_quote1(double price, double disc = 3.1)
	{
		cout << "Disc_quote1(double price, double disc = 3.1):disc = "<<disc << endl;
	}
	Disc_quote1(int price)
	{
		cout << "Disc_quote1(int price)" << endl;
	}
	Disc_quote1(){
		cout << "Disc_quote1()" << endl;
	}
	Disc_quote1(const std::string& book, double price,
		std::size_t qty, double disc) :
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

protected:
	std::size_t quantity = 0;// 折扣适用的购买量
	double discount = 0.0;// 表示折扣的小数值
};

class Bulk_quote1 :public Disc_quote1 {
public:
	using Disc_quote1::Disc_quote1;//继承基类的构造函数
	//Bulk_quote1() :Disc_quote1() {
	//	cout << "Bulk_quote1()" << endl;
	//}
	//Bulk_quote1(const std::string& book, double p, std::size_t qty, double disc)
	//	: Disc_quote1(book, p, qty, disc)
	//{
	//	cout << "Bulk_quote1(const std::string& book, double p, std::size_t qty, double disc)" << endl;
	//}
	//Bulk_quote1(const Bulk_quote1&)
	//{
	//	cout << "Bulk_quote1(const Bulk_quote1&)" << endl;
	//}
	//Bulk_quote1(Bulk_quote1&&)
	//{
	//	cout << "Bulk_quote1(Bulk_quote1&&)" << endl;
	//}
	//Bulk_quote1& operator=(const Bulk_quote1& q1) {
	//	cout << "Bulk_quote1& operator=(const Bulk_quote1&) " << endl;
	//	return *this;
	//}
	//Bulk_quote1& operator=(Bulk_quote1&&) {
	//	cout << "Bulk_quote1& operator=(Bulk_quote1&&)" << endl;
	//	return *this;
	//}
	//virtual ~Bulk_quote1() { cout << "~Bulk_quote1()" << endl; }
};

int main()
{
	int a;
	// 即当执行派生类的拷贝构造函数时，并不会继承基类的拷贝构造函数
	Bulk_quote1 bk1;
	cout << "--" << endl;
	Bulk_quote1 bk2(bk1);
	cout << "---" << endl;
	Disc_quote1 *qt1 = new Bulk_quote1("aaa",10,2,0.5);
	delete qt1;
	cout << "---" << endl;
	Bulk_quote1 bk3(3.14);
	Bulk_quote1 bk4(3.14, 56);

	// 练习
	/*
	15.27 ok
	*/
	cin >> a;
	return 0;
}
