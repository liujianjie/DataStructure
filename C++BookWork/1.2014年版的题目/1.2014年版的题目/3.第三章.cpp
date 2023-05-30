#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#pragma warning(disable:4996)


class XX {
public:
	int x;
public:
	XX(int xx = 0) : x(xx){}
	int getX() { return x; }
};
class YY : public XX {
	int y;
public:
	YY(int xx, int yy):XX(xx), y (yy){}
	int getV() { return getX() + y; }
};

template <class T>
void mySwap(T x, T y){}

int main()
{
	int a;
	
	double d1 = 1, d2 = 2;
	int i1 = 3, i2= 4;
	//mySwap(i1, d1);
	mySwap<int>(i2, d2);

	//ofstream ofs("data1.txt",ios_base::binary | ios_base::app);

	//if (ofs.good()) {
	//	ofs << "ok";
	//}
	//ofs.close();
	int i, s = 0;
	for (i = 1; s < 20; i += 2)
		s += i *i;

	cout << i << endl;

	int x = 4, y = 5;
	cout << (y > x++ ? x-- : y++) << endl;

	YY c(3, 4);
	cout << c.getV() + c.getX() << endl;

	cin >> a;
	return 0;
}