#pragma once
#include "Quote.h"
#include "Disc_quote.h"

//class Partice157 : public Quote
class Partice157 : public Disc_quote
{
public:
	Partice157() = default;
	Partice157(const std::string& book, double p, std::size_t qty, double disc)
		: Disc_quote(book, p,qty,disc)
	{
	}
	double net_price(std::size_t)const override;
//private:
//	std::size_t max_qty = 0;// ÕÛ¿Û²ßÂÔ¹ºÂòµÄ²»³¬¹ý¹ºÂòÁ¿
//	double discount = 0.0;// ÕÛ¿Û¶î
};

