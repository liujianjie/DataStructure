#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Partice157.h"
#include "Disc_quote.h"

using namespace std;

/*
������
ÿ����ֱ�����Լ��ĳ�Ա��ʼ�����̣�ÿ���໹�ֱ���������Ա������������˵�Ƿ�ɷ���

һ���ܱ����ĳ�Ա
protected:
1.�ܱ����ĳ�Ա��������û���˵�ǲ��ɷ��ʵģ�������Ķ��󲻿ɷ���
2.����������������Ԫ��˵���Է���
3.��Ҫ��һ�㣺������ĳ�Ա����Ԫֻ��ͨ�����������������
����������л��ಿ�ֵ�protected��Ա

�������С�˽�к��ܱ����ļ̳�
ĳ�������̳ж����ĳ�Ա�ķ���Ȩ���յ���������Ӱ�죺
1)	�ڻ����г�Ա�ķ���˵����
2)	��������������б��еķ���˵����
����������ĳ�Ա������Ԫ����this������ܷ����ֱ�ӻ����public,protected��private��Ա��
1.this
1)	�����������б����˵����ûʲôӰ�죬�Ի����г�Ա�ķ���˵������Ӱ��
2)	�����г�Ա˵������public,protected �ܷ��ʣ�private�Ͳ��ܷ���
3)	ǰ��ע�⣺������ĳ�Ա����Ԫ������������Ķ�����const�ģ���Ȼ���ɷ���public�ĳ�Ա������������

2.����
�������б����˵������Ŀ���ǿ�����������û�(����)�������������������������һ�����ۣ���Ҫ��������Ķ��󣩶��ڻ���ĳ�Ա�ķ���Ȩ�ޣ�
1)	���������б����˵�����ǣ�
public��������Ķ�����Է��ʻ����publc��protected
protected,������Ķ��󲻿��Է��ʻ����public��protected
private��������Ķ��󲻿��Է��ʻ����public��protected
2)	*������D˽�м̳�B ��D d��������d���󲻿ɷ��ʻ����public��Ա����������D�ڲ�ʹ��D d���Է��ʻ����public��Ա(��һ��)��
3)	private���������public��Ա˽�л��ˣ�����������Ķ��󲻿ɷ��ʻ����public
4)	protected���������public��Ϊprotected�ģ�����������Ķ��󲻿ɷ��ʻ����protected

3.�������������
��������˵���������Կ��Ƽ̳��������������ķ���Ȩ�ޣ�
1)	�̳�private������������������޷����ʼ�ӻ����public��protect��Ա
2)	��Ϊprivate�������protected��public��Ա����˽�л��ˣ��൱���������˳�Ա�ķ���˵����
��Ϊprivate��ֱ�ӻ��ཫ��˽����
������˵������protected����public�����

4.	�����������ת���Ŀɷ����ԡ�����Base*b=new Derived;
1)	�ɸ�ת���Ĵ��������λ�ã���ͬʱ������ķ���˵����Ҳ��Ӱ��
2)	ֻ��D���еļ̳�Bʱ
�û��������ʹ��������������ת��(��main�л������ط�)������˽�л��ܱ���������
3)	����D��ʲô��ʽ�̳�B��D�ĳ�Ա��������Ԫ������������������ת��������Զ���еġ�
4)	��D���л����ܱ����ļ̳�B������D�ġ�������E����E�ĳ�Ա����Ԫ����ʹ��D����E����B������ת������֮�����D�̳�B�ķ�ʽ��˽�еģ�����ʹ��
5)	note:��������3�����ĳ�������ڵ�Ĵ����У��������Ĺ��г�Ա���Է��ʵģ���������������ת���ǿ��еģ���֮���ɡ��ţ�ע��������Ķ��󲻿ɷ����������protected��private��Ա��

�ؼ�������������ܱ����ĳ�Ա
1.�����Ǽ̳�,һ���������ֲ�ͬ���û�
1����ͨ�û���������Ķ���ֻ�ܷ�����Ĺ��нӿڳ�Ա
2�����ʵ���ߣ������д��ĳ�Ա����Ԫ�Ĵ��룬�ܷ�����Ĺ��У�Ҳ����˽��

2.���Ǽ̳У��������û���������
�����һ���ܱ����ĳ�Ա
1����ͨ�û������ܷ����ܱ����ĳ�Ա
2�����ʵ���ߣ����Է����ܱ����������ܷ���private

3.����Ӧ�ý���ӿڳ�ԱΪ���е�
ʵ�ֵĲ��ַ����飺
һ��ɹ����������,Ӧ������protected
һ���ɻ��༰�������Ԫ���ʣ�Ӧ������private

�ġ���Ԫ��̳�
�����ϵ���ܴ��ݣ�ͬ�����ܼ̳С�
�������Ԫ���ɷ����������Ա�����������ԪҲ����������ʻ���ĳ�Ա
ÿ���ฺ������Լ��ĳ�Ա�ķ���Ȩ�ޡ�

��������Ƕ�Ļ��ಿ��Ҳ�ܻ��ಿ�ֿ���

��Ԫ��ϵ���ܼ̳У�

�塢�ı�����Ա�Ŀɷ�����
D˽�м̳�B
��D�������಻�ɷ���B�ĳ�Ա������B�ĳ�Ա���¶�����D����������û��Ϳ��Է���B�ĳ�Ա
ʹ�÷�����
public:
using B::a;

note��������ֻ��Ϊ��Щ�����Է��ʵ������ṩusing����

����Ĭ�ϵļ̳б�������
���������������˵��������class��structĬ��ʵ��
class��private
struct��public
struct��class�Ĳ�����Ĭ�ϳ�Ա����˵������Ĭ����������˵����

note��Ӧ����ʾ����������˵������ȥ����Ĭ�ϵģ���Ϊ������������

*/
class Base1 {
	friend class Pal;
protected:
	int prot_mem;
};
class Sneaky1 :public Base1 {
	friend void clobber(Sneaky1&);
	friend void clobber(Base1&);
	int j;
	void testfun() {
		prot_mem = 2;
	}
};
class Pal {
public:
	int f(Base1 b) { return b.prot_mem; }
	//int f2(Sneaky1 s) { return s.j; }
	int f3(Sneaky1 s) { return s.prot_mem; }// �Ի���ķ���Ȩ���ɻ��౾����ƣ�������Ļ��ಿ��Ҳ�����
};
class D2 : public Pal {
public:
	int mem(Base1 b)
	{
		//return b.prot_mem;
	}
};

