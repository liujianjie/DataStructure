#pragma once
#include <iostream>
#include <string>
using namespace std;
class Sales_data {
	// 7.2.1��Ԫ
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	friend ostream &operator<<(ostream &os, const Sales_data &item);
	friend istream &operator >> (istream &is, Sales_data &item);
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
	friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
	friend bool operator!=(const Sales_data &lhs, const Sales_data &rhs);

	// ��ϰ 14.22
	//friend Sales_data& operator+(Sales_data &lhs, Sales_data &rhs);
public:


	// 7.1.4���캯��
	Sales_data() = default;

	// 7.5.1 ����������������������ã������Ĭ��ʵ�ε�ע���������ֵ
	//Sales_data(std::string s = "") : bookNo(s){}// Ĭ�Ϲ��캯������ʽ��ʹ��string��Ĭ�Ϲ��캯����ʼ��bookNo�����Ժϲ���һ��

	/*Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p * n) {
		cout << "Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p * n)" << endl;}
	Sales_data(std::istream &);*/
	// 7.5.2ί��
	//Sales_data() : Sales_data("", 0, 0) { cout << "	Sales_data() : Sales_data("", 0, 0)" << endl; }
	//Sales_data(std::string s) : Sales_data(s, 0, 0) { cout << "Sales_data(std::string s) : Sales_data(s, 0, 0)" << endl; }
	//Sales_data(std::istream &is) : Sales_data() { cout << "Sales_data(std::istream &is) : Sales_data()" << endl; read(is, *this); }// ��ִ�б�ί�еĺ����ĺ������ٷ��ؿ���Ȩ��ί����

	// 7.5.4 ��
	//explicit Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p * n) {
		cout << "Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p * n)" << endl;
	}
	explicit Sales_data(std::istream &);

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

	std::string getBookNo() { return bookNo; }
	double getrevene() { return revenue; }
	// 13
	// �������캯��
	Sales_data(const Sales_data& rhs);
	// ������ֵ�����
	Sales_data& operator=(const Sales_data&);
	~Sales_data();

	// 14.1
	//int operator+(Sales_data& s1, Sales_data& s2);
	//int operator+(int, int);
	Sales_data& operator+=(const Sales_data &rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	//Sales_data& operator+=(const Sales_data &rhs)
	//{
	//	Sales_data temp = *this;
	//	temp = temp + rhs;
	//	return temp;
	//}
	
	Sales_data& operator=(string &);
	Sales_data& operator=(std::initializer_list<string> );

	// 14.45
	operator string() const
	{
		return bookNo;
	}
	operator double() const
	{
		return avg_price();
	}
private:
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
inline
ostream &operator<<(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
			<< item.revenue << " " << item.avg_price();
	return os;
}
inline
istream &operator >> (istream &is, Sales_data &item) 
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = item.units_sold*price;
	else
		item = Sales_data();
	return is;
}

inline
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;// ����sum�ĸ���
}

//inline
//Sales_data& operator+( Sales_data &lhs,  Sales_data &rhs)
//{
//	lhs.units_sold += rhs.units_sold;
//	lhs.revenue += rhs.revenue;
//	return lhs;
//}
inline
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() &&
		lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue;
}
inline
bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}
// Sales_data�ķǳ�Ա�ӿں���
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

//struct Sales_data {
//	// ���캯��
//	Sales_data() = default;
//	Sales_data(const std::string &s) : bookNo(s) {}
//	Sales_data(const std::string &s, unsigned n, double p) :
//		bookNo(s), units_sold(n), revenue(p * n) {}
//	Sales_data(std::istream &);
//	
//	std::string isbn() const { return bookNo; }
//	Sales_data& combine(const Sales_data&);
//	double avg_price() const;
//	std::string bookNo;
//	unsigned units_sold = 0;
//	double revenue = 0.0;
//};