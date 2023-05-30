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
	// 一：迭代器范围
	// 二：左闭合
	vector<int>  tve1{1,2,3,4,5,6,7,8,9,10};
	cout << "请输入你要找到的数" << endl;
	int findval;
	cin >> findval;
	auto begin = tve1.begin();
	auto end = tve1.end();
	bool bln = false;
	/*while (begin != end) 
	{
		if (*begin == findval) {
			bln = true;
			break;
		}
		++begin;
	}
	if (bln) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}*/

	// 练习9.5
	while (begin != end)
	{
		if (*begin == findval) {
			cout << *begin << endl;
			break;
		}
		++begin;
	}
	// 练习9.6
	list<int> lst1;
	list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
	/*while (iter1 < iter2) { 应该改为！=
	
	}*/
	cin >> a;
	return 0;
}