void clobber(Sneaky1& s)
{
	s.j = s.prot_mem = 0;
}
void clobber(Base1& b)
{
	//b.prot_mem = 0;
}

class Base2 {
public:
	void pub_mem() { cout << "Base:pub_mem()" << endl; }
protected:
	int prot_mem;
private:
	char priv_mem;
};
struct Pub_Derv1 : public Base2 {
	int f()
	{
		pub_mem();
		return prot_mem;
	}
	char g() {
		//return priv_mem;// error
	}
	void memfcn(Base2 &b) { b = *this; }
};
struct Prot_Derv1 : protected Base2 {
	int f()
	{
		//Prot_Derv1 p;
		//Base2* b = &p;
		pub_mem();
		return prot_mem;
	}
	char g() {
		//return priv_mem;// error
	}
	void memfcn(Base2 &b) { b = *this; }
};
struct Priv_Derv1 : private Base2 {
	void memfcn(Base2 &b) { b = *this; }
	// private ��Ӱ��������ķ���Ȩ��
	int f1()const {
		//pub_mem();
		return prot_mem;
	}
	void testchange(Priv_Derv1 p)
	{
		pub_mem();
		p.pub_mem();
		Base2* bs = &p;
	}
public:
	int val = 0;
};
struct Dervied_from_Public : public Pub_Derv1 {
	void memfcn(Base2 &b) { b = *this; }
	int use_base() { return prot_mem; }
	void testchange(Pub_Derv1 &p)
	{
		pub_mem();
		Base2* bs = &p;
	}
	void testchange(Dervied_from_Public &p)
	{
		Base2* bs = &p;
	}
};
struct Dervied_from_Protected : public Prot_Derv1 {
	void memfcn(Base2 &b) { b = *this; }
	int use_base() { return prot_mem; }
	void testchange(Prot_Derv1 &p)
	{
		pub_mem();
		Base2* bs = &p;
	}
	void testchange(Dervied_from_Protected &p)
	{
		Base2* bs = &p;
	}
};
struct Dervied_from_Private : public Priv_Derv1 {
	//void memfcn(Base2 &b) { b = *this; }
	int use_base() {
		//return prot_mem; 
		return val;
	}
	//void testchange(Priv_Derv1 &p)
	//{
	//	pub_mem();
	//	Base2* bs = &p;
	//}
	void testchange(Dervied_from_Private &p)
	{
		//pub_mem();
		//Base2* bs = &p;
	}
};
class Base3 {
public:
	std::size_t size() const { return n; }
protected:
	std::size_t n;
};
class Derived3 :private Base3 {
public:
	using Base3::size;
	void testn() {
		n = 4;
		cout << n << endl;
	}
protected:
	using Base3::n;
};

// ��ϰ 
class XingZhuang {
public:
	virtual double area() { return 0; }
	virtual double zhouchang() { return 0; }
	virtual ~XingZhuang() {}
protected:
	double area;
	double zhouchang;
};
class juxing : public XingZhuang {
public:
	juxing() = default;
	juxing(double chang, double kuan) :chang(chang), kuan(kuan) {}
	virtual double area()
	{
		return chang * kuan;
	}
	virtual double zhouchang()
	{
		return (chang + kuan) * 2;
	}
	virtual ~juxing() {}
private:
	double chang;
	double kuan;
};
class yuan : public XingZhuang {
public:
	yuan() = default;
	yuan(double pie, double r) :pie(pie), r(r) {}
	virtual double area()
	{
		return pie * r * r;
	}
	virtual double zhouchang()
	{
		return 2 * pie * r;
	}
	virtual ~yuan() {}
private:
	double pie = 3.14;
	double r;
};
int main()
{
	int a;

	//Disc_quote dq;
	//Bulk_quote bk;

	//Pub_Derv1 d1;
	//Priv_Derv1 d2;
	//Priv_Derv1 &d3 = d2;
	//Base2 *bs = &d1;
	//Base2 *bs = &d2;
	//d2.testchange(d2);
	//d3.pub_mem();

	//d1.pub_mem();
	//d2.pub_mem();// ������
	//d2.prot_mem;

	//Derived3 dd3;
	//cout << dd3.size() << endl;
	//dd3.testn();

	Pub_Derv1 d1;
	Priv_Derv1 d2;
	Prot_Derv1 d3;
	Dervied_from_Public dd1;
	Dervied_from_Protected dd3;
	Dervied_from_Private dd2;
	Base2 *p1 = &d1;
	//p1 = &d2;
	//p1 = &d3;// protectedҲ����
	p1 = &dd1;
	//p1 = &dd2;
	//p1 = &dd3;


	// ��ϰ
	/*
	15.18: ok
	15.19:
	d1,d2,d3,dd1,dd2����
	d3���� ok
	15.20 ok
	15.21
	*/
	cin >> a;
	return 0;
}