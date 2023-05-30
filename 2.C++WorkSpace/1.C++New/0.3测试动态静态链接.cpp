#include <iostream>
using namespace std;
#define PIE 3.14159

// 类的声明 
class Point
{
public:
	Point(float a, float b) :x(a), y(b) {};
	void SetPoint(float, float);
	float GetX() const { return x; }
	float GetY() const { return y; }
	friend ostream& operator<<(ostream&, const Point&);
public:
	float x;
	float y;
};
class Circle : public Point
{
public:
	Circle(float a, float b, float r) :Point(a, b), radius(r) {};
	void SetRadius(float);
	float GetRadius() const;
	virtual float Area() const;// 实现动态多态的关键 
	friend ostream& operator<<(ostream&, const Point&);
public:
	float radius;
};
class Cylinder :public Circle
{
public:
	Cylinder(float a, float b, float r, float h) :Circle(a, b, r), height(h) {};
	void SetHeight(float);
	float GetHeight() const;
	float Area() const;
	float Volume() const;
	friend ostream& operator<<(ostream&, const Cylinder&);
public:
	float height;
};

// 类函数的定义 
void Point::SetPoint(float a, float b)
{
	x = a;
	y = b;
}

void Circle::SetRadius(float r)
{
	radius = r;
}
float Circle::GetRadius() const
{
	return radius;
}
float Circle::Area() const
{
	return PIE * radius * radius;
}

void Cylinder::SetHeight(float h)
{
	height = h;
}
float Cylinder::GetHeight() const
{
	return height;
}
float Cylinder::Area() const
{
	return 2 * PIE * radius * height + 2 * Circle::Area(); // 一个矩形+两个圆形 
}
float Cylinder::Volume() const
{
	return Circle::Area() * height;
}

ostream& operator<<(ostream& output, const Point& p)
{
	output << "Point[" << p.x << "," << p.y << "]" << endl;
	return output;
}

ostream& operator<<(ostream& output, const Circle& c)
{
	output << "Circle Center=[" << c.x << "," << c.y << "],r=" << c.radius << ", area=" << c.Area() << endl;
	return output;
}

ostream& operator<<(ostream& output, const Cylinder& cy)
{
	output << "Cylinder Center=[" << cy.x << "," << cy.y << "],r=" << cy.radius << ",h="
		<< cy.height << "\narea=" << cy.Area() << ",volume=" << cy.Volume() << endl;
	return output;
}
int main()
{
	Cylinder cy1(3.5, 6.4, 5.2, 10);
	// 与函数静态关联
	cout << "original cylinder:\nx=" << cy1.GetX() << ",y=" << cy1.GetY() << ",r=" << cy1.GetRadius() << ",h=" << cy1.GetHeight()
		<< "\narea=" << cy1.Area() << ",volume=" << cy1.Volume() << endl;
	cy1.SetHeight(15);
	cy1.SetRadius(7.5);
	cy1.SetPoint(5, 5);
	cout << "\nnew cylinder:\n" << cy1;

	Point& pRef = cy1;
	// 与函数静态关联
	cout << "\npRef as a point1:" << pRef;

	Circle& cRef = cy1;
	// 静态关联：调用Circle的重载输出函数
	// 动态关联：面积调用的是cylinder中的area面积函数，因为重载输出函数中调用的面积函数是虚函数！在运行阶段把虚函数和类对象绑定在一起
	cout << "\ncRef as a Circle2:" << cRef;

	Circle* c1 = new Circle(1, 2, 3);
	// 静态关联
	cout << "圆的面积是：" << c1->Area();

	c1 = &cy1;// 绑定
	// 动态关联：在运行阶段把虚函数和类对象绑定在一起
	cout << "\n圆柱的面积是：" << c1->Area();

	return 0;
}

