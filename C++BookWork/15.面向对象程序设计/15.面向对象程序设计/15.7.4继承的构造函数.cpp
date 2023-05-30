#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Partice157.h"
#include "Disc_quote.h"

using namespace std;

/*
�Լ�����Ϊ��
�����ڻ���������๹�캯������������������ʹ�ö�������ʾ���ã�ֱ��using ���ࣺ�����๹�캯��
�������������һ����֮��Ӧ�������๹�캯����������ʾ����������Ĺ��캯��������ʹ��������Ĺ��캯�������ҵ��ø������Ӧ���캯��

������
��Щ����Ĺ��캯������Ĭ�ϵĹ��캯�������¶���Ĺ��캯��
���ܹ�������ֱ�ӻ��ඨ��Ĺ��캯����
��Щ���캯�������Գ��淽ʽ�̳ж����ģ�Ϊ�˷��㣬���ҳ�Ϊ���̳е�
1.һ����ֻ�̳���ֱ�ӻ���Ĺ��캯��
2.�಻�ܼ̳�Ĭ�ϡ��������ƶ����캯��
3.���������û��ֱ�Ӷ�����Щ���캯�������������Ϊ������ϳ�����

ʹ��using�������Ի���Ĺ��캯���������������������ñ������������롣
���ڻ����ÿ�����캯���������������2�⣩������������һ����֮��Ӧ�������๹�캯�����β��б���ȫ��ͬ�Ĺ��캯��

��������ȴ����ʵ��ֱ�ӻ���Ŀ������캯������ӻ��಻��

derived(parms) : base(args){ }

tips:��������ຬ���Լ������ݳ�Ա������Щ��Ա����Ĭ�ϳ�ʼ������Ϊ����Ĺ��캯��������ִ��������ĳ�Ա��ʼ��

�����̳еĹ��캯�����ص�
1.using��������ָ��explicit��constexpr��������Ĺ��캯����explicit��constexpr����̳еĹ��캯��Ҳӵ����ͬ������
2.һ�����๹�캯������Ĭ��ʵ�Σ����������̳еĹ��캯������������Ĺ��캯���������βΣ��ڶ����βκ���Ĭ��ʵ�ε��β�
�����������������캯����
һ�����캯�����������βΣ�û��Ĭ��ʵ�Σ�
����һ�����캯��ֻ����һ���βΣ���Ӧ�������������û��Ĭ��ֵ���Ǹ��β�

3.�����������⣬using����̳���Щ���캯��
1�������ඨ��������������ͬ�Ĳ����б�����Щ���캯�����ᱻ�̳� �滻�̳ж����Ĺ��캯��
2����Ĭ�ϡ��������ƶ����캯�����ᱻ�̳С���Ϊ������������Щ����������������ϳɡ�
�̳еĹ��캯�����ᱻ��Ϊ�û�����Ĺ��캯����ʹ��
����1��һ�����滻�̳ж����Ĺ��캯��

��������ȴ����ʵ��ֱ�ӻ���Ŀ������캯������ӻ��಻��
*/

class Quote1 {
public:

	Quote1() {
		cout << "Quote1()" << endl;
	}
	Quote1(const std::string &book, double sales_price) : bookNo(book), price(sales_price) 
	{
		cout << "Quote1(const std::string &book, double sales_price) : bookNo(book), price(sales_price) " << endl;
	}

