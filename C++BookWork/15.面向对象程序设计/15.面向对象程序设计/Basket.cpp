#include "Basket.h"



Basket::Basket()
{
}


Basket::~Basket()
{
}
double Basket::total_receipt(ostream& os)const
{
	double sum = 0;
	for (auto be = items.begin();
		be != items.end();
		be = items.upper_bound(*be)) 
	{
		sum += print_total(os, **be, items.count(*be));
	}
	cout << "Total coast:" << sum << endl;
	return sum;
}
void Basket::add_item(const Quote &sale)
{
	//items.insert(shared_ptr<Quote>(new Quote(sale))); //不正确的
	items.insert(shared_ptr<Quote>(sale.clone()));
}
void Basket::add_item(Quote &&sale)
{
	//items.insert(shared_ptr<Quote>(new Quote(sale)));// 不正确的
	items.insert(shared_ptr<Quote>(std::move(sale).clone()));
}