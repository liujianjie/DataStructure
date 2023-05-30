#include "Partice157.h"

double Partice157::net_price(std::size_t cnt)const
{
	cout << "Partice157::net_price(std::size_t n)const" << endl;
	//if (cnt < max_qty)
	if (cnt < quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}
