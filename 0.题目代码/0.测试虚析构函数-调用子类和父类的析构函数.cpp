#include <iostream>
using namespace std;
class Parent {
public:
	virtual ~Parent() {
		cout << "~Parent()" << endl;
	}
};
class Child : public Parent {
public:
	virtual ~Child() {
		cout << "~Child()" << endl;
	}
};
void main() {
	Parent* p = new Child;
	delete p; // ִ���������Ǹ������������
}