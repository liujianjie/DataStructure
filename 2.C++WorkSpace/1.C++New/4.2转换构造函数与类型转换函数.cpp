#include <iostream>
using namespace std;

// 
class Complex {
public:
	Complex() { real = 0; imag = 0; }
	Complex(double r) { cout << "ת�����캯��" << endl; real = r; imag = 0; }			// ת�����캯��
	//operator double() { cout << "����ת������" << endl; return real; }					// ����ת������
	Complex(double r, double i) { real = r; imag = i; } // ��ʼ���Ĺ��캯��
	void Display();
	// ��Ԫ
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
// ����ת������
class TestType {
public:
	TestType() { real = 0; imag = 0; }
	operator double() { return real; }					// ����ת������
	TestType(double r, double i) { real = r; imag = i; } // ��ʼ���Ĺ��캯��
	void Display();
private:
	double real;
	double imag;
};


int main()
{
	Complex c1(3, 4), c2(5, -10), c3;
	//c3 = c1 + c2;// ת�����캯��
	//c3.Display();
	//c3 = c1 + 2.5;// ת�����캯��
	//c3.Display();
	//c3 = 2.5 + c1;// ת�����캯��
	//c3.Display();
	//double d1 = 2.5 + c2; // ����ת������

	// ��������ת��
	TestType t1(3, 5), t2(2,0);
	double d1 = t1 + 2.5;// ����ת������
	cout << d1 << endl;
	double d2 = 2.5 + t1;// ����ת������
	cout << d2 << endl;
	return 0;
}

