#include <iostream>
using namespace std;
class Parent {
public:
	 ~Parent() {
		cout << "~Parent()" << endl;
	}
};
class Child : public Parent {
public:
	// 写了virtual的话，delete p 会报错。。。不写virtual也能说明问题
	~Child() {
		cout << "~Child()" << endl;
	}
};
void main() {
	Parent* p = new Child;
	delete p; // 只会执行父类的析构函数
}