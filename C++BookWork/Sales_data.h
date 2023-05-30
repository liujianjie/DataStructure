#pragma once
#include <iostream>
#include <string>
using namespace std;
class Sales_data {
	// 7.2.1友元
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	friend ostream& operator<<(ostream& os, const Sales_data& sa);
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
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
		//}
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