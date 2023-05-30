#include <iostream>

using namespace std;

class Box7 {
public:
	int m;
	int* p = &m;
	static int n;
	static void Say() {
		cout << "Hello" << endl;
	}
};
int Box7::n = 3;
int main() {

	Box7 b7;
	//(*b7.p) = 3;
	cout << b7.m << endl;
	cout << (*b7.p) << endl;
	return 0;
}
//void Say() {
//	cout << "Hello." << endl;
//}