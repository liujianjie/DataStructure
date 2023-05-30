#include <iostream>
using namespace std;

// 
class Complex {
public:
	Complex() { real = 0; imag = 0; }
	Complex(double r) { cout << "转换构造函数" << endl; real = r; imag = 0; }			// 转换构造函数
	//operator double() { cout << "类型转换函数" << endl; return real; }					// 类型转换函数
	Complex(double r, double i) { real = r; imag = i; } // 初始化的构造函数
	void Display();
	// 友元
	friend Complex operator+(Complex c1, Complex c2);
private:
	double real;
	double imag;
};

Complex operator+(Complex c1, Complex c2) {
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
void Complex::Display() {
	cout << "(" << real << "," << imag << "i)" << endl;
}
// 类型转换函数
class TestType {
public:
	TestType() { real = 0; imag = 0; }
	operator double() { return real; }					// 类型转换函数
	TestType(double r, double i) { real = r; imag = i; } // 初始化的构造函数
	void Display();
private:
	double real;
	double imag;
};


int main()
{
	Complex c1(3, 4), c2(5, -10), c3;
	//c3 = c1 + c2;// 转换构造函数
	//c3.Display();
	//c3 = c1 + 2.5;// 转换构造函数
	//c3.Display();
	//c3 = 2.5 + c1;// 转换构造函数
	//c3.Display();
	//double d1 = 2.5 + c2; // 类型转换函数

	// 测试类型转换
	TestType t1(3, 5), t2(2,0);
	double d1 = t1 + 2.5;// 类型转换函数
	cout << d1 << endl;
	double d2 = 2.5 + t1;// 类型转换函数
	cout << d2 << endl;
	return 0;
}

