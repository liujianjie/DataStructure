#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
using namespace std;
/*
1.�쳣��������Ĵ��벻��ִ�У��������Լ�����̬�ڴ棬delete���벻ִ�У�������ָ�뺯������ʱ���ǻ�ִ��
2.�ܶ��඼���������������������ʹ�õ���Դ�����������඼���������õĶ��壬�ر���Ϊc��c++����������Ƶ��࣬ͨ����Ҫ��ʽ���ͷ�
	���ǵ��þ���ķ������ͷ�
3.ʹ������ָ��������ͷ�һ���ڴ� ��Ҫ����һ������������delete�������ܹ���ɶ�shared_Ptr�б����ָ������ͷŵĲ���
4.����lambdaҲ�����ú����Զ���ɾ��
*/

void deletefunc(int *p) 
{
	cout << "start deletefunc" << endl;
	delete p;
}
int main()
{
	int a;
	int *p1 = new int(2);
	shared_ptr<int> sp1(p1, deletefunc);
	sp1.reset();

	// ��ϰ
	// 
	int *p2 = new int(3);
	shared_ptr<int> sp2(p2, [](int *p)->void { cout << "lambda" << endl; delete p; });
	sp2.reset();
	cout << *p2 << endl;

	cin >> a;
	return 0;
}
