#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <cstdlib>
using namespace std;

class Test {
public:
	Test(int a, int b, int c) try :a(a), b(b), c(c) {

	}
	catch (const std::bad_alloc &e) {// 内存空间不足
		cout << "std::bad_alloc &e" << e.what() << endl;
	}
		int a;
	int b;
	int c;
};
int main()
{
	int a;
	
	/*
	练习：
	可做可不做 ok
	*/
	cin >> a;
	return 0;
}
