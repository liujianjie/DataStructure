#include "Quote.h"


double Quote::net_price(std::size_t n)const
{
	cout << " Quote::net_price(std::size_t n)const" << endl;
	return n * price;
}