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
转换构造函数和类型转换运算符共同定义了：类类型转换，也称：用户定义的类型转换
转换构造函数：将其他类型转换为本类对象，定义构造函数就可以，非exclipt
类型转换运算符：将本类转换成其他类型, operator type() const

类型转换运算符可以面向任意类型，除了void之外，并且需要该类型作为函数的返回类型，所以数组或者函数类型不可，但可以转换成指针，或者引用

类型转换运算符
1、没有显式的返回类型，也没有形参
2、必须定义成类的成员函数
3、通常不应该改变待转换对象的内容 const

定义含有类型转换运算符的类
1.尽管编译器一次只能执行一次类型转换，但是能将得到后的类型转换再转换成任何其它算术类型
2.类型转换运算符是隐式执行的，所以无法给这些函数传递实参，相应也不能定义任何形参
3.虽然不负责指定返回类型，但实际上回返回一个对应类型的值

note:避免过度使用类型转换函数
特别是Date类型的对象和int类型的值之间不存在一对一映射关系，因此，不定义该类型转换运算符也许会更好

二、类型转换运算符可能产生意外结果
因为许多内置类型定义了bool类型转换运算符
并且bool是一种算术类型，可以将bool运用到任何需要算术类型的上下文中

三、显式的类型转换运算符
为了防止上述问题，新引入了显式的类型转换运算符。
(static_cast<int>(si1) + 3)	

存在一个例外，当表达式被用作条件，编译器会将显式的类型自动转换应用于它
当表达式出现在下列位置时，显式的类型转换将被隐式地执行
1.if while do
2.for
3.!|| &&
4. ?:

四、转换为bool
早期：IO类型定义了向void*转换规则
现在：Io标准库通过定义一个向bool的显式类型转换实现同样目的
无论什么时候在条件中使用流对象，都会使用为IO类型定义的operatorbool

向bool的类型转换通常用在条件不符，因此operator bool一般定义explicit


*/
//
struct Integral {
	Integral(double i = 0) : val(i),intct(2) {
		if (i < 0 || i > 255)
			throw std::out_of_range("bad value");
	}
	// 调用者是this，转为const int
	operator const int() {
		cout << "operator const int() " << endl;
		return intct;
	}
	// 调用者可以是this const this，精确匹配const this，转为int
	operator int() const {
		cout << "operator int() const  " << endl;
		return intc;
	}
private:
	double val;
	const int intct;
	int intc;
};
class SamllInt {
public:
	// 转换构造函数
	SamllInt(int i = 0) : val(i) {
		if (i < 0 || i > 255)
			throw std::out_of_range("bad value");
	}
	explicit operator int() const { return val; }
	// 类型转换运算符
	//operator int() const { return val; }
	//int operator int() const;//错误 返回类型
	//operator int(int = 0)const;//错误 形参 
	//operator int*() const { return 42; }//错误，42不是一个指针
private:
	std::size_t val;
};
int main()
{
	int a;

	SamllInt si1;
	si1 = 4;// 转换构造函数
	//cout << si1 + 3 << endl;// si1转换为int

	SamllInt si2 = 3.14;
	//si2 + 3.15;// 先转换为int再转double

	int val1 = 42;
	//std::cin << val1; 如果cin中向bool的类型转换不是显式的，则是合法的
	// 并且将cin转为bool，bool为0或1向左移动42位

	SamllInt si3;
	// 显式的强制类型转换
	cout << (static_cast<int>(si1) + 3) << endl;// si1转换为int

	int value;
	//while (std::cin >> value);// 若条件状态是good，则为真 否为假

	Integral i1;
	const Integral i2;

	// i1调用返回const int，可以赋给其它值，但是不能修改
	const int a1 = i1;
	int a2 = i1;
	int a3 = i2;

	Integral i3(5.0);
	int a4 = i3;
	cout << a4 << endl;

	Employee e1;
	if (e1) {
		cout << "Employee e1" << endl;
	}

	// 练习
	/*
	14.45,返回bookno，double的话应该返回price的
	14.46:不应该，麻烦，除非是bool
	14.47：ok
	14.48：employee不需要bool，需要的话要explicit 规定
	14.49：ok
	*/
	cin >> a;
	return 0;
}