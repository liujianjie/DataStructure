#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int* p = arr; // pָ��arr�׵�ַ
	int c = *(p++);// ����ִ��*pȡֵ����ִ��++��������ͬ*p++��
	cout << c << endl;// cΪ1
	cout << *p << endl;// *pΪ2

	return 0;
}