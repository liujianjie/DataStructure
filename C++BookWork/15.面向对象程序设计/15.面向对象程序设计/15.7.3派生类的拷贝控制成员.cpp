#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Partice157.h"
#include "Disc_quote.h"

using namespace std;

/*
������
�������Ƴ�Ա��������������ҲҪ�������ಿ�ֵĳ�Ա
1.��ͬ������������ֻ���������������Լ��������Դ������ĳ�Ա�Ǳ���ʽ���ٵģ����Ƶģ����������Ļ��ಿ��Ҳ���Զ����ٵ�

note���������ඨ���˿������ƶ�����ʱ���ò������𿽱����ƶ��������ಿ�ֳ�Ա���ڵ���������

��������������Ŀ������ƶ����캯��
��Ҫʹ�ö�Ӧ�Ļ��๹�캯����ʼ������Ļ��ಿ��
D(const D& d):B(d){}
��һ��D���󴫵ݸ����๹�캯����������˵��base������һ����������ΪD�Ĺ��캯������ͨ������ô��
һ���ƥ��Base�Ŀ������캯����������d�ϵĻ��ಿ�ֿ���Ҫ�����Ķ���

2.����û���ṩ����ĳ�ʼֵ�Ļ�������Ĳ��ֱ�Ĭ�ϳ�ʼ�����ܿ���δ�������Ϊ
note������Ĭ�Ϲ��캯����ʼ�����������Ļ��ಿ�֣����뿽�����ƶ����ಿ�֣��������������
���캯����ʼ���б�����ʾ��ʹ�û���Ŀ������ƶ����캯��

���������ำֵ�����
Ҳ������ʾ��Ϊ����ಿ�ָ�ֵ

��ʾ�ģ���ô���ۻ���Ĺ��캯����ֵ��������Զ���İ汾���Ǻϳɰ汾��������Ķ�Ӧ��������ʹ�����ǡ�

�ġ���������������
����������ִ����ɺ󣬶���ĳ�Ա�ᱻ��ʽ���١�
����Ļ��ಿ��Ҳ����ʽ���ٵġ�
�͹��캯������ֵ�������ͬ���ǣ���������������ֻ�����������������Լ��������Դ��

Base::~Base���Զ�����ִ��
�������ٵ�˳���������䴴����˳���෴��������������������ִ�У�Ȼ���ǻ�����������������ż̳���ϵ�ķ�����ֱ�����

�塢�ڹ��캯�������������е����麯��
���ಿ�����ȱ����������๹�캯������ʱ��������Ĳ�����δ����ʼ��״̬
�������������ʱ�������������������ʱ��������Ĳ����Ѿ������ٵ���
��ִ����������ĳ�Աʱ�򣬸ö�����δ��ɵ�״̬����Ϊ�����ಢ������δ����ʼ�������ٵ���

�麯���ĵ��ð��ǰѶ������͹��캯�����࿴��ͬһ��
Ϊ���ܴ�������״̬��
��������Ϊ����������ڹ���������Ĺ����з·����˸ı�һ���������ǹ���һ������ʱ����Ҫ�Ѷ������͹��캯�����࿴����ͬһ��
��������๹�캯������ʱ���������Ϊ���࣬��ôִ���麯�����ǻ���汾���麯����
ֱ�ӵ����麯��
��ӵ��ã�����ͨ�����캯������������������һ������Ҳ�ǿ���

����������Ϊû��ִ�У��ڻ���Ĺ��캯��ִ���麯����������汾ʱ���������Աδ��ʼ����������ܻ������

note��������캯������������������ĳ���麯����Ӧ��������ִ�й��캯�����������������������Ӧ���麯���汾

*/
class B {
public:
	//B() = default;
	B() { 
		testvir();
	}
	//B(const B&) = delete;
	B(const B&) = default;
	B(B&&) = default;
	B& operator=(const B&) = default;
	B& operator=(B&&) = default;
	//virtual ~B() = default;
	virtual ~B()
	{
		testvir();
	}
	virtual void testvir() { cout << "B:  testvir()" << endl; }
};
class D :public B {
public:
	D():B(){}
	D(const D& d):B(d){}
	D(D&& d):B(std::move(d)){}
	D& operator=(const D &rhs);
	// B::~B���Զ�����ִ��
	~D(){/* �ô����û���������������Ա�Ĳ���*/
		testvir();
	}

