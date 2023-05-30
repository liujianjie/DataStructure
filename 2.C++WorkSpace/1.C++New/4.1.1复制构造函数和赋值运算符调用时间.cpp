#include <iostream>
using namespace std;

class Box {
public:
	Box(int = 10, int = 10, int = 10);
	// 复制构造函数
	Box(const Box&);
	// 赋值运算符
	Box& operator=(const Box &b) {
		cout << "Box赋值运算符" << endl;
		Box b2;
		b2.height = b.height;
		b2.width = b.width;
		b2.length = b.length;
		return b2;
	}
	int volume();
private:
	int height;
	int width;
	int length;
};
Box::Box(const Box& b) {
	cout << "Box复制构造函数代码" << endl;
	height = b.height;
	width = b.width;
	length = b.length;
}
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
	Box box1(15, 20, 30), box2;
	cout << "volume:box1:" << box1.volume() << endl;
	box2 = box1;// 不调用复制构造函数
	cout << "volume:box2:" << box2.volume() << endl;
	// 这才调用复制构造函数
	Box box3(box2);
	cout << "volume:box3:" << box3.volume() << endl;

	cout << "box4 = box3 start:" << box3.volume() << endl;
	Box box4 = box3; // 调用的是复制构造函数，而不是赋值运算符
	cout << "box4 = box3 end:" << box3.volume() << endl;
	return 0;
}

