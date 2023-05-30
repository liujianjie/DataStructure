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
using namespace A;// 不会报错
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

	//using A::prints;// 可以隐藏外层
	//prints();
	//::prints();
	//A::prints();

	//::prints();
	//prints(1);
	//prints(1.2);
	
	/*
	练习：
	18.18:
	猜测：
	void compute()// 不可行 可见
	void compute(const void*)// 可行 可见
	void compute(int);// 可行 可见 最佳匹配
	void compute(const void*):// 可行 可见
	void compute(double, double = 3.4);// 可行 可见
	void compute(char*,char*=0);// 可行 可见
	
	2.
	void compute()// 不可行 可见
	void compute(const void*):// 可行 可见
	void compute(int);// 可行 不可见 被隐藏了
	void compute(const void*):// 可行 不可见 被隐藏了
	void compute(double, double = 3.4);// 可行 不可见 被隐藏了
	void compute(char*,char*=0);// 可行 不可见 被隐藏了
	*/
	cin >> a;
	return 0;
}
