#include <iostream>
using namespace std;

class Complex {
public:
	double real;
	double imag;
	Complex() { real = 0;imag = 0; }						// Ĭ�Ϲ��캯�������β�
	Complex(double r, double i):real(r), imag(i) {} // ʵ�ֳ�ʼ���Ĺ��캯���������β�
	void display();
};
Complex operator+(Complex c1, Complex c2)	// ���������+���غ���,�ǳ�Ա����Ԫ
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