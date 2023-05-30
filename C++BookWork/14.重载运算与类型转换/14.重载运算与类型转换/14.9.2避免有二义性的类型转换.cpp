#include <iostream>
#include "String.h"
#include <map>
#include "Sales_data.h"
#include "StrVec.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Employee.h"
#include <memory>
#include <functional>
#include "NewClass1432.h"
using namespace std;

/*
引出：
如果类中包含一个或多个类型转换，则必须确保在类类型和目标类型之间只存在唯一一种转换方式。否则存在二义性

如：
第一种：两个类提供相同的类型转换
A类定义一个接受B类对象的转换构造函数
B类定义了一个转换目标是A类的类型转换运算符
第二种：类定义了多个转换规则，类型转换运算符
算术运算符，这些转换涉及的类型本身可以通过其他类型转换联系到一起

第一种：
只能显式指定哪个，但是不能使用强制类型转换来解决，因为强制转换也面临二义性

第二种：
定义：类定义一组类型转换，他们的转换目标可以通过其他类型联系到一起，则二义性
标准库类型转换将决定最佳匹配到底是哪个

note：除了显示地向bool类型的转换之外，尽量避免定义类型转换函数并
尽可能地限制那些 “显然正确"的非显示构造函数

三、重载函数与转换构造函数
当我们调用重载的函数时，从多个类型转换中进行选择将变得更加复杂
如果两个或多个类型转换都提供了同一种可行匹配，则这些类型转换一样好

简单的列子：两个类都有int转换构造函数，两个重载函数都有这个类对象，调用时传入int值应该调用哪个重载函数

显示的指定是哪个类对象可以解决

note：若需要使用构造函数或强制类型转换来改变实参的类型，意味程序设计补足

四、重载函数与用户定义的类型转换
引出：调用重载函数，若多个用户定义的类型转换都提供了可行匹配，则认为这些类型转换一样好，
这一过程不会考虑任何可能出现的标准库转换的优先。
只有当重载函数只能通过一个类型转换函数得到匹配时，才考虑标准库类型优先级，像 上面提到的第二种

练习:
14.51: 必须显示类型转换才会调用第二种，否则调用int。
只有一种类型转换，所以会考虑优先级吧，不，是因为标准库优先级优于对象.
只有一种类型转换，所以会考虑优先级是说的是转换构造函数或类型转换里的优先级
*/
// 第一种：
struct B;
struct A {
	A() = default;
	A(const B&){}
};
struct B {
	operator A() const{
		return a;
	}
	A a;
};
A f(const A&)
{
	A a;
	return a;
}
struct Test {
public:
	operator int() {
		return 3;
	}
};
// 第二种
struct C {
	C() {
	}
	C(int){
		cout << "C(int = 0)" << endl;
	}
	C(double){
		cout << "C(double)" << endl;
	}
	operator int()const{
		return 2;
	}
	operator double() const{
		return 4.0;
	}
};
void f2(long double l) {
	cout << "f2():" << l << endl;
}

struct CC {
	CC(int){}
};
struct DD {
	DD(int){}
};
struct EE {
	EE(double){}
};
void manip(const CC&)
{
}
void manip(const DD&)
{
}

void manip2(const CC&)
{
}
void manip2(const EE&)
{
}

struct LongDouble {
	LongDouble(double = 0.0){}
	operator double() { return 2.0; }
	operator float() { return 1.0; }
	//operator short() { return 1; }
};
struct LongDouble2 {
	LongDouble2(double = 0.0) {}
};
void calc(int)
{
	cout << "void calc(int)" << endl;
}
void calc(LongDouble)
{
	cout << "void calc(LongDouble)" << endl;
}
void calc(LongDouble2)
{
	cout << "void calc(LongDouble2)" << endl;
}
int main()
{
	int a;
	B b;
	//A a = f(b);//两个 是A的转换构造 还是 B的类型转换为A
	// 只能显式指定哪个，但是不能使用强制类型转换来解决，因为强制转换也面临二义性
	A a1 = f(b.operator A());
	A a2 = f(A(b));

	Test t1;
	cout << t1 << endl;

	C c1;
	//f2(c1);// 类型转换二义性

	long long lg = 4;
	//C c2(lg);// 两个转换构造都可
	short stval = 3;
	C c3(stval);// short 转为int 优于double，标准库类型转换将决定最佳匹配到底是哪个

	// 三
	//manip(10);
	manip(CC(10));
	//manip2(10); 不考虑标准库的优先级

	// 练习
	LongDouble ldObj;
	//int ex1 = ldObj;// 有最佳的short可选，c+向上转型有匹配规则,这里只有向下没有最优，即二义性
	float ex2 = ldObj;

	double dval = 0.0;
	calc(dval);
	//calc(LongDouble(dval));
	/*
	14.50：好吧，还是二义性，无法，应该是第二种问题)  再用float，
	14.51: 必须显示类型转换才会调用第二种，否则调用int。只有一种类型转换，所以会考虑优先级吧，不，是因为标准库优先级优于对象，只有一种类型转换，所以会考虑优先级是说的是转换构造函数或类型转换里的优先级
	*/
	cin >> a;
	return 0;
}