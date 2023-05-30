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
	virtual ~Quote() = default;// �������������ж�̬��

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
	// ���ص�ǰ�����һ�ݶ�̬����Ŀ���
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