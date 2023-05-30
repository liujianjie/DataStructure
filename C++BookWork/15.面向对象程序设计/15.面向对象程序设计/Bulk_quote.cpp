#include "Bulk_quote.h"

double Bulk_quote::net_price(std::size_t cnt)const
{
	cout << "Bulk_quote::net_price(std::size_t n)const" << endl;
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}