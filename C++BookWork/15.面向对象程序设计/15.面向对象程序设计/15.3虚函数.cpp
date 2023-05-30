#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Partice157.h"

using namespace std;

/*
������
ʹ�û�������û�ָ�����һ�����Ա������ִ�ж�̬��

һ�����麯���ĵ��ÿ���������ʱ�ű�����
�麯������������󶨵�ָ��������ϵĶ���Ķ�̬������ƥ����Ǹ�

������ͨ���͵ı��ʽ�����麯�����ڱ���ʱ��ȷ���˰汾�����Ըı�ase��ʾ�Ķ����ֵ�����ǲ���ı�ö��������

�ؼ����C++��̬��
1.�Ѿ��м̳й�ϵ�Ķ�����ͳ�Ϊ��̬����
2.��������û�ָ����û��ඨ���һ������ʱ
�麯��������ʱ�ž����ĸ��汾
���麯��������ʱ�;����뾲̬����һ�°汾
3.�ö�����е��õĺ���
�麯������麯���ڱ���ʱ�뾲̬����һ��

�����������е��麯��
1��һ������Ϊ�麯�����������������ж����麯����������дvirtual��ʾ��ʾ
2.�����������¸�����ĳ���̳ж������麯�����βα����븲�ǵĻ��ຯ����ȫһ��
3.��������Ҳ����ƥ�䣬������ǵ������з����౾���ָ�������ʱ
�磺������麯������B*,��������麯������D*
ǰ����D��B������ת���ǿɷ��ʵ�

����final��override˵����
override��˵���������е��麯�������˻�����麯������û�������ʾ��ʾ����
ֻ���麯���ſ��Ա�����

final���Ѻ���ָ��Ϊfinal����֮���κγ��Ը��Ǹú����Ĳ���������������

override ��final�������β��б� �Լ�β������֮�� ������˳������ν

�ġ��麯����Ĭ��ʵ��
�麯��Ҳ������Ĭ��ʵ��
ʵ��ֵ�ɱ��ε��õľ�̬���;�����
������������麯����Ĭ��ʵ��Ӧ������۵�Ĭ��ʵ�α���һ��

�塢�ر��麯���Ļ���
ϣ�����麯���ĵ��ò�Ҫִ�ж�̬�󶨣�����ǿ��ִ���麯����ĳ���ض��汾��ʹ�������������

�ڱ���ʱ��ɽ���
note��ͨ����ֻ�г�Ա����������Ԫ���еĴ������Ҫʹ����������������ر��麯���Ļ���

ʲôʱ���ã�
һ������������麯���е��û����麯�����麯����ɹ�ͬ����
ע��Ҫ�������򣬲�Ȼ�ͻ������������
*/
struct B {
	virtual void f1(int)const{}
	virtual void f2(){}
	void f3(){}
};
struct D1 : B {
	void f1(int) const override{}
	//void f2(int) override;
	//void f3() override; ֻ���麯���ſ��Ա�����
	//void f4() override;
};
struct D2 : B {
	virtual void f1(int)const override final {}
	//virtual void f2() {}
};
struct D3 : D2 {
	//void f2() override final{}
	//virtual void f1(int) const{}
};
double print_total(ostream& os,
	const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn() <<
		"# sold:" << n << "total due:" << ret << endl;
	return ret;
}

class base {
public:
	string name() 
	{ 
		cout << "string name()" << endl;
		return basename; 
	}
	virtual void print(ostream &os) { os << basename << "basename" << endl; }
private:
	string basename;
};
class derived :public base {
public:
	void print(ostream &os) { base::print(os); os << " " << i<<"i"<<endl; }
private:
	int i;
};
int main()
{
	int a;
	Quote base1("0-021-32-1", 50);
	print_total(cout, base1, 10);
	Bulk_quote derived1("09-sdfsd-9sdf",50,5, .19);
	print_total(cout, derived1, 10);

	base1 = derived1;
	base1.net_price(20);
	//base.min_qty// ���ʲ���������ĳ�Ա

	Bulk_quote bq;
	Quote* qt = &bq;
	qt->testMorenShi();

	qt->Quote::testMorenShi();


	
	derived dr1;
	base* bs1 = &dr1;
	bs1->print(cout);


	cout << endl;
	base bobj;
	derived dobj;
	base *bp1 = &bobj;
	base *bp2 = &dobj;

	base &br1 = bobj;
	base &br2 = dobj;

	bobj.print(cout);
	dobj.print(cout);

	bp1->name();
	bp2->name();

	br1.print(cout);
	br2.print(cout);
	// ��ϰ
	/*
	15.11 ok
	15.12 �ض��������Ҫ
	15.13 û���û����������
	15.14 ok
	*/
	cin >> a;
	return 0;
}