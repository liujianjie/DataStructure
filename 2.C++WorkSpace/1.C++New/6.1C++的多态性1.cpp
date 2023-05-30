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

ostream& operator<<(ostream& output, const Point& p)
{
	output << "Point [" << p.x << "," << p.y << "]" << endl;
	return output;
}

ostream& operator<<(ostream& output, const Circle& c)
{
	output << "Circle Center=[" << c.x << "," << c.y << "],r=" << c.radius << ", area=" << c.Area() << endl;
	return output;
}


int main()
{
	Circle c(3.5, 6.4, 5.2);
	cout << "original circle:\nx =" << c.GetX() << ",y=" << c.GetY() << ",r=" << c.GetRadius() << ",area=" << c.Area() << endl;
	c.SetRadius(7.5);
	c.SetPoint(5,5);
	cout << "new circle:\n" << c;
	Point& pRef = c;
	cout << "pRef:" << pRef;

	return 0;
}

