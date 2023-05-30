#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

namespace A {
	int i;
	namespace B {
		int i;
		int j;
		int f1() {
			int j;
			return i;
		}
	}
	//int f2() {
		//return j;// 没有定义，点之后才有
	//}
	int j = i;
}

namespace AA {
	int i = 2;
	int k;
	class C1 {
	public:
		C1():i(0),j(0){}
		int f1() { return k; }
		//int f2() { return h; }
		int f3();
	private:
		int i;
		int j;
		//int h = 4;
	};
	int h = i;
}
// 定义f3
int AA::C1::f3() {
	return h;
}
class Test;
namespace stds {
	class Test {
	public:
		void swaps(const Test&);
	};
	void Test::swaps(const Test&) {
		cout << "Test:swaps()" << endl;
	}
	void swaps(const Test&) {
		cout << "stds:swaps()" << endl;
	}
}

namespace AAA {
	class C {
		friend void f2();
		friend void f(const C&);
		
	public:
		void f3();
		void f4(const C&);
		void f5(const C&) {
			cout << "class f5(const C&)" << endl;
		}
	};
	void f(const C& c) {
		cout << "f(const C&);" << endl;
	}
	void f2() {
		cout << "f2()" << endl;
	}
	void C::f3() {
		cout << "f3()" << endl;
	}
	void f4(const C&) {
		cout << "namespace f4(const C&)" << endl;
	}
	void f5(const C&) {
		cout << "namespace f5(const C&)" << endl;
	}
}

int main()
{
	int a;
	using A::B::f1;
	f1();

	using AA::C1;
	C1 c1;
	cout << c1.f3() << endl;

	std::string s;
	//std::cin >> s;
	//operator >> (std::cin, s);
	using AAA::C;
	C obj;
	f(obj);// 会去找obj的命名空间
	obj.f3();
	f4(obj);
	f5(obj);
	//obj.f4(obj);
	//f2();// 不可

	using stds::Test;
	Test t1;
	swaps(t1);
	stds::swaps(t1);
	/*
	练习：
	18.18:
	using std::swap
	swap(v1.mem1,v2.mem1);

	猜测：
	using std::swap应该是声明使用std下的swap
	当传入string时，string是类型，会先搜索string里的swap，若找不到才使用std声明的swap

	传入int，不是类型，直接std下的swap

	但是我试得却只找std的**

	18.19:显示使用std的
	*/
	cin >> a;
	return 0;
}
