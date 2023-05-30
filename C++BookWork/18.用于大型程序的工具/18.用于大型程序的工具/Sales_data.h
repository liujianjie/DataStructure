#pragma once
#include <iostream>
#include <string>
#include "isbn_mismatch.h"

using namespace std;

template <class T> struct std::hash;
class Sales_data {
	friend struct std::hash<Sales_data>;
	// 7.2.1友元
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	friend ostream& operator<<(ostream& os, const Sales_data& sa);
	friend istream& operator >> (istream& is,  Sales_data& sa);
public:
	// 7.1.4构造函数
	Sales_data() = default;

	Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p * n) {
		cout << "Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p * n)" << endl;
	}
	explicit Sales_data(std::istream &);

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

	std::string getBookNo() { return bookNo; }

	Sales_data& operator+(const Sales_data& rhs) {
		//if (bookNo != rhs.bookNo) {
			//units_sold += rhs.units_sold;
			//revenue += rhs.revenue;
		//}
		*this += rhs;
		return *this;
	}
	Sales_data& operator+=(const Sales_data& rhs) {
		if (isbn() != rhs.isbn())
			throw isbn_mismatch("wrong isbns ",isbn(),rhs.isbn());
		cout << "operator+=" << endl;
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	Sales_data& noexceplus(const Sales_data& rhs) {
		//if (isbn() != rhs.isbn())
		//cout << "well operator+=" << endl;
		cout << "noexceplus" << endl;
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
private:
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

inline
ostream& operator<<(ostream& os, const Sales_data& sa) {
	os << "units_sold:" << sa.units_sold << ",revenue:" << sa.revenue;
	return os;
}
inline
istream& operator >> (istream& is,  Sales_data& sa) {
	double price;
	is >> sa.bookNo >> sa.units_sold >> price;
	if (is)
		sa.revenue = sa.units_sold * price;
	return is;
}