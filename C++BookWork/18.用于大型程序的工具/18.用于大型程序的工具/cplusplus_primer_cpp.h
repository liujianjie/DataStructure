#pragma once
#include <iostream>
#include <string>
#include "isbn_mismatch.h"
#include "cplusplus_primer.h"
using namespace std;

void 
cplusplus_primer::Sales_data::testOutIdenti()
{
	cout << "定义好了" << endl;
}

namespace cplusplus_primer {
	//inline// 不重要 
		Sales_data& operator+(Sales_data& lhs, const Sales_data& rhs) {
		lhs += rhs;
		return lhs;
	}
	inline
		ostream& operator<<(ostream& os, const Sales_data& sa) {
		os << "units_sold:" << sa.units_sold << ",revenue:" << sa.revenue;
		return os;
	}
	inline
		istream& operator >> (istream& is, Sales_data& sa) {
		double price;
		is >> sa.bookNo >> sa.units_sold >> price;
		if (is)
			sa.revenue = sa.units_sold * price;
		return is;
	}
	// cpp
	Sales_data& Sales_data::combine(const Sales_data& rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	double Sales_data::avg_price() const
	{
		if (units_sold)
			return revenue / units_sold;
		else
			return 0;
	}
	// 属于类的接口 的组成部分
	istream &read(istream &is, Sales_data &item)
	{
		double price = 0;
		is >> item.bookNo >> item.units_sold >> price;
		item.revenue = price * item.units_sold;
		return is;
	}
	ostream &print(ostream &os, const Sales_data &item)
	{
		cout << item.isbn() << " " << item.units_sold << " "
			<< item.revenue << " " << item.avg_price() << endl;
		//os << item.isbn() << " " << item.units_sold << " "
		//	<< item.revenue << " " << item.avg_price();
		return os;
	}
	Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
	{
		Sales_data sum = lhs;
		sum.combine(rhs);
		return sum;
	}
	Sales_data::Sales_data(std::istream &is)
	{
		read(is, *this); // read函数的作用是从is中读取一条交易信息然后存入this对象中
	}
}