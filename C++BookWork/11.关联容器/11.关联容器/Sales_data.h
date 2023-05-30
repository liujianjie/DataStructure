#pragma once
#include <iostream>
#include <string>
using namespace std;
class Sales_data {
	// 7.2.1友元
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
public:
	// 7.1.4构造函数
	Sales_data() = default;

	// 7.5.1 三，这个函数做了两个作用，用这个默认实参得注意需求给予值
	//Sales_data(std::string s = "") : bookNo(s){}// 默认构造函数，隐式地使用string的默认构造函数初始化bookNo。可以合并成一个

	/*Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p * n) {
		cout << "Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p * n)" << endl;}
	Sales_data(std::istream &);*/
	// 7.5.2委托
	//Sales_data() : Sales_data("", 0, 0) { cout << "	Sales_data() : Sales_data("", 0, 0)" << endl; }
	//Sales_data(std::string s) : Sales_data(s, 0, 0) { cout << "Sales_data(std::string s) : Sales_data(s, 0, 0)" << endl; }
	//Sales_data(std::istream &is) : Sales_data() { cout << "Sales_data(std::istream &is) : Sales_data()" << endl; read(is, *this); }// 先执行被委托的函数的函数体再返回控制权给委托者

	// 7.5.4 三
	//explicit Sales_data(const std::string &s) : bookNo(s) {}
	 Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p * n) {
		cout << "Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p * n)" << endl;
	}
	explicit Sales_data(std::istream &);

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

	std::string getBookNo() { return bookNo; }
private:
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

//struct Sales_data {
//	// 构造函数
//	Sales_data() = default;
//	Sales_data(const std::string &s) : bookNo(s) {}
//	Sales_data(const std::string &s, unsigned n, double p) :
//		bookNo(s), units_sold(n), revenue(p * n) {}
//	Sales_data(std::istream &);
//	
//	std::string isbn() const { return bookNo; }
//	Sales_data& combine(const Sales_data&);
//	double avg_price() const;
//	std::string bookNo;
//	unsigned units_sold = 0;
//	double revenue = 0.0;
//};