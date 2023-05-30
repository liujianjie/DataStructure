#include <iostream>
#include <iomanip>
#include <string>
#include <corecrt_math_defines.h>
using namespace std;

class Shape {
public:
	virtual double getArea() const = 0;
	void display(double area) 
	{
		cout << name << "的面积是:" << area << endl;
	}
	string name;
};
class Circle : public Shape {
public:
	Circle(double r) : radius(r) { name = "圆形"; }
	virtual double getArea() const 
	{
		return M_PI * radius * radius;
	}
private:
	double radius;

};
class Square : public Shape {
public:
	Square(double w) : width(w) { name = "正方形"; }
	virtual double getArea() const
	{
		return width * width;
	}
private:
	double width;
};
class Rectangle : public Shape {
public:
	Rectangle(double w, double h) : width(w), height(h) { name = "矩形"; }
	virtual double getArea() const
	{
		return width * height;
	}
private:
	double width;
	double height;
};
class Trapezoid : public Shape {
public:
	Trapezoid(double t, double b, double h) : top(t), bottom(b), height(h) { name = "梯形"; }
	virtual double getArea() const
	{
		return (top + bottom) * height / 2;
	}
private:
	double top;
	double bottom;
	double height;
};
class Triangle : public Shape {
public:
	Triangle(double b1, double b2, double b3) : a(b1), b(b2), c(b3) { name = "三角形"; }
	virtual double getArea() const
	{
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p -c));
	}
private:
	double a;
	double b;
	double c;
};
int main() 
{
	Shape* sh[] = {new Circle(2), new Square(2), new Rectangle(2, 3), new Trapezoid(2, 3, 4), new Triangle(3, 4, 5)};
	double totalArea = 0.0f;
	for (int i = 0; i < 5; i++) 
	{
		double curArea = sh[i]->getArea();
		sh[i]->display(curArea);
		totalArea += curArea;
	}
	cout << "5个图形的面积和是：" << totalArea << endl;
	return 0;
}