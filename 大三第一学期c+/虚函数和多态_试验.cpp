#include <iostream>
#include <iomanip>
#include <string>
#include <corecrt_math_defines.h>
using namespace std;

class Base {
public:
	virtual double getArea() const = 0;
	void display(double area)
	{
		cout << name << "的面积是:" << area << endl;
	}
	string name;
};
class Circle :public Base {
public:
	Circle(double r) : radius(r) { name = "圆形"; }
	virtual double getArea() const
	{
		return M_PI * radius * radius;
	}
private:
	double radius;

};
class Triangle :public Base {
public:
	Triangle(double b1, double b2, double b3) : a(b1), b(b2), c(b3) { name = "三角形"; }
	virtual double getArea() const
	{
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
private:
	double a;
	double b;
	double c;
};
int main()
{
	Base* pi;
	pi = new Circle(3);
	pi->display(pi->getArea());
	pi = new Triangle(3, 4, 5);
	pi->display(pi->getArea());
	return 0;
}