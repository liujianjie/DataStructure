#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

namespace NS {
	class Quote{
		void display(const Quote&) {
			cout << "Quote::display(const Quote&)" << endl;
		}
	};
	void display(const Quote&) {
		cout << "Ns::display(const Quote&)" << endl;
	}
}
class Bulk_item : public NS::Quote {
};

namespace A {
	void prints() {
		cout << "namespace A:prints()" << endl;
	}
	void prints(double) {
		cout << "namespace A:prints(double)" << endl;
	}
}
void prints() {
	cout << "all namespace A:prints()" << endl;
}
//using A::prints;
namespace Aw {
	int prints(int) {
		cout << "Aw::prints(int):" << endl;
		return 0;
	}
	void prints() {
		cout << "Aw namespace A:prints()" << endl;
	}
}
using namespace A;// ���ᱨ��
using namespace Aw;

namespace primerLib {
	void compute()
	{
		cout << "void compute()" << endl;
	}
	void compute(const void*)
	{
		cout << "void compute(const void*)" << endl;
	}
}
//void compute(int) 
//{
//	cout << "void compute(int)" << endl;
//}

void compute(double, double = 3.4)
{
	cout << "void compute(double, double = 3.4)" << endl;
}
void compute(char*, char* = 0)
{
	cout << "void compute(char*, char* = 0)" << endl;
}
//using primerLib::compute;
void f() 
{
	using primerLib::compute;
	compute(0);
}

int main()
{
	int a;

	//f();
	f();
	/*Bulk_item bk;
	display(bk);*/

	//using A::prints;// �����������
	//prints();
	//::prints();
	//A::prints();

	//::prints();
	//prints(1);
	//prints(1.2);
	
	/*
	��ϰ��
	18.18:
	�²⣺
	void compute()// ������ �ɼ�
	void compute(const void*)// ���� �ɼ�
	void compute(int);// ���� �ɼ� ���ƥ��
	void compute(const void*):// ���� �ɼ�
	void compute(double, double = 3.4);// ���� �ɼ�
	void compute(char*,char*=0);// ���� �ɼ�
	
	2.
	void compute()// ������ �ɼ�
	void compute(const void*):// ���� �ɼ�
	void compute(int);// ���� ���ɼ� ��������
	void compute(const void*):// ���� ���ɼ� ��������
	void compute(double, double = 3.4);// ���� ���ɼ� ��������
	void compute(char*,char*=0);// ���� ���ɼ� ��������
	*/
	cin >> a;
	return 0;
}
