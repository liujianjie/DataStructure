#include <iostream>
#include "TestStruct.h"//������struct�������Ķ���������һ�� ���Բ��������������ڱ����ж���struct�ſ���������

using namespace std;


int main() 
{
	int getchar;
	Sals_data sd12;
	sd12.bookNo = "Test Struct";
	//printf((s1.bookNo
	sd12.sold = 30;
	cout << sd12.sold << endl;
	cout << sd12.reven << endl;

	Sals_data sdss;
	sdss.bookNo = "Test ddd";
	sdss.reven = 3;

	cin >> getchar;
	return 0;
}