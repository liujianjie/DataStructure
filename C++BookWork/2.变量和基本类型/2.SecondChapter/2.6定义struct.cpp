#include <iostream>
#include "TestStruct.h"//这里会把struct中声明的对象再声明一遍 所以不能声明，除非在本类中定义struct才可声明对象

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