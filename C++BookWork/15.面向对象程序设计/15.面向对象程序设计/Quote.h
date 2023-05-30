#pragma once
#include <iostream>
#include <string>
using namespace std;

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}

	std::string isbn() const { return bookNo; }

	virtual double net_price(std::size_t n)const;
	virtual ~Quote() = default;// 对析构函数进行动态绑定

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
	// 返回当前对象的一份动态分配的拷贝
	virtual Quote* clone()const & { return new Quote(*this); }
	virtual Quote* clone() && 
	{ 
		return new Quote(std::move(*this));
	}
protected:
	double price = 0.0;
public:
	int val1 = 10;
	std::string bookNo;
};