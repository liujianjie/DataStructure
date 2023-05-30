#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <functional>
#include "Token.h"
#include "TextQuerys.h"
using namespace std;

union Token0 {
	char cval;
	int ival;
	double dval;
};

union Token1 {
	string st1;
	int ival2;
};

/*
思想很重要：
管理需要拷贝控制的联合成员：
1.类内有匿名union，有一个enum判别式
2.用拷贝控制给union赋值，通过enum是否构造还是析构
3.比如，给token = 32，判断当前是否为string，是就析构，再给ival赋值32
4.比如，给token赋值string，判断当前是否为string，若不是就构造，若是就直接赋值
*/
int main()
{
	int a;
	//Token0 first_token = { 'a' };// cval
	//Token0 last_token;// 未初始化的
	//Token0 *pt = new Token0;//未初始化

	////last_token.ival = 12;
	//last_token.cval = 'z';
	////cout << last_token.ival << endl;
	//pt->ival = 42;

	////
	//union 
	//{
	//	char cval1;
	//	int ival1;
	////protected:
	//	double dval;
	//};
	//cval1 = 'c';
	//cout << cval1 << endl;

	//
	//Token1 tk1;
	//Token1 *tk2 = new Token1;
	//Token to;
	//to = 'z';
	//to = 32;
	////to = "nihao";
	//to.prints();

	//Token to2;
	//to2 = "asdfasd";
	//to = to2;
	//to.prints();

	cout << "-----练习----------" << endl;
	Token tk1,tk2;
	//tk1 = "12321321";
	//tk1 = tk1;
	//tk1.prints();
	tk1 = 23;
	tk1 = Sales_data("a-df-s12",1,1);
	tk1.prints();

	tk2 = Sales_data("12312-s12", 1, 1);
	tk1 = tk2;
	tk1.prints();

	a = 10;
	if (a > 6) {
		cout << "a > 6" << endl;
	}
	else if (a > 7) {
		cout << "a > 7" << endl;
	}
	else {
		cout << "a > 9" << endl;
	}

	/*
	练习：
	19.21:ok
	19.22:ok
	19.23:ok
	19.24:处理得好 不会发生问题 就是调用拷贝构造函数，两个都是同等的tok，自然自己赋给自己 是没问题的
	19.25：ok 可有可无
	*/
	cin >> a;
	return 0;
}
