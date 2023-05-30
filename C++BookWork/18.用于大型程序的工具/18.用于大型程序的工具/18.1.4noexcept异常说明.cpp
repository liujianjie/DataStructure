#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <cstdlib>
using namespace std;

void recoup(int) noexcept;
void recoup2(int) noexcept;
void alloc(int);

void recoup(int) noexcept
{

}
void recoup2(int) noexcept
{
	throw exception();
}
void alloc(int) {

}
void recoup3(int) throw()
{

}

void recoup4() noexcept(true){}// ���׳�
void recoup5(int) noexcept(false){}// �׳�

void recoup6(int) noexcept(noexcept(recoup4())) {
	throw exception();
}

class Base {
public:
	virtual double f1(double) noexcept{}
	virtual int f2() noexcept(false){}
	virtual void f3(){}
	virtual ~Base() noexcept {

	}
};
class Derived :public Base {
public:
	double f1(double) noexcept{}
	int f2() noexcept(false){}
	void f3() noexcept{}//�������
	virtual ~Derived() noexcept{

	}
};
int main()
{
	int a;

	//recoup6(1);
	cout << boolalpha;
	cout << noexcept(recoup4()) << endl;
	cout << noexcept(recoup5(3)) << endl;
	try
	{
		//recoup2(3);// ֱ��terminate
	}
	catch (const std::exception& e)
	{
		cout << "exception:" << e.what() << endl;
	}
	void(*pf1)(int) noexcept = recoup;
	void(*pf2)(int) = recoup;
	//pf1 = alloc;
	//pf2 = alloc;


	/*
	��ϰ�����ˣ�֪��noexcept���У��������������������noexcept����
	*/
	cin >> a;
	return 0;
}
