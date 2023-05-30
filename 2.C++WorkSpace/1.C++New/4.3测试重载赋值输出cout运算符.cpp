#include <iostream>
using namespace std;

class Complex {
public:
	Complex(){}
	Complex(int r, double i):real(r),img(i){
		cout << "带参的构造函数" << endl;
	}
	Complex(const Complex& com) {
		cout << "复制构造" << endl;
		this->real = com.real;
		this->img = com.img;
	}
	Complex& operator=(const Complex& com) {
		cout << "赋值运算符" << endl;
		// 以下的赋值方法都是错误的，因为方法体结束后临时变量会销毁
		//Complex coms;
		//coms = com; // 赋值运算符重复调用
		//Complex coms(com); // 调用复制构造函数，没重写，是不会有数据的
		//Complex coms(com.real, com.img);
		//Complex coms;
		//coms.img = co.img;
		//coms.real = co.real;
		//return coms;
		Complex coms(com.real, com.img);
		return coms;
		// ，要返回this的指针才行
		//this->real = com.real;
		//this->img = com.img;
		//return *this;
	}
	Complex& operator+(const Complex &com) {
		cout << "+运算符" << endl;
		Complex coms(this->real + com.real, this->img + com.img);
		return coms;
	}
	~Complex() {
		//cout << "析构" << endl;
	}
public:
	int real;
	double img;
};
ostream& operator<<(ostream& os,const Complex& b) {
	os << b.real << " " << b.img;
	return os;
}
int main()
{
	// 测试赋值与重载，什么时候析构
	Complex cp1(12, 2.4), cp3(11, 3.4),cp2;
	cp2 = cp1; // 若返回临时对象，先调用完赋值运算符再析构
	Complex cp4 = cp1 + cp3; // 复制构造前就析构？
	cout << cp4 << endl;
	getchar();

	//Complex c1(12, 2.3);
	//Complex c3(12, 2.3);
	//Complex c2;
	//c2 = c1;
	//cout << c2.real << endl;
	//cout << c1 << endl;;
	//cout << c2 << endl;
	//Complex c4 = c1 + c3;
	//c4 = c1 + c3; 调用赋值
	//cout << c4;

	return 0;
}

