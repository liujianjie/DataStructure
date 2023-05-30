#include <iostream>

using namespace std;
class Box5 {
public:
	int val1;
	Box5(int v1) :val1(v1) {

	}
	Box5(const Box5& box) {// 复制构造函数
		cout << "Box5(Box& box)" << endl;
	}
private:
	static int val2;
};
int Box5::val2 = 3;
Box5 Copy1(Box5 b) {
	return b;
}
int main()
{
	Box5 b51(3);
	Copy1(b51);
	cout << '\005' << endl;
	return 0;
}