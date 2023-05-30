#pragma once
#include <iostream>
#include <string>
#include "Quote.h"
using namespace std;
class Disc_quote : public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double price,
		std::size_t qty, double disc) :
		Quote(book, price),
		quantity(qty), discount(disc){}
	double net_price(std::size_t)const = 0;
	std::pair<size_t, double> discount_policy() const
	{
		return{ quantity, discount };
	}
protected:
	std::size_t quantity = 0;// �ۿ����õĹ�����
	double discount = 0.0;// ��ʾ�ۿ۵�С��ֵ
};

