#include "Sales_data.h"
using namespace std;

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
		<< item.revenue << " " << item.avg_price()<<endl;
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

Sales_data::Sales_data(const Sales_data &orig):
	bookNo(orig.bookNo),
	units_sold(orig.units_sold),
	revenue(orig.revenue)
{
}

Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
	bookNo = rhs.bookNo;
	units_sold = rhs.units_sold;
	revenue = rhs.revenue;
	return *this;
}
Sales_data::~Sales_data()
{
	cout << "~Sales_data();" << endl;
}

Sales_data &Sales_data::operator=(string &st)
{
	Sales_data sd(st);
	*this = sd;
	return *this;
}

Sales_data& Sales_data::operator=(std::initializer_list<string> il)
{
	int i = 0;
	for (auto p = il.begin(); p != il.end(); p++) {
		if (i == 0) {
			bookNo = *p;
		}
		else if(i == 1){
			units_sold = atoi((*p).c_str());
		}
		else if (i == 2) {
			revenue = atof((*p).c_str());
		}
		i++;
	}
	return *this;
}