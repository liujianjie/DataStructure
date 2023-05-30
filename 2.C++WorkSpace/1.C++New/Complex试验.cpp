#include <iostream>
#include <string>
using namespace std;

class Complex {
public:
	Complex() { cout << "�޲ι��캯��" << endl; a = 0; b = 0; }						// Ĭ�Ϲ��캯�������β�
	Complex(double r, double i) :a(r), b(i) { cout << "���ι��캯��" << endl; } // ʵ�ֳ�ʼ���Ĺ��캯���������β�
	Complex operator + (Complex& c2);
	Complex operator - (Complex& c2);
	Complex operator * (Complex& c2);
	Complex& operator / (Complex& c2);
	void display(string str);
private:
	double a;
	double b;
};
Complex Complex::operator+(Complex& c2)
{
	return Complex(a + c2.a, b + c2.b);
}
Complex Complex::operator-(Complex& c2)
{
	return Complex(a - c2.a, b - c2.b);
}
Complex Complex::operator*(Complex& c2)
{
	return Complex(a * c2.a - b * c2.b, b * c2.a + a * c2.b);
}
Complex& Complex::operator/(Complex& c2)
{
	Complex com((a * c2.a + b * c2.b) / (c2.a * c2.a + c2.b * c2.b), (b * c2.a - a * c2.b) / (c2.a * c2.a + c2.b * c2.b));
	return com;
}
void Complex::display(string str)
{
	cout << str << ":(" << a << "," << b << "i)" << endl;
}
int main()
{
	Complex c1(3, 4), c2(5, -10), c3;
	c3 = c1 + c2;
	c3.display("c3 = c1 + c2��ã�");
	c3 = c1 - c2;
	c3.display("c3 = c1 - c2��ã�");
	c3 = c1 * c2;
	c3.display("c3 = c1 * c2��ã�");
	c3 = c1 / c2;
	c3.display("c3 = c1 / c2��ã�");
	return 0;
}