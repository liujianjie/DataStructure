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
	catch (const std::bad_alloc &e) {// �ڴ�ռ䲻��
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
	��ϰ��
	�����ɲ��� ok
	*/
	cin >> a;
	return 0;
}
