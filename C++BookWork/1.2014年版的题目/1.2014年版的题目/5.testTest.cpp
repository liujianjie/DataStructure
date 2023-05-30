#include <iostream>

using namespace std;

class T1 {
public:
	T1(int i) { cout << "T1()"<<(i) << endl; }

};
class T2 {
public:
	T2() { cout << "T2()" << endl; }
};
class T3:public T2{
	T1 t1;
	T1 t2;
	T1 t3;
	T1 t4;
public:
	T3() :t1(1),t4(4),t3(3),t2(2){ cout << "T3()" << endl; }
};
int main()
{
	int a;
	T3 t;
	
	cin >> a;
	return 0;
}