	virtual void testvir() { cout << "D:  testvir()" << endl; }
};
D &D::operator=(const D &rhs)
{
	// ��ʾ�ĵ���
	B::operator=(rhs);
	return *this;
}
// ��ϰ
class Quote1 {
public:
	Quote1() {
		cout << "Quote1()" << endl;
	}
	Quote1(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}

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

	std::string isbn() const { return bookNo; }

	virtual double net_price(std::size_t n)const
	{
		return 0;
	}
	// �������������ж�̬��
	virtual ~Quote1(){ cout << "~Quote1()" << endl; }

	void Quote_quoteMethod()
	{
		cout << "Quote_quoteMethod()" << endl;
	}
	virtual void testMorenShi(int val = 2) {
		cout << "Quote::testMorenShi:" << val << endl;
	}
	virtual void debug()
	{
		cout << "price:" << price << "val:" << val1 << "bookNo:" << bookNo << endl;
	}
protected:
	double price = 0.0;
public:
	int val1 = 10;
	std::string bookNo;
};
class Disc_quote1 : public Quote1
{
public:
	Disc_quote1():Quote1() {
		cout << "Disc_quote1()" << endl;
	}
	Disc_quote1(const std::string& book, double price,
		std::size_t qty, double disc) :
		Quote1(book, price),
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

	virtual double net_price(std::size_t)const = 0;
	std::pair<size_t, double> discount_policy() const
	{
		return{ quantity, discount };
	}
protected:
	std::size_t quantity = 0;// �ۿ����õĹ�����
	double discount = 0.0;// ��ʾ�ۿ۵�С��ֵ
};

class Bulk_quote1 :public Disc_quote1 {
public:
	Bulk_quote1() :Disc_quote1(){
		cout << "Bulk_quote1()" << endl;
	}
	//Bulk_quote():Disc_quote("",0,0,0){}
	Bulk_quote1(const std::string& book, double p, std::size_t qty, double disc)
		: Disc_quote1(book, p, qty, disc)
	{
		cout << "Bulk_quote1(const std::string& book, double p, std::size_t qty, double disc)" << endl;
		//bookNo = books; //����bookNo��˽�е� �Ͳ��ɷ���
		//price = p;
	}
	Bulk_quote1(const Bulk_quote1&)
	{
		cout << "Bulk_quote1(const Bulk_quote1&)" << endl;
	}
	Bulk_quote1(Bulk_quote1&&)
	{
		cout << "Bulk_quote1(Bulk_quote1&&)" << endl;
	}
	Bulk_quote1& operator=(const Bulk_quote1& q1) {
		cout << "Bulk_quote1& operator=(const Bulk_quote1&) " << endl;
		return *this;
	}
	Bulk_quote1& operator=(Bulk_quote1&&) {
		cout << "Bulk_quote1& operator=(Bulk_quote1&&)" << endl;
		return *this;
	}
	virtual ~Bulk_quote1() { cout << "~Bulk_quote1()" << endl; }
	double net_price(std::size_t)const override
	{
		return 0;
	}
	void Bulk_quoteMethod()
	{
		cout << "Bulk_quoteMethod()" << endl;
	}
	virtual void testMorenShi(int val = 3) {
		//Quote::testMorenShi();
		cout << "Bulk_quote::testMorenShi:" << val << endl;
	}
	virtual void debug()
	{
		cout << "min_qty:" << quantity << "discount:" << discount << endl;
	}
};

int main()
{
	int a;

	B *b1 = new D();
	delete b1;

	cout << "----" << endl;
	//Bulk_quote1 bk1;
	Quote1 *qt1 = new Bulk_quote1();
	delete qt1;
	// ��ϰ
	/*
	15.26: ok
	*/
	cin >> a;
	return 0;
}
