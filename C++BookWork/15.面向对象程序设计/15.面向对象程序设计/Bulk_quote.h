#pragma once
#include <iostream>
#include "Quote.h"
#include "Disc_quote.h"
using namespace std;

class Bulk_quote :public Disc_quote {
public:
	Bulk_quote() = default;
	//Bulk_quote():Disc_quote("",0,0,0){}
	Bulk_quote(const std::string& book, double p, std::size_t qty, double disc)
		: Disc_quote(book, p, qty, disc)
	{
		//bookNo = books; //倘若bookNo是私有的 就不可访问
		//price = p;
	}
	double net_price(std::size_t)const override;
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
	virtual Bulk_quote* clone()const & { return new Bulk_quote(*this); }
	virtual Bulk_quote* clone() &&
	{
		return new Bulk_quote(std::move(*this));
	}
public:
	int val2 = 10;
//private:
//public:
//	std::size_t min_qty = 0;// 折扣策略购买的最低购买量
//	double discount = 0.0;// 折扣额
};
