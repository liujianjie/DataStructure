#include <iostream>
#include <string>
#include <vector>

using namespace std;

int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };
decltype(odd) *arrPtr(int i)
{
	return (i % 2) ? &odd : &even;
}
int main() 
{
	int getchar;
	// ��������ָ��

	// 1.���ͱ���
	typedef int arrT[10];	//��ʾ����10������������
	using arrT = int[10]; // �ȼ۵���������Ӱ�죬����
	arrT* func(int i);	// func����һ��ָ����10�������������ָ��

	// 2.����һ����������ָ��ĺ���,������ͨ�Ķ��壬�����ķ���ֵ ��������ָ��ĺ������岻һ��
	int arr[10];
	int *p1[10];
	int(*p2)[10] = &arr;

	// ����һ��һ���������ԣ������ض��壬����ά��һ��
	//int(*func(int i))[9];
	int(*func2(int i))[9];

	// 3.ʹ��β�÷�������
	auto func(int i) -> int(*)[10];

	// 4.ʹ��decltype�����֪������Ҫ���ص�ָ�뽫ָ���ĸ����飬�Ϳ���ʹ��decltype�ؼ��������������͡�
	//int arrs[5] = arrPtr(4);
	// ����һ��ָ�룬��ָ��ָ����5������������
	// ע�⣺decltype�����������������ת�������Ӧ��ָ�룬���ԣ�decltype���ص������飬��Ҫ��ʾ����ָ�뻹���ں�������ʱ���һ��*

	cin >> getchar;
	return 0;
}