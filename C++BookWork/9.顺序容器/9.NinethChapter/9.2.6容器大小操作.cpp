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
	list<string> li1{"1","2","3" ,"4" };
	cout << li1.size() << " "<< li1.max_size() << " " << li1.empty() << endl;

	// 二 关系运算符
	vector<int> v1 = { 1,3,5,7,9,12 };
	vector<int> v2 = { 1,3,9 };
	vector<int> v3 = { 1,3,5,7 };
	vector<int> v4 = { 1,3,5,7,9,12 };
	cout << (v1 < v2) << endl;// true
	cout << (v1 < v3) << endl;//false
	cout << (v1 == v4) << endl;// true
	cout << (v1 == v2) << endl;// false

	vector<Sales_data> storeA, storeB;
	//cout << (storeA == storeB) << endl;// error
	//cout << (storeA < storeB) << endl;// error

	// 9.2.7练习
	vector<int> v5{1,2,3};
	vector<int> v6{ 1,2,3 };
	cout << (v5 == v6) << endl;
	list<int> v7{ 1,2,3 };
	//cout << (v5 < v7) << endl;// 不能需要是同一容器类型

	cin >> a;
	return 0;
}