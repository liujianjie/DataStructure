#include <iostream>
using namespace std;

class Complex {
public:
	double real;
	double imag;
	Complex() { real = 0;imag = 0; }						// 默认构造函数，无形参
	Complex(double r, double i):real(r), imag(i) {} // 实现初始化的构造函数，两个形参
	void display();
};
Complex operator+(Complex c1, Complex c2)	// 定义运算符+重载函数,非成员非友元
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
void Complex::display()
{
	cout << "(" << real << "," << imag << "i)" << endl;
}
int main()
{
	Complex c1(3, 4), c2(5, -10), c3;
	c3 = c1 + c2;
	c3.display();
	return 0;
}