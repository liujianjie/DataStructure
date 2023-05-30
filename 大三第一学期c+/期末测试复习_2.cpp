#include <iostream>
using namespace std;

class Box {
public:
	Box(int = 10, int = 10, int = 10);
	Box(const Box&);
	Box& operator=(const Box&);
	int volume();
private:
	int height;
	int width;
	int length;
};
Box::Box(int h, int w, int len) {
	height = h;
	width = w;
	length = len;
	cout << "Box" << endl;
}

Box::Box(const Box& b) {
	height = b.height;
	width = b.width;
	length = b.length;
	cout << "Box::Box(const Box& b)" << endl;
}
Box& Box::operator=(const Box& b) {
	Box x;
	x.height = b.height;
	x.width = b.width;
	x.length = b.length;
	cout << "Box& Box::operator=()" << endl;
	return x;
}
int Box::volume() {
	return height * width * length;
}
int main()
{
	Box box1(15, 30, 25), box2;
	cout << "Volum" << box1.volume() << ",Volum2" << box2.volume() << endl;
	box2 = box1;
	Box box3(box1);
	Box box4 = box1;
	Box box5;
	box5 = box1;
	cout << "Volum" << box2.volume();
	return 0;
}