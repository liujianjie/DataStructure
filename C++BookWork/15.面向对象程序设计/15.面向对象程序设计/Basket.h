#pragma once
#include <iostream>
#include "Quote.h"
#include <memory>
#include <algorithm>
#include <set>
using namespace std;

class Basket
{
public:
	Basket();
	~Basket();

	//void add_item(const shared_ptr<Quote> &sale)
	//{
	//	items.insert(sale);
	//}
	void add_item(const Quote &sale);// 拷贝给定的对象
	void add_item(Quote &&sale);// 移动给定的对象
	double total_receipt(ostream&)const;
private:
	static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

inline
double print_total(ostream& os,
	const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn() <<
		" # sold:" << n << "total due:" << ret << endl;
	return ret;
}