#include <iostream>
using namespace std;

class Circle {
public:
	int val;
};
class Box {
public:
	Box(int = 10, int = 10, int = 10);
	int volume();
	Box& operator=(const Box& box) {
		cout << "赋值运算符" << endl;
		Box b1;
		b1.height = box.height;
		b1.width = 2;
		b1.length = 2;
		return b1;
	}
public:
	int* pointint;
	Circle c;
	int data[10];
private:
	int height;
	int width;
	int length;
};

Box::Box(int h, int w, int len) {
	cout << "Box构造函数代码" << endl;
	height = h;
	width = w;
	length = len;
}
int Box::volume() {
	return (height * width * length);
}
int main()
{
	//Box box1(15, 20, 30), box2;
	//int val2 = 2;
	//box1.pointint = &val2;
	//box1.c.val = 30;
	//box1.data[0] = 10;

	//cout << "Box1.pointint : " << *box1.pointint << endl;;
	//cout << "Box1.box1.c.val : " << box1.c.val << endl;;
	//cout << "Box1.box1.data[0] : " << box1.data[0] << endl;;
	//cout << "volume:box1:" << box1.volume() << endl;

	//box2 = box1;// 不调用复制构造函数
	//cout << "volume:box2:" << box2.volume() << endl;
	//cout << "Box2.box1.c.val : " << box2.c.val << endl;;
	//cout << "Box2.box2.data[0] : " << box2.data[0] << endl;; // 数组照样拷贝
	//cout << "Box2.pointint : " << box2.pointint << endl;; // 指针照样赋值

	Box box1(15, 20, 30), box2;
	cout << "volume:box1:" << box1.volume() << endl;
	box2 = box1;// 不调用复制构造函数
	cout << "volume:box2:" << box2.volume() << endl;
	return 0;
}

