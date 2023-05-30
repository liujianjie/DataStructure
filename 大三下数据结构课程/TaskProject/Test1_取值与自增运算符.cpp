#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int* p = arr; // p指向arr首地址
	int c = *(p++);// 是先执行*p取值后，再执行++操作，等同*p++。
	cout << c << endl;// c为1
	cout << *p << endl;// *p为2

	return 0;
}