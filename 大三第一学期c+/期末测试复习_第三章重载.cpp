#include <iostream>
using namespace std;

class Complex {
public:
	Complex() {
		real = 0;
		imag = 0;
	}
	Complex(double r) {
		cout << "Complex(double r)" << endl;
		real = r;
		imag = 0;
	}
	Complex(double r, double i) {
		real = r;
		imag = i;
	}
	//operator double() {
	//	cout << "operator double" << endl;
	//	return real;
	//}
	//Complex operator+(Complex &c1) {
	//	cout << "+" << endl;
	//	Complex c;
	//	return c;
	//}
	friend Complex operator+(Complex c1, Complex c2);
private:
	double real;
	double imag;
};
Complex operator+(Complex c1, Complex c2)
{
		cout << "+" << endl;
		return c1;
}
int main()
{
	Complex co1, co2(3.5, 3);
	//co1 = 2.5;
	co1 = co2 + 2.5;
	//co1 = co2.operator+((Complex)2.5);

	return 0;
}