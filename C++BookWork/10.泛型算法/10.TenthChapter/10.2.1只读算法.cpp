#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

int main()
{
	int a;
	vector<int> vec{1,2,3,4,5,6};
	cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;
	
	// 序列中元素的类型必须与第三个参数匹配，能够转换为第三个参数的类型
	vector<string> v1{ "123","456","abc","kjh" };
	string s1 = accumulate(v1.cbegin(), v1.cend(), string(""));
	cout << s1 << endl;
	// string("") 不能写成 "" 这个是字符串数组无运算符 或是const char* 无+运算符
	//string s2 = accumulate(v1.cbegin(), v1.cend(), "");

	vector<int> v2{1,2,3,4,5, 6};
	vector<int> v3{ 1,2,3,4,5,6, 9 };
	// v2.size() <= v3.size(); 必须 反过来不行
	cout << equal(v2.cbegin(), v2.cend(), v3.begin()) << endl;

	// 练习
	vector<int> v4{ 1,2,3,4,5,6,7 };
	cout << accumulate(v4.cbegin(), v4.cend(), 0) << endl;

	vector<double> v5{ 1.2,2.4,3.5 };
	cout << accumulate(v5.cbegin(), v5.cend(), 0) << endl;// 忽略了小数，转换为int，丢失数据
	cout << accumulate(v5.cbegin(), v5.cend(), 0.0f) << endl;// 忽略了小数，转换为int，丢失数据

	vector<const char*> v6{"123","456","789"};
	vector<const char*> v7{ "123","456","789" };
	cout << equal(v6.cbegin(), v6.cend(), v7.cbegin()) << endl;
	cin >> a;
	return 0;
}