	Quote1(const Quote1&)
	{
		cout << "Quote1(const Quote1&)" << endl;
	}
	Quote1(Quote1&&)
	{
		cout << "Quote1(Quote1&&)" << endl;
	}
	Quote1& operator=(const Quote1& q1) {
		cout << "Quote1& operator=(const Quote1&) " << endl;
		return *this;
	}
	Quote1& operator=(Quote1&&) {
		cout << "Quote1& operator=(Quote1&&)" << endl;
		return *this;
	}
	// �������������ж�̬��
	virtual ~Quote1() { cout << "~Quote1()" << endl; }
protected:
	double price = 0.0;
public:
	int val1 = 10;
	std::string bookNo;
};
//class Disc_quote1 : public Quote1
//{
//public:
//	// test
//	Disc_quote1(double price,double disc = 3.1)
//	{
//		cout << "Disc_quote1(double price, double disc = 3.1)" << endl;
//	}
//
//	Disc_quote1() :Quote1() {
//		cout << "Disc_quote1()" << endl;
//	}
//	Disc_quote1(const std::string& book, double price,
//		std::size_t qty, double disc) :
//		Quote1(book, price),
//		quantity(qty), discount(disc) {
//		cout << "Disc_quote1(const std::string& book, double price,std::size_t qty, double disc)" << endl;
//	}
//
//	Disc_quote1(const Disc_quote1&)
//	{
//		cout << "Disc_quote1(const Disc_quote1&)" << endl;
//	}
//	Disc_quote1(Disc_quote1&&)
//	{
//		cout << "Disc_quote1(Disc_quote1&&)" << endl;
//	}
//	Disc_quote1& operator=(const Disc_quote1& q1) {
//		cout << "Disc_quote1& operator=(const Disc_quote1&) " << endl;
//		return *this;
//	}
//	Disc_quote1& operator=(Disc_quote1&&) {
//		cout << "Disc_quote1& operator=(Disc_quote1&&)" << endl;
//		return *this;
//	}
//	virtual ~Disc_quote1() { cout << "~Disc_quote1()" << endl; }
//
//protected:
//	std::size_t quantity = 0;// �ۿ����õĹ�����
//	double discount = 0.0;// ��ʾ�ۿ۵�С��ֵ
//};
class Disc_quote1
{
public:
	// test
	Disc_quote1(double price, double disc = 3.1)
	{
		cout << "Disc_quote1(double price, double disc = 3.1):disc = "<<disc << endl;
	}
	Disc_quote1(int price)
	{
		cout << "Disc_quote1(int price)" << endl;
	}
	Disc_quote1(){
		cout << "Disc_quote1()" << endl;
	}
	Disc_quote1(const std::string& book, double price,
		std::size_t qty, double disc) :
		quantity(qty), discount(disc) {
		cout << "Disc_quote1(const std::string& book, double price,std::size_t qty, double disc)" << endl;
	}

	Disc_quote1(const Disc_quote1&)
	{
		cout << "Disc_quote1(const Disc_quote1&)" << endl;
	}
	Disc_quote1(Disc_quote1&&)
	{
		cout << "Disc_quote1(Disc_quote1&&)" << endl;
	}
	Disc_quote1& operator=(const Disc_quote1& q1) {
		cout << "Disc_quote1& operator=(const Disc_quote1&) " << endl;
		return *this;
	}
	Disc_quote1& operator=(Disc_quote1&&) {
		cout << "Disc_quote1& operator=(Disc_quote1&&)" << endl;
		return *this;
	}
	virtual ~Disc_quote1() { cout << "~Disc_quote1()" << endl; }

protected:
	std::size_t quantity = 0;// �ۿ����õĹ�����
	double discount = 0.0;// ��ʾ�ۿ۵�С��ֵ
};

class Bulk_quote1 :public Disc_quote1 {
public:
	using Disc_quote1::Disc_quote1;//�̳л���Ĺ��캯��
	//Bulk_quote1() :Disc_quote1() {
	//	cout << "Bulk_quote1()" << endl;
	//}
	//Bulk_quote1(const std::string& book, double p, std::size_t qty, double disc)
	//	: Disc_quote1(book, p, qty, disc)
	//{
	//	cout << "Bulk_quote1(const std::string& book, double p, std::size_t qty, double disc)" << endl;
	//}
	//Bulk_quote1(const Bulk_quote1&)
	//{
	//	cout << "Bulk_quote1(const Bulk_quote1&)" << endl;
	//}
	//Bulk_quote1(Bulk_quote1&&)
	//{
	//	cout << "Bulk_quote1(Bulk_quote1&&)" << endl;
	//}
	//Bulk_quote1& operator=(const Bulk_quote1& q1) {
	//	cout << "Bulk_quote1& operator=(const Bulk_quote1&) " << endl;
	//	return *this;
	//}
	//Bulk_quote1& operator=(Bulk_quote1&&) {
	//	cout << "Bulk_quote1& operator=(Bulk_quote1&&)" << endl;
	//	return *this;
	//}
	//virtual ~Bulk_quote1() { cout << "~Bulk_quote1()" << endl; }
};

int main()
{
	int a;
	// ����ִ��������Ŀ������캯��ʱ��������̳л���Ŀ������캯��
	Bulk_quote1 bk1;
	cout << "--" << endl;
	Bulk_quote1 bk2(bk1);
	cout << "---" << endl;
	Disc_quote1 *qt1 = new Bulk_quote1("aaa",10,2,0.5);
	delete qt1;
	cout << "---" << endl;
	Bulk_quote1 bk3(3.14);
	Bulk_quote1 bk4(3.14, 56);

	// ��ϰ
	/*
	15.27 ok
	*/
	cin >> a;
	return 0;
}
