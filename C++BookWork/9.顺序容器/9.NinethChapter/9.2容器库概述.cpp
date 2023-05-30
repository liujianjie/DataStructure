#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include "Sales_data.h"
#include "noDefault.h"

using namespace std;

int main() 
{
	int a;
	// 一：新建
	list<Sales_data> oli;
	deque<double> ode;

	vector<vector<string>> lines;

	// 二：限制
	vector<noDefault> tv1(10, 3);// 调用了定义的构造函数，隐式的
	//vector<noDefault> tv2(10);// false,因为这个类我没有定义默认构造函数
	cout << tv1[0].noas << endl;

	vector<int> tv11(10, 3);
	vector<int> tv3;
	vector<int> tv4(tv3);
	vector<int> tv5(tv11.begin(), tv11.end());
	vector<int> tv6{ 2,3,4,5 };

	tv3 = tv5;
	tv5 = { 4,5,6,8 };
	tv6.swap(tv5);
	swap(tv6, tv5);

	cout << tv6.size() << " ," << tv6.max_size() << " ," << tv6.empty() << endl;
	

	cin >> a;
	return 0;
}