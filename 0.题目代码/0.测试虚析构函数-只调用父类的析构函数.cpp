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
	// д��virtual�Ļ���delete p �ᱨ��������дvirtualҲ��˵������
	~Child() {
		cout << "~Child()" << endl;
	}
};
void main() {
	Parent* p = new Child;
	delete p; // ֻ��ִ�и������������
}