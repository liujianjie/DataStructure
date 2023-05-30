#include <iostream>
using namespace std;
#define PIE 3.14159

// ������� 
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
	virtual float Area() const;// ʵ�ֶ�̬��̬�Ĺؼ� 
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

// �ຯ���Ķ��� 
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
	return 2 * PIE * radius * height + 2 * Circle::Area(); // һ������+����Բ�� 
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
	// �뺯����̬����
	cout << "original cylinder:\nx=" << cy1.GetX() << ",y=" << cy1.GetY() << ",r=" << cy1.GetRadius() << ",h=" << cy1.GetHeight()
		<< "\narea=" << cy1.Area() << ",volume=" << cy1.Volume() << endl;
	cy1.SetHeight(15);
	cy1.SetRadius(7.5);
	cy1.SetPoint(5, 5);
	cout << "\nnew cylinder:\n" << cy1;

	Point& pRef = cy1;
	// �뺯����̬����
	cout << "\npRef as a point1:" << pRef;

	Circle& cRef = cy1;
	// ��̬����������Circle�������������
	// ��̬������������õ���cylinder�е�area�����������Ϊ������������е��õ�����������麯���������н׶ΰ��麯������������һ��
	cout << "\ncRef as a Circle2:" << cRef;

	Circle* c1 = new Circle(1, 2, 3);
	// ��̬����
	cout << "Բ������ǣ�" << c1->Area();

	c1 = &cy1;// ��
	// ��̬�����������н׶ΰ��麯������������һ��
	cout << "\nԲ��������ǣ�" << c1->Area();

	return 0;
}

