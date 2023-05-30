#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Partice157.h"
#include "Disc_quote.h"

using namespace std;

/*
������
ÿ���ඨ���Լ����������������ж�����ĳ�Ա��
�̳й�ϵʱ���������������Ƕ����������������֮��
�������������������޷��ҵ���Ա����������Ļ������������

һ���ڱ���ʱ�������ֲ���
һ���������û�ָ��ľ�̬���;����˸ö������Щ��Ա�ǿɼ��ġ�
��ʹ��̬�����붯̬���Ϳ��ܲ�һ�¡�
�ܣ��ɾ�̬���;�����Щ��Ա�ɼ���ʹ��

��������ת��ʱ����̬�����붯̬���Ͳ�һ�£��Ӿ�̬���ͣ����ࣩ���ң������Զ�̬���ͣ����ࣩ�ĳ�Ա

�������ֳ�ͻ��̳�
������ĳ�Ա���ֻ����ض����ڻ���ĳ�Ա����,ͬ��

����ͨ���������������ʹ�����صĳ�Ա
����ʹ���������������ʹ��һ�������صĻ����Ա
note�����˸��Ǽ̳ж������麯��֮�⣬��ò�Ҫ����ͬ������

�ؼ�������ֲ�����̳�
p->mem();4������
1.ȷ��p�ľ�̬���͡���Ȼ��������
2.p�ľ�̬���Ͷ�Ӧ�����в���mem���Ҳ������һ���ֱ��������û���򱨴�
3.���ҵ���mem����������ͼ�飬�Ƿ�Ϸ�
4.�Ϸ����Ƿ����麯��������ͬ�Ĵ��룺
1����mem���麯����������ͨ�����û�ָ����еĵ��ã�������������Ĵ��뽫������ʱȷ���������и��麯�����ĸ��汾�����ݶ�̬����
2���������麯������ͨ�����󣨶������û�ָ�룩���еĵ��ã��������������һ�����溯������

�ġ�һ�����������ֲ����������ͼ��
�ڲ�������ĺ��������������������ĺ���
�����������еĺ���Ҳ�������ػ���ĳ�Ա��
���������еĳ�Ա������ĳ����Աͬ�����������ཫ���������������ظû����Ա����ʹ�β��б�һ��

d.memfcn();//
һ���ҵ���Ϊmemfcn�ĳ�Ա�����ҹ��̾���ֹ���ٽ������ͼ�飬�βκϷ���

�塢�麯����������
���Ի�������������麯�����ܵ�ʵ�α�����ͬ

����ͨ������������ص��麯��
���Ǹ��ݶ�̬���Ͳ��ң�����������ص��麯���������ϲ���

�ߡ��������صĺ���
����������������һ������Ա���������Ƿ����麯�����ܱ�����
��������Ը������غ�����0������ʵ����
������ϣ�����е����ذ汾��������˵���ǿɼ�������Ҫ�������еİ汾������һ��Ҳ������

�����ǣ�����������Ҫʹ�û�������س�Ա������������Ҫ���ǲ��ֻ�������س�Ա���򲻵ò���Ҫ���ǻ����ÿ���汾����Ȼ�鷳

��������ǣ�ʹ��using
��using�������������غ��������ƣ������¶����򸲸ǵ����غ����汾����Խ����
��������û�����¶�������ذ汾�ķ���ʵ�����Ƕ�using������ķ���
*/
struct Base1 {
	Base1():mem(0){}
	int memfcn()
	{
		cout << "Base1::memfcn()" << endl;
	}
public:
	virtual int fcn() {
		cout << "Base1::fcn()" << endl;
		return 0;
	}
protected:
	int mem;
};
struct Derived :Base1 {
	Derived() = default;
	int memfcn(int a)
	{
		cout << "Derived::memfcn()" << endl;
		return 0;
	}
	Derived(int i):mem(i){}
	//int get_mem() { return mem; }
	int get_mem() { return Base1::mem; }
protected:
	int mem;
};

class D1 :public Base1 {
public:
	using Base1::fcn;
	int fcn() {
		cout << "D1::fcn()" << endl;
		return 0;
	}
	int fcn(int) {
		cout << "D1::fcn(int)" << endl;
		return 0;
	}
	virtual void f2() {
		cout << "D1::f2()" << endl;
	}
};
class D2 :public D1 {
public:
	int fcn(int) {
		cout << "D2::fcn(int)" << endl;
		return 0;
	}
	int fcn() {
		cout << "D2::fcn()" << endl;
		return 0;
	}
	void f2() {
		cout << "D2::f2()" << endl;
	}
};

struct Base2 {
public:
	void fcn() { cout << "Base2::fcn()"<<endl;}
	void fcn(int){ cout << "Base2::fcn(int)" << endl; }
	void fcn(int,double) { cout << "Base2::fcn(int,double)" << endl; }
};
struct Derived2:public Base2 {
public:
	using Base2::fcn;
	void fcn() { cout << "Derived2::fcn()" << endl; }
	/*void fcn(int) { cout << "Derived2::fcn(int)" << endl; }
	void fcn(int, double) { cout << "Derived2::fcn(int,double)" << endl; }*/
};
int main()
{
	int a;
	Bulk_quote bulk;
	Bulk_quote *bulkP = &bulk;
	Quote *itemP = &bulk;
	bulkP->discount_policy();
	//itemP->discount_policy();

	//Derived d(42);
	//cout << d.get_mem() << endl;

	//Derived d;
	//Base1 b;
	//b.memfcn();
	//d.memfcn(10);
	//d.memfcn();//
	//d.Base1::memfcn();

	Base1 bobj;
	D1 dlobj;
	D2 d2obj;
	Base1 *bp1 = &bobj, *bp2 = &dlobj, *bp3 = &d2obj;
	bp1->fcn();
	bp2->fcn();
	bp3->fcn();

	D1 *d1p = &dlobj;
	D2 *d2p = &d2obj;
	//bp2->f2();
	d1p->f2();
	d2p->f2();

	Base1 *p1 = &d2obj;
	D1 *p2 = &d2obj;
	D2 *p3 = &d2obj;
	//p1->fcn(42);
	p2->fcn(42);
	p3->fcn(42);
	cout << "---------------" << endl;

	Derived2 dd2;
	dd2.fcn();
	dd2.fcn(32);


	// ��ϰ
	/*
	15.23 ok
	*/
	cin >> a;
	return 0;
}
