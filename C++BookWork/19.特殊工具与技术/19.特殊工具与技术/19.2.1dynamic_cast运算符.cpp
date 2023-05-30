#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "ZooClass.h"
using namespace std;

class A{
public:
	A() {}
	virtual ~A() {

	}
};
class B:public A{
public:
	B() {}
	virtual ~B() {

	}
};
class C :public B{
public:
	C() {}
	virtual ~C() {

	}
};
class D:public B,public A{
public:
	D() {}
	virtual ~D() {

	}
};
int main()
{
	int a;
	// ����ת�ͣ�����
	ZooAnimal z0;
	Bear ba0 = dynamic_cast<Bear&>(z0);

	cout << "----" << endl;
	Panda *pa1 = new Panda;
	Bear *ba1 = new Bear;
	ZooAnimal *z1 = new ZooAnimal;
	Bear *ba2 = dynamic_cast<Bear*>(pa1);
	Bear *ba3 = dynamic_cast<Bear*>(z1);
	cout << "ba3" << ba3 << endl;
	Bear *ba4 = dynamic_cast<Bear*>(ba1);

	Panda *pa2 = 0;
	Bear *ba5 = dynamic_cast<Bear*>(pa2);
	cout << ba5 << endl;

	Panda pa3;
	Panda &pa4 = pa3;
	Bear &ba6 = dynamic_cast<Bear&>(pa4);
	//Bear &ba7 = dynamic_cast<Bear&>((&pa3));

	Bear &&ba8 = dynamic_cast<Bear&&>(pa4);// ��������ֵ

	cout << "-----��ϰ-------" << endl;
	A *pa = new C;
	B *pb = dynamic_cast<B*>(pa);
	//B *pb = new B;
	//C *pc = dynamic_cast<C*>(pb);
	//cout << pc << endl;// ת��ʧ��Ү������ת�ͻ�ʧ�ܡ�
	//A *pa = new D;
	//B *pb = dynamic_cast< B* >(pa);

	A *pa = new C;
	B *pbb = new B;
	A *paa = new D;
	if (B *pb = dynamic_cast<B*>(pa))
	{
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	if (C *pc = dynamic_cast<C*>(pbb))
	{
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	if (B *pb = dynamic_cast< B* >(paa))
	{
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	try
	{
		ZooAnimal *z0 = new ZooAnimal;
		// �����׳��쳣����֧������ת��
		//C& cp = dynamic_cast<C&>(*pbb);
		//Bear ba0 = dynamic_cast<Bear&>(z0);
		
		// ָ�벻�׳��쳣����ָ��ֵΪ0
		//C *pc = dynamic_cast<C*>(pbb);
		//Bear *ba00 = dynamic_cast<Bear*>(z0);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	/*
	��ϰ��
	19.3:
	a.����
	b.������ ��֧������ת��
	c.����
	19.4:
	ok
	19.5��
	������ʹ���麯������Ҫ�û���ָ������õ����������Ա��ʱ��
	��dynamic_castֱ��ת��Ϊ�����࣬��ֱ�ӵ�����������麯����Ա

	*/
	cin >> a;
	return 0;
}