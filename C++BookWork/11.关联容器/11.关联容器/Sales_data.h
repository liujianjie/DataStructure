#pragma once
#include <iostream>
#include <string>
using namespace std;
class Sales_data {
	// 7.2.1��Ԫ
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
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
private:
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

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