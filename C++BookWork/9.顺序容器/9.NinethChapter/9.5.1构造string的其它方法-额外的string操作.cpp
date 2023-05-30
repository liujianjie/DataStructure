#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <array>
#include "Sales_data.h"
#include "noDefault.h"
#include <string>
using namespace std;
int main()
{
	int a;
	const char *cp = "Hello World!!";// 以空字符串为结束的数组
	char noNull[] = { 'H','i' };
	string s1(cp);// 直遇到空字符
	string s2(noNull, 2);// 拷贝2个字符
	string s3(noNull);//未定义没有空字符
	string s4(cp + 6, 5);//从cp[6]开始拷贝5个字符
	string s5(s1, 6, 5);// 从s1[6]开始拷贝5个字符
	string s6(s1, 6);// 从s1[6]开始拷贝直至末尾
	//string s7(s1, 16);// 开始下标不能大于length 异常 out_of_range

	string s8("hello world");
	string s9 = s8.substr(0, 5);
	string s10 = s8.substr(6);
	string s11 = s8.substr(6, 11);
	//string s12 = s8.substr(12);// 异常

	// 练习
	// 9.4.1
	vector<char> v1{'1','2','3' ,'4' ,'5' ,'6' ,'7','8','9' };
	string s12(v1.begin(), v1.end());
	cout << s12 << endl;

	cin >> a;
	return 0;
}